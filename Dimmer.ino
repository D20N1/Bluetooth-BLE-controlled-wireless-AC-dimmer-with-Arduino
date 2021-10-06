#include <RBDdimmer.h>
#include <SoftwareSerial.h>


SoftwareSerial mySerial(11,10);
//#define mySerial  Serial


dimmerLamp dimmer(5); //initialase port for dimmer
String msg; 
void setup()
  {
    mySerial.begin(9600); 
    //USE_SERIAL.begin(19200);
    dimmer.begin(NORMAL_MODE, OFF); //dimmer initialisation: name.begin(MODE, STATE)
    delay(50);
    dimmer.setPower(90);
    delay(50);
    dimmer.setState(ON);
  }


void loop()
{    
  
  if (mySerial.available())
  {    
      msg = mySerial.readString();
      int buf = msg.toInt();


      if (buf >9 && buf<=90)
      {        
                
        if (dimmer.getState()==0)
        {
          dimmer.setPower(buf);
          delay(50);
          dimmer.begin(NORMAL_MODE, ON);
        }else
        {
          dimmer.setPower(buf);         
        }
       
      }else if (buf <10 && buf>=0)
      { 
        if (dimmer.getState()==1)
        {
          dimmer.setState(OFF);
        }
     }
  }
}
