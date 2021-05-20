#include "header.h"

int tempint;


/* 
 requring q~0 supply should mean that everyone has to die to kill you (supply ~ 1 for everyone).
 requring q~1 supply should mean that anyone has to die to kill you (supply ~ degree for everyone).
 */


void determine_supply(double q){

	for(i=0;i<N;i++){
        nodes.providedSupply[i]=1;
		tempint=((int)((1-q)*((double)(nodes.inDeg[i]))));		//the supply is q* in degrees
		nodes.neededSupply[i]=((double)(nodes.inDeg[i]-tempint));	
	}
	


}