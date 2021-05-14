#include "main.h"
double encdL = 0, encdR = 0, bearing = 0, angle = halfPI;
int intakeColorValue = 0, shootColorValue = 0;
void Sensors(void * ignore){
  Rotation lRot(lRotPort);
  Rotation rRot(rRotPort);
	ADIAnalogIn intakeColor (intakeColorPort);
	ADIAnalogIn shootColor (shootColorPort);
  Imu imu (imuPort);

  while(true){
    if(!imu.is_calibrating()){

    encdL = lRot.get_position();
    encdR = rRot.get_position();
    bearing = imu.get_rotation();
    angle = halfPI - bearing * toRad;



    intakeColorValue = intakeColor.get_value();
    shootColorValue = shootColor.get_value();

    delay(5);
  }
  }
}
