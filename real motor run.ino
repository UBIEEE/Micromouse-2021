#include <AFMotor.h>

// Number of steps per output rotation
// Change this as per your motor's specification
const int stepsPerRevolution = 60;

// connect motor to port #2 (M3 and M4)
AF_Stepper motor1(stepsPerRevolution, 2);
AF_Stepper motor2(stepsPerRevolution, 1);

void setup() {
  Serial.begin(9600);
  Serial.println("Stepper test!");

  motor1.setSpeed(160);// 10 rpm
  motor2.setSpeed(160);   
}

void loop() {
  //single coil steps
  motor1.step(1, FORWARD, SINGLE); 
  motor2.step(1, FORWARD, SINGLE); 
  
  //Double coil steps
  //motor1.step(1, FORWARD, DOUBLE); 
  //motor2.step(1, BACKWARD, DOUBLE);

  //Interleave coil steps
  //motor1.step(1, FORWARD, INTERLEAVE); 
  //motor2.step(1, BACKWARD, INTERLEAVE); 

  //Microstep steps
  //motor1.step(1, FORWARD, MICROSTEP); 
  //motor2.step(1, BACKWARD, MICROSTEP); 
}
