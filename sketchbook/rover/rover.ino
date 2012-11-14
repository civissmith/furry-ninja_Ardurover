/*******************************************************************************
* @Title: rover.ino 
*
* @Author: Phil Smith 
*
* @Date: 20-Oct-2012	08:38 AM
*
* @Project: 
*
* @Purpose: 
*
* @Modification History: 
*
*******************************************************************************/
#include <rover.h>
#include <ping.h>
#include <motor.h>

#define MINDIST    5  /* Inches */
#define SLOWDIST  12  /* Inches */
#define MAXTRIES   5  /* When tries expire, direction changes */

void checkClearance();

Rover r1;
int numTries;
bool driveDir;
short turnDir;

void setup(){
  
   r1.stop();
   r1.checkDistance( FORWARD, INCHES );
   r1.setSpeed( SLOW );

   r1.forwardSensor->assignSigPin(2);
   r1.aftSensor->assignSigPin(4);

   numTries = MAXTRIES;
   driveDir = FORWARD;
   turnDir  = RIGHT;

   Serial.begin(9600);

}

void loop(){


   if( numTries % 2 )
      turnDir = LEFT;
   else
      turnDir = RIGHT;

   checkClearance();
   r1.drive( driveDir );
   
   delay(1000);
   
}

void checkClearance(){

   volatile long distance;

   Serial.println();
   Serial.println();

   if( r1.getDirection() == FORWARD )
      distance = r1.checkDistance( FORWARD, INCHES );
   else
      distance = r1.checkDistance( BACKWARD, INCHES );
 
   Serial.print("Distance = ");
   Serial.print( distance );
   Serial.println(" in.");


   if( r1.getDirection() == FORWARD )
      Serial.println("Direction is FORWARD");
   else
      Serial.println("Direction is BACKWARD");

   /* Make sure we're not too close */
   if( distance <= SLOWDIST ){
     r1.setSpeed( SLOW ); 
     if( distance <= MINDIST ){
        numTries--;
        Serial.print( "numTries = " );
        Serial.println( numTries );

        r1.stop();
        delay(1000);
        r1.turn( turnDir ); /* <- Causes motors to drive */
        delay(1000);
        if( numTries <= 0 ){
           Serial.println( "Changing directions" );
           numTries = MAXTRIES;
           driveDir = !driveDir;
           r1.setDirection( driveDir );
        }
     }
   } 
}
