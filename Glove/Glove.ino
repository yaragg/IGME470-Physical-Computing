#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif

const int xPin = A0;
const int yPin = A1;
const int zPin = A2;
const int speakerPin = 10;
const int lightPin = 11;
const int minAcc = 0;
const int maxAcc = 10;
const int minFreq = 261;
const int maxFreq = 523;
int xInit;
int yInit;
int zInit;

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(3, lightPin, NEO_GRB + NEO_KHZ800);

void setup() {
  xInit = analogRead(xPin);
  yInit = analogRead(yPin);
  zInit = analogRead(zPin);
  pixels.begin();
}

void loop() {
  int x = analogRead(xPin) - xInit;
  int y = analogRead(yPin) - yInit;
  int z = analogRead(zPin) - zInit;
  y = -y;
  
  //y = sqrt(x*x + y*y + z*z);
  
  if(y < minAcc) y = minAcc;
  else if(y > maxAcc) y = maxAcc;
  int sound = map(y, minAcc, maxAcc, minFreq, maxFreq);
  tone(speakerPin, sound);

  for(int i=0; i<3; i++)
  {
    pixels.setPixelColor(i, pixels.Color(map(x, minAcc, maxAcc, 0, 255), map(y, minAcc, maxAcc, 0, 255), map(z, minAcc, maxAcc, 0, 255)));
  }
  pixels.show();
  delay(100);
}
