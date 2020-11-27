//Från början 224 bytes

const int clkPin = 2;
const int DT = 4;
const int encoderButt = 3;

void setup() {
//Sets inputs
DDRD = ((0 << clkPin) | (0 << DT) | (0 << encoderButt)); // This pins are now inputs
PORTD = ((1 << clkPin) | (1 << DT) | (1 << encoderButt)); //Sets the pins internal pullup resistors

//External interupts
EIMSK = (1 << INT1) | (1 << INT0);//Enable external interupts 
EICRA = (1 << ISC11) | (1 << ISC01);//Sets that external interupts trigger on falling edge
sei(); //Enable global interupts 

Serial.begin(9600);
}

void loop() {
  Serial.print("\n");
  delay(1000);
}
