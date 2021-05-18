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
	baseMove(28.6);
	waitBase(1000);	//check
	baseTurn(90,1.35,0.95);
	waitBase(800);
	baseMove(30.5);	//funny thing must check
	waitBase (1000);
	delay(1000);
	//ram ball into centre
	baseTurn(0,1.35,0.95);
	waitBase(850);
	manualIndex();
	resetMech();
	baseMove(-25);
	waitBase(1150);

	//goal 3
	baseTurn(-50,1.45,0.85);
	waitBase(800);
	manualIndex();
	baseMove(68);
	waitBase(1550);
	manualIndex();
	setMech(-127,-127,0);
	delay(700);
	manualIndex();

	//goal 4
	baseMove(-76);
	waitBase(1250);
	baseTurn(-146); //tune kP & kD
	waitBase(1500);
	baseMove(100);
	waitBase(1900);
	delay(100);
	setMech(-127, 127, 127);
	delay(1000);







}
