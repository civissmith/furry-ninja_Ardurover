/*******************************************************************************
* @Title: rover.cpp 
*
* @Author: Phil Smith 
*
* @Date: 19-Oct-2012	10:29 PM
*
* @Project: Ardurover
*
* @Purpose: Encapsulate the rover platform
*
* @Modification History: 
* PROJECT TERMINATED
*
*******************************************************************************/
#include <rover.h>
#define TURNSEC  2000
#define DRIVESEC 500

Rover::Rover(){
   _speed     = SLOW;
   _direction = FORWARD;

   forwardSensor = &_distSensor1;
   aftSensor     = &_distSensor2; 

   _motA.setChannel( CHAN_A );
   _motB.setChannel( CHAN_B );
   
   /* Associate the motors */
   setDirection( FORWARD );
   leftMotor  = &_motA;      
   rightMotor = &_motB;      
   
   leftMotor->activateBrake();
   rightMotor->activateBrake();

}

void Rover::selfTest(){
}



/* drive() - causes the vehicle to drive in the current direction */
void Rover::drive( const short direction ){
    
    if( direction == FORWARD ){
       setDirection( FORWARD ); 
       rightMotor->drive( FORWARD, getSpeed() );
       leftMotor->drive( BACKWARD, getSpeed() );
       delay( DRIVESEC );
    }else{
       setDirection( BACKWARD ); 
/*$*/  rightMotor->drive( BACKWARD, getSpeed() );
       leftMotor->drive( FORWARD, getSpeed() );
    }
}

/* turn() - causes the vehicle to turn to the desired direction.
 *          by default, turns are SLOW. Vehicle will be in the
 *          stopped state after a turn. */
void Rover::turn( const short direction ){

    /* Stop the vehicle before attempting to turn */
    stop();
    

    /* To turn the vehicle the desired direction, the opposite motor must be
     * driven. (Driving the LEFT motor will cause the vehicle to turn RIGHT. */
    if( direction == LEFT ){
       rightMotor->drive( FORWARD, SLOW );
       delay( TURNSEC );  /* Give the motor time to turn the vehicle */
    }else{
       leftMotor->drive( FORWARD, SLOW );
       delay( TURNSEC );
    }

    /* Stop the vehicle after attempting to turn */
    stop();
}

/* stop() - applies both motor brakes */
void Rover::stop(){
   leftMotor->activateBrake();
   rightMotor->activateBrake();
}

/* checkDistance() - calls the getDistance for the
 * appropriate sensor. */
long Rover::checkDistance( const bool direction, const short uom ){

   if( direction == FORWARD ){
     return forwardSensor->getDistance( uom );
   }
   return aftSensor->getDistance( uom );
}
     
/* getSpeed() - returns the current speed setting */
short  Rover::getSpeed(){
   return _speed;
}

/* setSpeed() - sets the desired speed setting */
void Rover::setSpeed( short speed ){
   _speed = speed;
}

/* getDirection() - returns the current drive direction */
bool Rover::getDirection(){
   return _direction;
}

/* setDirection() - sets the desired drive direction */
void Rover::setDirection( bool direction ){
   _direction = direction;
}


