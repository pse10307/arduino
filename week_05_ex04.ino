/*
* IRremote: IRrecvDemo - demonstrates receiving IR codes with IRrecv
* An IR detector/demodulator must be connected to the input RECV_PIN.
* Version 0.1 July, 2009
* Copyright 2009 Ken Shirriff
* http://arcfn.com
*/
#include <IRremote.hpp>
#define DECODE_SAMSUNG
int IR_RECEIVE_PIN = 11;

void setup(){   
  Serial.begin(9600);
// In case the interrupt driver crashes on setup, give a clue
// to the user what's going on.
  Serial.println("Enabling IRin");
  IrReceiver.begin(IR_RECEIVE_PIN, DISABLE_LED_FEEDBACK);
  Serial.println("Enabled IRin");  
}
void loop() {
  uint16_t received;
  if (IrReceiver.decode()) {
  received = IrReceiver.decodedIRData.command;
  Serial.println(received, HEX); 
  //IrReceiver.printIRSendUsage(&Serial);
  IrReceiver.resume(); // Receive the next value
  }
}
