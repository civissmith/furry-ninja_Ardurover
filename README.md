This archive contains the source code at the last stage of developement. This project was terminated on 21Oct2012 because I didn't have access to the hardware needed to complete the project.
The project was to make a rover using an Arduino, Arduino Motor Shield and an RC car. The chassis used had two opposing drivetrains (one motor drove both left-forward and left-rear wheels through a gear set, the other controlled the right side). This chassis worked in either straight forward or straight back, but the combined hardware couldn't supply enough power to allow the vehicle to turn. The project will be archived until such time that I can acquire the hardware needed to build a motor control circuit that can source the demanded current.

Warning/Disclaimer:
The code base at this stage was still very much in flux. There may be hard coded pin assignments or wonky, redundant, useless or confusing code sections. This code has not been thoroughly bug-checked and I cannot guarantee that it does exactly what you want it to do. Anyone is free to take this code base as a start for a new project. I WILL NOT accept or merge updates to this code.

Let me repeat:
I WILL NOT accept or merge updates to this code.
I WILL NOT accept or merge updates to this code.
I WILL NOT accept or merge updates to this code.
I WILL NOT accept or merge updates to this code.
I WILL NOT accept or merge updates to this code.

So, don't be surprised if I tell you that I'm not accepting updates. 

Project Layout:
   
arduino-1.0.1/libraries/Rover/
arduino-1.0.1/libraries/Rover/rover.cpp
arduino-1.0.1/libraries/Rover/rover.h
   rover.cpp - Function bodies, implementation code for the Rover class. This class logically embodies full rover platform. It's
               design is based around calls that one would make to a physical rover. Again, it is based on SPECIFIC hardware because
               of the funky drive train that was used originally. You will have to touch this file - guaranteed.

   rover.h   - Interface for users of the Rover class. Depending on what changes are needed, you might not need to touch anything here.
               I attempted to write the functions at a generic enough level that this should be transparent, but you might want to
               at least open this file.

arduino-1.0.1/libraries/Motor/
arduino-1.0.1/libraries/Motor/motor.h
arduino-1.0.1/libraries/Motor/motor.cpp
   motor.cpp - Function bodies, implementation code for the Motor class. This class is meant to encapsulate small DC hobby motors.
               It will not work well for servo, stepper, or brushless motors. The controls are also pretty rudimentary. There's 
               some spillage here where motor logic was fudged to account for the counter-rotation, so you'll probably need to
               do work here. You can curse me as you modify this one, I let some higher-level designs push through into here.
   motor.h   - Interface for users of the Motor class... you might not need to touch this.

   *** Important Note *** 
   This motor control system is based on the Arduino Motor Shield (using the L298 chip). The control interfaces are relative to
   the pinout from that board. Don't waste your time with this code if you're using the SeeedStudio or any other board.   

arduino-1.0.1/libraries/Ping/
arduino-1.0.1/libraries/Ping/ping.h
arduino-1.0.1/libraries/Ping/ping.cpp
   ping.cpp - Function bodies, implementation code for the Parallax Ping))) Ultrasonic sensor. The equations used are derived from
              the SI and US standard equations distributed by Parallax and Arduino. The rest of the class is built around those
              equations to encapsulate the hardware. The accuracy can't be guaranteed, although rough tests showed that the
              inch and centimeter functions worked with a very low error. You can probably leave this alone.
   ping.h   - Interface for users of the Ping class.

sketchbook/
sketchbook/rover/
sketchbook/rover/rover.ino
   rover.ino - This is the main entry point for the Arduino environment. It was built and tested on an Ubuntu Linux machine running
               Ubuntu 12.04 (kernel 3.2.0-32-generic) using Arduino ver. 1.0.1. The code has been tested on an Arduino Duemilenove
               (ATmega328) and an Arduino Diecimila (ATMega168). It HAS NOT been run on an Arduino Uno of any kind, and I can't
               certify that it will work. Try it... if it works, it works.


Good luck and may all your symbols resolve!



