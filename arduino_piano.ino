// Import the CapacitiveSensor Library.
#include <CapacitiveSensor.h>

#define speaker A5


// Set the Send Pin & Receive Pin.
CapacitiveSensor   a = CapacitiveSensor(13,12);        
CapacitiveSensor   b = CapacitiveSensor(11,10);         
CapacitiveSensor   c = CapacitiveSensor(9,8);     
CapacitiveSensor   d = CapacitiveSensor(7,6);     
CapacitiveSensor   e = CapacitiveSensor(5,4);      
CapacitiveSensor   f = CapacitiveSensor(3,2);         
CapacitiveSensor   g = CapacitiveSensor(A0,A1);  
CapacitiveSensor   h = CapacitiveSensor(A2,A3);     


void setup()                    
{
  d.set_CS_AutocaL_Millis(0xFFFFFFFF);     // turn off autocalibrate on channel 1 
  
  // Arduino start communicate with computer.
  Serial.begin(9600);
}

void loop()                    
{
  // Set a timer.
  long start = millis();
  
  // Set the sensitivity of the sensors.
  long press_a =  a.capacitiveSensor(3000);
  long press_b =  b.capacitiveSensor(3000);
  long press_c =  c.capacitiveSensor(3000);
  long press_d =  d.capacitiveSensor(3000);
  long press_e =  e.capacitiveSensor(3000);
  long press_f =  f.capacitiveSensor(3000);
  long press_g =  g.capacitiveSensor(3000);
  long press_h =  h.capacitiveSensor(3000);
  


  Serial.print(millis() - start);        // check on performance in milliseconds
  Serial.print("\t");                    

  Serial.print(press_a);                  // print sensor output 1
  Serial.print("\t");                     // Leave some space before print the next output
  Serial.print(press_b);                  // print sensor output 2
  Serial.print("\t");                     // Leave some space before print the next output
  Serial.print(press_c);                  // print sensor output 3
  Serial.print("\t");                     // Leave some space before print the next output
  Serial.print(press_d);                  // print sensor output 4
  Serial.print("\t");                     // Leave some space before print the next output
  Serial.print(press_e);                  // print sensor output 5
  Serial.print("\t");                     // Leave some space before print the next output
  Serial.print(press_f);                  // print sensor output 6
  Serial.print("\t");                     // Leave some space before print the next output
  Serial.print(press_g);                  // print sensor output 7
  Serial.print("\t");                     // Leave some space before print the next output
  Serial.println(press_h);                 // print sensor output 8  
  
  // When sensor is touched, the speaker will produce a tone.
  if (press_h > 500) tone(A5, 262, 100);   // frequency
  if (press_g > 500) tone(A5, 294, 100);   
  if (press_f > 500) tone(A5, 330, 100);
  if (press_e > 500) tone(A5, 349, 100);
  if (press_d > 500) tone(A5, 392, 100);
  if (press_c > 500) tone(A5, 440, 100);
  if (press_b > 500) tone(A5, 494, 100);
  if (press_a > 500) tone(A5, 523, 100);
  
  // When hand didn't touch on it, no tone is produced.
  if (press_a<=500  &  press_b<=500  &  press_c<=500 & press_d<=500  &  press_e<=500  &  press_f<=500 &  press_g<=500 &  press_h<=500)
    noTone(speaker);

  delay(10);                             // arbitrary delay to limit data to serial port 
}
