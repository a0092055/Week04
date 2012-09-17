#include <IRremote.h> // include IR remote library


int RECV_PIN = 11; //IR receiver attached to Pin11
int LEDpin = 3; //LED to be attached to Pin3
int y;

IRrecv irrecv(RECV_PIN);  //setup IRreceiver only Pin11 works.
decode_results results;   //devoder for received IR signal.

void setup()
{
  Serial.begin(9600);
  irrecv.enableIRIn(); // Start the receiver  

 
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
  


    irrecv.resume(); // Receive the next value
  } 
  
}
