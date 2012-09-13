/*
'A simple O'
Jamie Yeo 27/08/2012
jamie.yeowl@gmail.com
*/
import processing.serial.*;  // Import Serial class library
Serial myPort;  // Create object from Serial class



float val1 = 0;
float val2 = 0;
float val3 = 0;


void setup() 
{
size(400,400);
String portName = Serial.list()[0]; //the first port
   
  myPort = new Serial(this, portName, 9600);
  myPort.bufferUntil('\n'); // buffer incoming characters until line feed.
}

//serialEvent function is called when incoming character reaches '\n'
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




void draw()
{
background(15);
noFill();

for(int i = 1; i < 20; i = i + 1){
  stroke(val2,i*val2+150,i*10+60);
ellipse(200,200,i*val3+10,i*val1+20);

}
}
