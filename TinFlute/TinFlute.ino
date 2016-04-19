#define SPEAKER 12
#define MIC A0
#define LED 13
#define F1 2
#define F2 3
#define F3 4
#define F4 5
#define F5 6
#define F6 7

#define NOTE_D4 293.66
#define NOTE_E4 329.63
#define NOTE_F4 349.23
#define NOTE_G4 392.00
#define NOTE_A4 440.00
#define NOTE_B4 493.88  
#define NOTE_C5 523.25  


int bf1, bf2, bf3, bf4, bf5, bf6;
int micReading = 0;
int micMax = 0;
int micMin = 1023;
int threshold = 0;
int difference;

void setup() {
  // put your setup code here, to run once:
  pinMode(F1, INPUT_PULLUP);
  pinMode(F2, INPUT_PULLUP);
  pinMode(F3, INPUT_PULLUP);
  pinMode(F4, INPUT_PULLUP);
  pinMode(F5, INPUT_PULLUP);
  pinMode(F6, INPUT_PULLUP);
  pinMode(LED, OUTPUT);

  //Callibrate microphone
  digitalWrite(LED, HIGH);
  Serial.begin(9600);
  while(millis() < 3000){
    threshold = analogRead(MIC);
    if(threshold > micMax) micMax = threshold;
  }
  digitalWrite(LED, LOW);
  threshold = micMax;

}

void changeTone(float note)
{
  tone(SPEAKER, note);
}

void loop() {
  // put your main code here, to run repeatedly:
  bf1 = digitalRead(F1);
  bf2 = digitalRead(F2);
  bf3 = digitalRead(F3);
  bf4 = digitalRead(F4);
  bf5 = digitalRead(F5);
  bf6 = digitalRead(F6);

  micReading = analogRead(MIC);
  micMax = max(micMax, micReading);
  difference = 0;
  if(micReading >= threshold){
    difference = micReading - threshold;
    Serial.print(difference);
  }
  else{
    noTone(SPEAKER);
    return;
  }

  //Play notes. This is based on a simple tin whistle, like this: http://www.irish-folk-songs.com/uploads/4/3/3/6/43368469/2665650.gif?394
  if(!bf1 && !bf2 && !bf3 && !bf4 && !bf5 && !bf6) changeTone(NOTE_D4);
  if(!bf1 && !bf2 && !bf3 && !bf4 && !bf5 && bf6) changeTone(NOTE_E4);
  if(!bf1 && !bf2 && !bf3 && !bf4 && bf5 && bf6) changeTone(NOTE_F4);
  if(!bf1 && !bf2 && !bf3 && bf4 && bf5 && bf6) changeTone(NOTE_G4);
  if(!bf1 && !bf2 && bf3 && bf4 && bf5 && bf6) changeTone(NOTE_A4);
  if(!bf1 && bf2 && bf3 && bf4 && bf5 && bf6) changeTone(NOTE_B4);
  if(bf1 && bf2 && bf3 && bf4 && bf5 && bf6) changeTone(NOTE_C5);
  
  delay(2);

}
