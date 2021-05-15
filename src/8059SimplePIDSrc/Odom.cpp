#include "main.h"
/*-----------------------------------------USER INPUT-----------------------------------------*/
const double baseWidth = 10.51829263080055; //Enter distance in inches between side encoders
const double inPerDeg = 0.000242; //Determine empirically using at least 1 rotation
/*--------------------------------------------------------------------------------------------*/
double X = 0, Y = 0, bearing = 0, angle = halfPI, prevEncdL = 0, prevEncdR = 0;
void setCoords(double x, double y, double b){
  X = x;
  Y = y;
  bearing = b;
}
void Odometry(void * ignore){
  double changeX = 0, changeY = 0, changeBearing = 0;
  while(true){
    double encdChangeL = encdL-prevEncdL;
    double encdChangeR = encdR-prevEncdR;

    double distance = (encdChangeL + encdChangeR)/2*inPerDeg;
    changeBearing = (encdChangeL - encdChangeR)*inPerDeg/baseWidth;
    changeX = distance * cos(angle);
    changeY = distance * sin(angle);
    /** update prev variables */
    X += changeX;
    Y += changeY;
    bearing += changeBearing;
    angle = halfPI - bearing;
    prevEncdL = encdL;
    prevEncdR = encdR;
    Task::delay(5);
  }
}