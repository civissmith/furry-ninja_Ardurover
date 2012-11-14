/*******************************************************************************
* @Title: motor.cpp 
*
* @Author: Phil Smith 
*
* @Date: 20-Oct-2012	09:01 AM
*
* @Project: 
*
* @Purpose: 
*
* @Modification History: 
*
*******************************************************************************/
#include "motor.h"

namespace motor{

   void Motor::setChannel( int chan ){
   /* Setting a channel fixes the brake pin and direction pin
    * because they are defined by hardware. */      
       _channel = chan;
       if( _channel == CHAN_A ){
          _brakePin = PIN_BRAKEA;
          _dirPin   = PIN_DIRA; 
          return;
       }else{
          _brakePin = PIN_BRAKEB;
          _dirPin   = PIN_DIRB;
       }

       pinMode( _brakePin, OUTPUT );
       pinMode( _dirPin, OUTPUT );
   }
   
   int Motor::getChannel(){
       return _channel;
   }
   
   void Motor::activateBrake(){
   
       _brakeIsActive = true;
       digitalWrite(_brakePin, HIGH);  
       
   }
   
   
/* Motor needs to be abstracted to either a Forward or Reverse call */
   void Motor::drive( short direction, short speed ){
       _brakeIsActive = false;
   
       if( direction )
         digitalWrite(_dirPin, HIGH); 
       else
         digitalWrite(_dirPin, LOW); 
   
       digitalWrite(_brakePin, LOW);
       analogWrite(_channel, speed);
      
   }

};

