const int cheek1 = 5; //Red LED for the cheek
const int cheek2 = 6; //Red LED for the other cheek
const int flash1 = 3; //Yellow LED for "flash" move
const int flash2 = 9; //Other yellow LED for the "flash" move
const int fsr = A0; //FSR in the forehead
const int light = A1; //Light sensor

int fsrValue = 0; //Value read from the FSR
int cheekValue = 0; //Output to the cheeks
int lightValue = 0; //Light sensor reading
int flashValue = 0; //Output to "flash" LEDs

const int debug = 1;

void setup() {
  Serial.begin(9600);
}

void loop() {
  //read the pressure on the FSR
  fsrValue = analogRead(fsr);
  lightValue = analogRead(light);

  cheekValue = map(fsrValue, 0, 1023, 0, 255);
  if(lightValue < 500) flashValue = map(1023-lightValue, 0, 1023, 0, 255);
  else flashValue = 0;

  analogWrite(cheek1, cheekValue);
  analogWrite(cheek2, cheekValue);
  analogWrite(flash1, flashValue);
  analogWrite(flash2, flashValue);

  if(debug){
    Serial.print("FSR sensor = ");
    Serial.print(fsrValue);
    Serial.print("\t cheek output = ");
    Serial.println(cheekValue);
    Serial.print("Light sensor = ");
    Serial.print(lightValue);
    Serial.print("\t flash output = ");
    Serial.println(flashValue);
  }
  
  delay(2);
}
