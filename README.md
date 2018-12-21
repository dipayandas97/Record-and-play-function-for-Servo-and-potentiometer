# Record-and-play-function-for-Servo-and-potentiometer
Record-and-Play-function-for-Servo-and-potentiometer : This arduino code reads the postion of a potentiometer over a finite amount of time and then outputs a servo writable corresponding value (in degrees) in a loop, until the system is toggled onto recording mode again.
This is a modular program structure that can be cascaded over a set of potentiometers and servos to make a teaching/recording system for servo driven systems that needs to repeat a specific movement over and over again.

 *  A 1K pull up resistor for A0 pin. 
 *  A touch of GND to AO pin will toggle the system between record and play mode.
 *  Though this is made for copying a potentiometer's movement into a servo, 
    it can be used for other kinds of outputs too like LED etc (need to change the upper and lower bound of map() for respective outputs).
 *  To use a servo include Servo.h library, initialize a servo object like: Servo servo 
 *  and attach it to a pin using servo.attach(PWMpinNumber)
 *  Move the servo using servo.write() function
