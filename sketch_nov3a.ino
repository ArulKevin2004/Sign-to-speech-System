#include "SoftwareSerial.h"
#include "DFRobotDFPlayerMini.h"
DFRobotDFPlayerMini myDFPlayer;

void printDetail(uint8_t type, int value);

unsigned int f2;
unsigned int f3;
unsigned int f4;

SoftwareSerial mySoftwareSerial(9,10);

void setup()
{
 

  Serial.begin(9600);
  mySoftwareSerial.begin(9600);
  Serial.begin(115200);
  Serial.println();
  
  Serial.println(F("Initializing DFPlayer..."));

  if (!myDFPlayer.begin(mySoftwareSerial))
  {
    Serial.println(F("Unable to begin:"));
    Serial.println(F("1.Please recheck the connection!"));
    Serial.println(F("2.Please insert the SD card!"));
    while (true);
  }
  
  Serial.println(F("DFPlayer Mini online."));
  myDFPlayer.volume(27);// max-30 volume

}

void loop()
{
 
  f2 = analogRead(1);
  delay(100);
  f3 = analogRead(2);
  delay(100);
  f4 = analogRead(3);
  delay(100);
   
  Serial.print("A1=");
  Serial.println(f2);
  delay(100);
  
  Serial.print(" A2=");
  Serial.println(f3);
  delay(100);
      
  Serial.print(" A3=");
  Serial.println(f4);
  delay(100);

  if ((f2 < 50) && (f2 > 30))                      
  {
    Serial.print("Please Give Me Water");
    myDFPlayer.play(1);
    delay(2000);
  }
  else if ((f3 < 60) && (f3 > 40))  
  {
    Serial.print("Please Give Me Food");
    myDFPlayer.play(2);
    delay(2000);
  }
  else if ((f4 < 50) && (f4 > 30))  
  {
    Serial.print("CAN U HELP ME");
    myDFPlayer.play(3);
    delay(2000);
  }
 
  delay(50);
}