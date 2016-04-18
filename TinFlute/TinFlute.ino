#define SPEAKER 12
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

void setup() {
  // put your setup code here, to run once:
  pinMode(F1, INPUT_PULLUP);
  pinMode(F2, INPUT_PULLUP);
  pinMode(F3, INPUT_PULLUP);
  pinMode(F4, INPUT_PULLUP);
  pinMode(F5, INPUT_PULLUP);
  pinMode(F6, INPUT_PULLUP);

}

void changeTone(float note)
{
  //noTone(SPEAKER);
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

  if(!bf1 && !bf2 && !bf3 && !bf4 && !bf5 && !bf6) changeTone(NOTE_D4);
  else if(!bf1 && !bf2 && !bf3 && !bf4 && !bf5) changeTone(NOTE_E4);
  else if(!bf1 && !bf2 && !bf3 && !bf4) changeTone(NOTE_F4);
  else if(!bf1 && !bf2 && !bf3) changeTone(NOTE_G4);
  else if(!bf1 && !bf2) changeTone(NOTE_A4);
  else if(!bf1) changeTone(NOTE_B4);
  else changeTone(NOTE_C5);

  delay(2);

}
