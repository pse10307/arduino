int pin=2;
void setup(){
  for (int i=2; i<=9; i++){
    pinMode(i,OUTPUT);

  digitalWrite(2,HIGH);
}
}
void loop()
{
  for(int i=0; i<8; i++){
    for(int j=0; j<8; j++){
      if (i==j)digitalWrite(pin+j, HIGH);
      else digitalWrite(pin+j, LOW);
    }
    delay(1000);
  }
}