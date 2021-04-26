////////////////////////////////// LIBRARIES //////////////////////////////////
//-- Import Serial communication libraries
import processing.serial.*;
import processing.opengl.*;
//-- Import [ToxicLibs]
//--   Sketch -> Importer une librairie -> Ajouter une librairie
//--     Search and install [ToxicLibs] by Karsten Schmidt
import toxi.geom.*;
import toxi.processing.*;

/////////////////////////////// OBJECT CREATION ///////////////////////////////
ToxiclibsSupport gfx;

////////////////////////////////// VARIABLES //////////////////////////////////
Serial arduino;

String serial_angle;
String serial_distance;
String serial_data;

float object_distance;

int radar_angle;
int radar_distance;
int index = 0;

/////////////////////////////////// METHODS ///////////////////////////////////

/*---------------------------------------------------------------------------*/
void draw() 
{
  //fill(10,255,10);
  noStroke();
  fill(0, 4);
  //-- The radar takes the window resolution
  rect(0, 0, 1280, 720);
  fill(10, 255, 10);  //-- Green color
  
  //-- Radar arcs
  pushMatrix();
  
  translate(640, 666);
  noFill();
  strokeWeight(2);
  stroke(0, 255, 0);  //-- Lime color
  
  arc(0, 0, 1200, 1200, PI, TWO_PI);
  arc(0, 0, 934, 934, PI, TWO_PI);
  arc(0, 0, 666, 666, PI, TWO_PI);
  arc(0, 0, 400, 400, PI, TWO_PI);
  
  //-- Radar lines
  strokeWeight(4);
  
  line(-640, 0, 640, 0);
  line(0, 0, -554, -320);
  line(0, 0, -320, -554);
  line(0, 0, 0, -640);
  line(0, 0, 320, -554);
  line(0, 0, 554, -320);
  
  popMatrix();
 
  //-- Ultrasonic line
  pushMatrix();
  
  strokeWeight(5);
  stroke(255, 255, 0);  //-- Yellow color
  translate(640, 666);
  line(0, 0, 640 * cos(radians(radar_angle)),
    -640 * sin(radians(radar_angle)));
  
  popMatrix();

  //Object detection line
  pushMatrix();
  
  translate(640, 666);
  strokeWeight(5);
  stroke(255, 0, 255); //-- Magenta color
  
  object_distance = (radar_distance * 15);

  if(radar_distance<40)
  {
    line(object_distance * cos(radians(radar_angle)),
      -object_distance * sin(radians(radar_angle)),
        633 * cos(radians(radar_angle)),
          -633 * sin(radians(radar_angle)));
  }
  
  popMatrix();
}
void setup() 
{
  size(1280, 720);  //-- Radar window resolution
  gfx = new ToxiclibsSupport(this);
  smooth();
  
  String arduino_port_name = "/dev/ttyACM0";
  arduino = new Serial(this, arduino_port_name, 9600);
  
  //-- Reads the data from the serial port up to the [#] character,
  //-- it will read : angle, distance
  arduino.bufferUntil('#');
}
/*---------------------------------------------------------------------------*/
//-- MUST BE WRITE LIKE THIS [serialEvent]
//-- [setup] & [serialEvent] are the same as [setup] & [loop] for Arduino
void serialEvent (Serial arduino) 
{
  serial_data = arduino.readStringUntil('#');
  serial_data = serial_data.substring(0, (serial_data.length() - 1));
  
  index = serial_data.indexOf("*");
  
  serial_angle= serial_data.substring(0, index);
  serial_distance= serial_data.substring((index + 1), serial_data.length());
  
  //-- Convert angle & distance STRING to INT
  radar_angle = int(serial_angle);
  radar_distance = int(serial_distance);
}
