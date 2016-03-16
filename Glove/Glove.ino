
const int xPin = A0;
const int yPin = A1;
const int zPin = A2;
const int speakerPin = 3;
const int minAcc = 0;
const int maxAcc = 10;
const int minFreq = 261;
const int maxFreq = 523;
int xInit;
int yInit;
int zInit;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  xInit = analogRead(xPin);
  yInit = analogRead(yPin);
  Serial.println(yInit);
  zInit = analogRead(zPin);
}

void loop() {
  // put your main code here, to run repeatedly:

  int x = analogRead(xPin) - xInit;
  int y = analogRead(yPin) - yInit;
  int z = analogRead(zPin) - zInit;
  
  y = sqrt(x*x + y*y + z*z);
  
  if(y < minAcc) y = minAcc;
  else if(y > maxAcc) y = maxAcc;
  int sound = map(y, minAcc, maxAcc, minFreq, maxFreq);
  //Serial.println("y: %d, sound: %d", y, sound);
  //Serial.println(sound);
  tone(3, sound);
  delay(100);
}
