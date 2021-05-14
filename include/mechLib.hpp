/** Header file for mech_lib.cpp */
#ifndef _MECH_LIB_HPP_
#define _MECH_LIB_HPP_
/** refer to mech_lib.cpp for function documentation */
/** traditional-style mech library */
extern bool autoIndex;
void setMech(int r, int i, int s);
void resetMech();
void setMech(int r, int i, int s, int t);
void waitIntakeColor();
void waitShootColor();
void autoFrontIntake();
void autoBackIntake();
void autoLoad();
void MechControl(void * ignore);
#endif
