/*
Adafruit Arduino - Lesson 10. Simple Sounds
*/
 
int speakerPin = 12;
 
int numTones = 10;
//int tones[] = {261, 277, 294, 311, 330, 349, 370, 392, 415, 440};
//            mid C  C#   D    D#   E    F    F#   G    G#   A
int tones[] = {494, 247};
float beats[] = {0.5, 1};
int tones2[] = {494, 247, 494};
float beats2[] = {0.5, 0.7, 0.5};

int ledPin = 4;
 
void setup()
{
  //pinMode(ledPin, OUTPUT);
  for (int i = 0; i < 2; i++)
  {
    tone(speakerPin, tones[i]);
    delay(500*beats[i]);
  }
  noTone(speakerPin);
  delay(300);
    for (int i = 0; i < 3; i++)
  {
    tone(speakerPin, tones2[i]);
    delay(500*beats2[i]);
  }
  noTone(speakerPin);
}
 
void loop()
{
    //digitalWrite(ledPin, HIGH);   // turn the LED on (HIGH is the voltage level)
  //delay(1000);              // wait for a second
  //digitalWrite(ledPin, LOW);    // turn the LED off by making the voltage LOW
  //delay(1000);  
}
