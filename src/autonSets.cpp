/** Autonomous routines */
#include "main.h"
/** programming skills run */
void test(){
	setCoords(0,0,30);	//25 degree offset
	baseTurn(90,1.35,0.95);
}
/** Autonomous routine for blue left spawn. */
void blue(){

}
void red(){
	//goal 1
	//shoot
	setCoords(0,0,30);
	setMech(127,127);
	delay(200);

	//goal 2
	//get ball
	setMech(127,0);
	//delay(500);
	baseMove(28.8);
	waitBase(1000);	//check
	baseTurn(90,1.35,0.95);
	waitBase(800);
	baseMove(30.5);
	waitBase (1000);
	delay(1000);
	//ram ball into centre
	baseTurn(0,1.35,0.95);
	waitBase(850);
	manualIndex();
	resetMech();
	baseMove(-24);
	waitBase(1500);

	//goal 3
	baseTurn(-46,1.45,0.85);
	waitBase(800);
	manualIndex();
	baseMove(68);
	waitBase(1550);
	manualIndex();
	setMech(-127,-127,0);
	delay(750);
	manualIndex();

	//goal 4
	baseMove(-70);
	waitBase(1250);
	baseTurn(-150); //tune kP & kD
	waitBase(700);
	baseMove(85);
	waitBase(1250);
	setMech(-127, 127, 127);
	delay(750);







}
