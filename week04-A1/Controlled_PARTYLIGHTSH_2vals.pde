/*
Controlled with analog sensors
Jamie Yeo 13/09/2012
jamie.yeowl@gmail.com
*/
import processing.serial.*;  // Import Serial class library
Serial myPort;  // Create object from Serial class



float val1 = 0;
float val2 = 0;
float val3 = 0;

void setup() 
{
  size(400, 400);
 
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

background (30);
noStroke();

for (int i = 0; i < 5; i = i + 1){
  for (int j= 0; j <30; j = j+1){
    for (int k= 0; k <23; k = k+1){
   if(((i+j+k) % 2) == 0 ){
     fill(val2,80,158);
   }else{
     fill(155,val2,133);
   }
    
    ellipse(i * 10 + 50, j * 10 + 50, val3, val3);
    ellipse(i * 10 + 300, j * 10 + 50, val3,val3);
    
    ellipse(k * 10 + 80, i * 10 + 180, val3,val3);
  }}}
  
}
