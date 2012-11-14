/*******************************************************************************
* @Title: motor.h 
*
* @Author: Phil Smith 
*
* @Date: 20-Oct-2012	09:01 AM
*
* @Project: Ardurover V.1
*
* @Purpose: Encapsulate Motor Shield
*
* @Modification History: 
* PROJECT TERMINATED
*
*******************************************************************************/
#ifndef __MOTOR_H__
#define __MOTOR_H__

#include <Arduino.h>
#define CHAN_A 3
#define CHAN_B 11
#define CLOCK  1
#define CCLOCK 0


/* These pin assignments are defined by the Arduino Motorshield
 * hardware. */
#define PIN_BRAKEA  9
#define PIN_BRAKEB  8
#define PIN_DIRA   12
#define PIN_DIRB   13

namespace motor{
   class Motor{
      public:
         void setChannel( int chan );
      
         void activateBrake();
   
         int getChannel();
   
         void drive( short direction, short speed );

   
      private:
         int _brakePin; // Pin that controls the motor brake
         int _dirPin;   // Pin that controls the motor direction
         int _channel;
         bool _brakeIsActive;
   };
};
#endif
