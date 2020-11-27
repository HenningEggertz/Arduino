//Hej på dig
const int clkPin = 2;
const int DT = 4;
const int encoderButt = 3;

void setup() {
pinMode(clkPin, INPUT_PULLUP);
pinMode(DT, INPUT_PULLUP);
pinMode(encoderButt, INPUT_PULLUP);
attachInterrupt(0, encoder, FALLING);
attachInterrupt(1, encoderButton, FALLING);

Serial.begin(9600);
}

void loop() {
  Serial.print("\n");
  delay(1000);
}

void encoder(){
  if(digitalRead(DT) == LOW){
    Serial.println("Clockvise");
  }
  else{
    Serial.println("Anticlockvise");
  }
}

void encoderButton(){
  Serial.println("Clickde");
}
