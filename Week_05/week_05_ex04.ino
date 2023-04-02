/*
* IRremote: IRrecvDemo - demonstrates receiving IR codes with IRrecv
* An IR detector/demodulator must be connected to the input RECV_PIN.
* Version 0.1 July, 2009
* Copyright 2009 Ken Shirriff
* http://arcfn.com
*/
#include <IRremote.h>
int IR_RECEIVE_PIN = 11;
void setup()
{   
Serial.begin(9600);
IrReceiver.begin(IR_RECEIVE_PIN, ENABLE_LED_FEEDBACK); 
pinMode(5, OUTPUT);
// In case the interrupt driver crashes on setup, give a clue
// to the user what's going on.
Serial.println("Enabling IRin");
IrReceiver.enableIRIn(); // Start the receiver
Serial.println("Enabled IRin");  }
void loop() {
  if (IrReceiver.decode()) {
  Serial.println(IrReceiver.decodedIRData.decodedRawData,HEX); 
  IrReceiver.resume(); // Receive the next value
  if (IrReceiver.decodedIRData.decodedRawData == 0xF30CFF00) digitalWrite(5, HIGH);  //1번 LED 켜기
  if (IrReceiver.decodedIRData.decodedRawData == 0xE718FF00) digitalWrite(5, LOW);  // 2번 LED 끄기

}
}

// 1: F30CFF00, 2: E718FF00
