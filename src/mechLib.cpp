/** Other mechanical functions. */
#include "main.h"
#include "mechLib.hpp"
int intakeColorThreshold = 2850, shootColorThreshold = 2830;
double powerRollers = 0, powerIndexer = 0, powerShooter = 0;
double rollerMax = 127, indexMax=127, shooterMax = 127;
bool autoIndex = false;


void setMech(int r, int i, int s){
  powerRollers = r;
  powerIndexer = i;
  powerShooter = s;
}
void resetMech(){
  setMech(0, 0, 0);
}
void setMech(int r, int i, int s, int t){
  setMech(r, i, s);
  delay(t);
  resetMech();
}
void waitIntakeColor(){
  // printf("wait intake color \t value: %d\n", shootColorValue);
  while(intakeColorValue>intakeColorThreshold) delay(5);
}
void waitShootColor(){
  // printf("wait Shoot color \t value: %d\n", shootColorValue);
  while(shootColorValue>shootColorThreshold) delay(5);
}
void autoFrontIntake(){
  setMech(rollerMax, indexMax, 0);
  waitIntakeColor();
  resetMech();
}
void autoBackIntake(){
  setMech(0, indexMax, 0);
  waitIntakeColor();
  resetMech();
}
void autoLoad(){
  printf("auto load\n");
  setMech(0, indexMax, 0);
  waitShootColor();
  resetMech();
}
void MechControl(void * ignore){

}
