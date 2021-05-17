/** Other mechanical functions. */
#include "main.h"
#include "mechLib.hpp"

int outdoorIntake = 2508, outdoorShoot = 2508;

int indoorIntake = 2900, indoorShoot = 2900;

int intakeColorThreshold = 0, shootColorThreshold = 0;
double powerRollers = 0, powerIndexer = 0, powerShooter = 0;
double rollerMax = 127, indexMax=127, shooterMax = 127;
bool autoIndex = false, outdoorField=false;

bool debug = false;

void setMech(int r, int s){
  powerRollers = r;
  powerShooter = s;
}
void resetMech(){
  setMech(0, 0);
}
void setMech(int r, int s, int t){
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
void switcheroo(){
  //switch to outdoor field conditions
  if (!competition::is_connected() && outdoorField){
  intakeColorThreshold = outdoorIntake;
  shootColorThreshold = outdoorShoot;
  }
  else{
    intakeColorThreshold = indoorIntake;
    shootColorThreshold = indoorShoot;
  }
}
void MechControl(void * ignore){
  Motor lRoller (lRollerPort);
  Motor rRoller (rRollerPort);
  Motor indexer (indexerPort);
  Motor shooter (shooterPort);
  Controller master(E_CONTROLLER_MASTER);
  double indexerMove = 0, shooterMove = 0, rollersMove = 0;

  while(true){
    switcheroo();
    if (autoIndex){
      if (intakeColorValue < intakeColorThreshold && shootColorValue < shootColorThreshold){indexerMove=0;debug=true;}
      else {
        debug = false;
        if (competition::is_autonomous())indexerMove=1;
        else indexerMove=master.get_digital(DIGITAL_L1);
      }
    }
    else{
      indexerMove=(master.get_digital(DIGITAL_L1) - master.get_digital(DIGITAL_L2));
    }
    //shooting code
    if(master.get_digital(DIGITAL_R2) && master.get_digital(DIGITAL_R1)) {
      shooterMove=0.75;
    }else if(master.get_digital(DIGITAL_R2)){
      shooterMove=-1;
    }else if(master.get_digital(DIGITAL_R1)){
      shooterMove=1;
      indexerMove=1;
    }else{
      shooterMove=0.05;
    }
    //outake ALLLL 
    if (master.get_digital(DIGITAL_L2)){
      shooterMove=-1;
      indexerMove=-1;
      rollersMove=-1;
    }
    //rollllersssss
    rollersMove=(master.get_digital(DIGITAL_L1) - master.get_digital(DIGITAL_L2));

    powerIndexer = (indexerMove*indexMax);
    powerRollers = (rollersMove*rollerMax);
    powerShooter = (shooterMove*shooterMax);
    lRoller.move(powerRollers);
    rRoller.move(powerRollers);
    indexer.move(powerIndexer);
    shooter.move(powerShooter);
    delay(5);
  }
}
