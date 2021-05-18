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
	setCoords(0,0,30);
	setMech(127,127);
	delay(500);
	setMech(127,0);
	delay(500);
	baseMove(28);
	waitBase(1000);
	baseTurn(90,1.35,0.95);
	waitBase(750);
	baseMove(31);
	waitBase (800);
	delay(1000);
	baseTurn(-90);
	waitBase(750);
	baseMove(-24);
	waitBase(750);
	baseTurn(-135);
	waitBase(750);
	baseMove(78);
	waitBase(1250);




}
