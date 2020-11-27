//Från början 224 bytes

const int clkPin = 2;
const int DT = 4;
const int encoderButt = 3;

void setup() {
DDRD = ((0 << clkPin) | (0 << DT) | (0 << encoderButt)); // This pins are now inputs
PORTD = ((1 << clkPin) | (1 << DT) | (1 << encoderButt)); //Sets the pins internal pullup resistors

GIMSK = (1 << PCIE);
sei();

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
