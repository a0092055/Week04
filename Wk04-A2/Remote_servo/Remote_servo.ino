/*
 * IRremote: IRrecvDemo - demonstrates receiving IR codes with IRrecv
 * An IR detector/demodulator must be connected to the input RECV_PIN.
 * Version 0.1 July, 2009
 * Copyright 2009 Ken Shirriff
 * http://arcfn.com
 */

#include <IRremote.h> // include IR remote library
#include <Servo.h>    // include Servo control library


Servo myservo; // declare servo

int RECV_PIN = 11; //IR receiver should be attached to Pin11
int SERVO_PIN = 3; //Servo to be attached to Pin3

IRrecv irrecv(RECV_PIN);  //setup IRreceiver only Pin11 works.
decode_results results;   //devoder for received IR signal.

void setup()
{
  Serial.begin(9600);
  irrecv.enableIRIn(); // Start the receiver  

  myservo.attach(SERVO_PIN); // attach serto to SERVO_PIN

}

void loop() {
  
  if (irrecv.decode(&results)) { // decode IR signal
    int angle = results.value;   // received value
    Serial.println(results.value, DEC);
    
    if(results.value == 3778927144)
  {
    myservo.write(50);
  }
  else if (results.value == 2908251746)
  {
    myservo.write(108);
  }
  else if (results.value == 657459652)
  {
    myservo.write(180);
  }
    irrecv.resume(); // Receive the next value
  } 
  
}
