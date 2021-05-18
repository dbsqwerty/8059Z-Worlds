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
	baseMove(25.8 );
	waitBase (800);
	delay(1000);
	baseTurn(0,1.35,0.95);
	waitBase(750);
	manualIndex();
	resetMech();
	baseMove(-20);
	waitBase(750);
	baseTurn(-50,1.45,0.85);
	waitBase(500);




}
