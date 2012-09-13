/*
Randomly rotated O
Jamie Yeo 27/08/2012
jamie.yeowl@gmail.com
*/

import processing.serial.*;  // Import Serial class library
Serial myPort;  // Create object from Serial class



float val1 = 0;
float val2 = 0;
float val3 = 0;

void setup() {
  size(400, 400);
  
  background(255);
  smooth();
  

  
    String portName = Serial.list()[0]; //the first port
   
  myPort = new Serial(this, portName, 9600);
  myPort.bufferUntil('\n'); // buffer incoming characters until line feed.
}

void serialEvent(Serial p){
  String s = "";        // string value received.
  String[] values;      // splitted string values.
  
  if(p.available() > 0){  // check number of characters in the serial buffer 
    s = p.readString();   // read string.
    if(s != null){ 
      println("received:"+s);
      
      values = s.split(",");     // separate values with ',' characters.
      println(values);           
      
      val1 = float(values[0]);
      val2 = float(values[1]);
      val3 = float(values[2]);
    }
  }
}


void draw() {
  translate(200, 200);
 noFill();
 stroke (0,10);

  
  for (int i=0; i<70; i++) {
    
    float r = val2;
   
      rotate(r);
      ellipse(50,80,i*1+50,80);
     
  



}
}


