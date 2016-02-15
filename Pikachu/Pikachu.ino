const int cheek1 = 5; //Red LED for the cheek
const int cheek2 = 6; //Red LED for the other cheek
const int fsr = A0; //FSR in the forehead
int speakerPin = 12; //pin for the buzzer

int fsrValue = 0; //Value read from the FSR
int cheekValue = 0; //Output to the cheeks

//Notes and beats for the two cries
int tones[] = {494, 247};
//float beats[] = {0.5, 1};
float beats[] = {0.5, 1.5};
int tones2[] = {494, 247, 494};
float beats2[] = {0.5, 0.7, 0.5};

unsigned long previousSound = 0;
const long soundInterval = 2000;
const long duration1 = 800;
const long duration2 = 900;
bool playing = false;

const int debug = 1;

void setup() {
  Serial.begin(9600);
}

void loop() {
  //read the pressure on the FSR
  fsrValue = analogRead(fsr);

  cheekValue = map(fsrValue, 0, 1023, 0, 255);

  analogWrite(cheek1, cheekValue);
  analogWrite(cheek2, cheekValue);

  unsigned long current = millis();
  if(playing || fsrValue > 20 && current - previousSound >= soundInterval){
    previousSound = current;
    for(int i=0; i<2; i++){
      if(current < previousSound + (unsigned long)beats[i]*500){
        if(!playing){
          tone(speakerPin, tones[i]);  
          playing = true;
        }
      }
      else playing = false;   
    }
  }
  else if(!playing) noTone(speakerPin);

  previousSound = current;

  if(debug){
    Serial.print("FSR sensor = ");
    Serial.print(fsrValue);
    Serial.print("\t cheek output = ");
    Serial.println(cheekValue);
  }

  delay(2);

}
