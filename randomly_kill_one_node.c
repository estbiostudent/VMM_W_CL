#include "header.h"

extern double ran2(int *seed);


int ranPos,tempJ,tempK;

void randomly_kill_one_node(int numAlive,int timestep){
    
    
    
    ranPos=((int)(((double)numAlive)*ran2(&seed)))+1;    //choose a random living node
    tempK=0;
    for(tempJ=0;tempJ<N;tempJ++){
        if(nodes.status[tempJ]==1){
            tempK+=1;
            if(tempK==ranPos){
                ranPos=tempJ;              //find the location of that node
                break;
            }
        }
    }
    nodes.status[ranPos]=0;
    nodes.timeOfDeath[ranPos]=-timestep;
        //time of death for nodes killed randomly is tagged negative
        //use absolute value if you don't want this functionality
}