#include <IRremote.h> // include IR remote library
#include <Servo.h>    // include Servo control library


int RECV_PIN = 11; //IR receiver attached to Pin11
int LEDpin = 2; //LED to be attached to Pin3
int SERVO_PIN = 3; //Servo to be attached to Pin3

Servo myservo; // declare servo

IRrecv irrecv(RECV_PIN);  //setup IRreceiver only Pin11 works.
decode_results results;   //devoder for received IR signal.

void setup()
{
  Serial.begin(9600);
  irrecv.enableIRIn(); // Start the receiver  

  myservo.attach(SERVO_PIN); // attach serto to SERVO_PIN
pinMode(LEDpin, OUTPUT);
}

void loop() {
  
  if (irrecv.decode(&results)) { // decode IR signal
    int angle = results.value;   // received value
    Serial.println(results.value, DEC);
   
    if(results.value == 3778927144)//remote button 1
  {
    digitalWrite(LEDpin, HIGH);
  }
  else if (results.value == 2908251746)//remote button 2
  {
    digitalWrite(LEDpin, LOW);
  }
  else if (results.value == 657459652) //remote button 3
  {
    digitalWrite(LEDpin, HIGH);
    delay(500);               
    digitalWrite(LEDpin, LOW);
    delay(500);               
    digitalWrite(LEDpin, HIGH);
  }
  else if (results.value == 4120482440) //remote button 4
  {
    digitalWrite(LEDpin, HIGH);
    delay(500); 
   digitalWrite(LEDpin,LOW);
  
  }
   else if (results.value == 1931099650) //remote button 5
  {
    myservo.write(180);
  }
  else if (results.value == 742730860) //remote button 6
  {
    myservo.write(90);
  }
  
    irrecv.resume(); // Receive the next value
  } 
  
}
