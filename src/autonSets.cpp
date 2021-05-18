/** Autonomous routines */
#include "main.h"
/** programming skills run */
void test(){
}
/** Autonomous routine for blue left spawn. */
void blue(){

}
void red(){
	setCoords(0,0,30);	//25 degree offset
	setMech(127,127);
	delay(500);
	setMech(127,0);
	delay(500);
	baseMove(28);
	waitBase(1000);
	baseTurn(90,1.2,1.5);
	waitBase(500);
	baseMove(35);
	waitBase (1000);


}
