#include "main.h"
int DEBUG_MODE = 8;
void printPosMaster(){
  Controller master(E_CONTROLLER_MASTER);
  master.print(1, 0, "%.2f %.2f %.2f", X, Y, bearing*toDeg);
  delay(50);
  master.print(2, 0, "Battery: %.0f ",battery::get_capacity());
}
void printPosTerminal(){
  printf("x: %.2f y: %.2f bearing: %.2f\n", X, Y, bearing*toDeg);
}
void printEncdTerminal(){
  printf("encdL: %.2f encdR: %.2f\n", encdL, encdR);
}
void printErrorEncdTerminal(){
  printf("errorEncdL: %.2f errorEncdR: %.2f\n", errorEncdL, errorEncdR);
}
void printErrorBearingTerminal() {
  printf("errorBearing: %.2f\n", errorBearing*toDeg);
}
void printTargPowerTerminal(){
  printf("targPowerL: %.2f, targPowerR: %.2f\n", targPowerL, targPowerR);
}
void printPowerTerminal(){
  printf("powerL: %.2f powerR: %.2f\n", powerL, powerR);
}
void Debug(void * ignore){
  while(true){
    printPosMaster();
    switch(DEBUG_MODE){
      case 1: printPosTerminal(); break;
      case 2: printEncdTerminal(); break;
      case 3: printErrorEncdTerminal(); break;
      case 4: printErrorBearingTerminal(); break;
      case 5: printTargPowerTerminal(); break;
      case 6: printPowerTerminal(); break;
      case 7: {
          printf("errorEncdL: %.2f errorEncdR: %.2f\t", errorEncdL, errorEncdR);
          printf("targPowerL: %.2f, targPowerR: %.2f\t", targPowerL, targPowerR);
          printf("powerL: %.2f powerR: %.2f\n", powerL, powerR);
          break;
        } 
      case 8: {
          printf("errorEncdL: %.2f errorEncdR: %.2f\t", errorEncdL, errorEncdR);
          printf("targPowerL: %.2f, targPowerR: %.2f\t", targPowerL, targPowerR);
          printf("powerL: %.2f powerR: %.2f\n", powerL, powerR);
          printf("encdL: %.2f encdR: %.2f\n", encdL, encdR);
          printf("indexValue: %.2f ShooterValue: %.2f\n", intakeColorValue , shootColorValue);
          break;
      }
    }
    delay(50);
  }
}