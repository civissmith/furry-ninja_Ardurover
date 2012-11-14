/*******************************************************************************
* @Title: ping.h 
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
#ifndef __PING_H__
#define __PING_H__

#include <Arduino.h>

/* Define the unit of measure (uom) constants */
#define INCHES  0x00
#define CM      0x01
#define FEET    0x02
#define METERS  0x03
#define NULLPIN 0xFF /* Used to initial the pin */
/*******************************************************************************
 * Class:   PingSensor
 * Members:
 *     _sigPin
 * Methods: 
 *     void assignSigPin( short pin );
 *     long getDistance( short uom );
 ******************************************************************************/
namespace ping{
   class PingSensor{

          public:
             void assignSigPin( short pin );
             long getDistance( short uom );
             PingSensor();
             PingSensor(short pin );
          private:
             short _sigPin; /* The Signal Pin defined on the hardware */
   };
};
#endif /* __PING_H__ */
