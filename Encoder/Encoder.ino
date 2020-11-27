//Från början 224 bytes

const int clkPin = 2;
const int DT = 4;
const int encoderButt = 3;

void setup() {
DDRD = ((0 << clkPin) | (0 << DT) | (0 << encoderButt)); // This pins are now inputs
PORTD = ((1 << clkPin) | (1 << DT) | (1 << encoderButt)); //Sets the pins internal pullup resistors



//attachInterrupt(0, encoder, FALLING);

EIMSK = (1 << INT1) | (1 << INT0);
EICRA = (1 << ISC11) | (1 << ISC01);
sei();

Serial.begin(9600);
}

void loop() {
  Serial.print("\n");
  delay(1000);
}

ISR(INT0_vect){
  if(digitalRead(DT) == LOW){
    Serial.println("Clockvise");
  }
  else{
    Serial.println("Anticlockvise");
  }
}

ISR(INT1_vect){
  Serial.println("Clickde");
}
