/*******************************************************************************
* @Title: ping.cpp 
*
* @Author: Phil Smith 
*
* @Date: 19-Oct-2012	05:55 PM
*
* @Project: Arduino Library
*
* @Purpose: This module implements the functions for the Parallax Ping)))
*           distance sensor.
*
* @Modification History: 
* PROJECT TERMINATED
*******************************************************************************/
#include "ping.h"
namespace ping{
   void PingSensor::assignSigPin( short pin ){
      _sigPin = pin;
   }
   
   long PingSensor::getDistance( short uom ){
   
      long duration;
   
      if( _sigPin != NULLPIN ){
   
         pinMode( _sigPin, OUTPUT );
         digitalWrite( _sigPin, LOW );
         delayMicroseconds(2);
         digitalWrite( _sigPin, HIGH );
         delayMicroseconds(5);
         digitalWrite( _sigPin, LOW );
   
         pinMode( _sigPin, INPUT );
         duration = pulseIn( _sigPin, HIGH );
   
         switch( uom ){
            case INCHES:
               return duration / 74 / 2;
               break;
   
            case CM:
               return duration / 29 / 2;
               break;
   
            case FEET:
               return (duration / 74 / 2) / 12;
               break;
   
            case METERS:
               return (duration / 29 / 2) / 100;
               break;
   
            default:
               return 0;
               break;
         }
      }else{
         /* If the signal pin is not set, return negative distance */
         return -1;
      }
   }
   
   PingSensor::PingSensor(){
      _sigPin = NULLPIN;
   }
   
   PingSensor::PingSensor( short pin){
      _sigPin = pin;
   }
};
