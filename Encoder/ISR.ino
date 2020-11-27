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
