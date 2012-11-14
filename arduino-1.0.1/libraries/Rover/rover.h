/*******************************************************************************
* @Title: rover.h 
*
* @Author: Phil Smith 
*
* @Date: 19-Oct-2012	10:29 PM
*
* @Project: Ardurover
*
* @Purpose: 
*
* @Modification History: 
*
*******************************************************************************/
#ifndef __ROVER_H__
#define __ROVER_H__

#include "../Ping/ping.h"
#include "../Motor/motor.h"

#define FORWARD  true
#define BACKWARD false
#define LEFT     0
#define RIGHT    1

#define SLOW      125
#define FAST     255

using namespace ping;
using namespace motor;


class Rover{
   public:
      Rover();
      void drive( const short direction );
      void turn( const short direction );
      void stop();
      void selfTest();

      long checkDistance( const bool direction, const short uom );
     
      short  getSpeed();
      void setSpeed( short speed );

      bool getDirection();
      void setDirection( bool direction );
      PingSensor* forwardSensor;
      PingSensor* aftSensor;


   private:
      /* Vehicle speed setting (not measured speed) */
      short _speed;

      /* Vehicle's primary direction */
      bool _direction; 

      /* Vehicle's two drive motors. The model vehicle
       * has two parallel drive motors. */
      Motor _motA;
      Motor _motB;

      /* Vehicle's distance sensors. */
      PingSensor _distSensor1;
      PingSensor _distSensor2;
      
      Motor* leftMotor;
      Motor* rightMotor;
};
#endif /* __ROVER_H__ */
