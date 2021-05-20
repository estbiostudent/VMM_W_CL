#include "header.h"

extern double ran2(int *seed);
void randomize_BA_directions(){
	
	for(i=0;i<M;i++){
		if(ran2(&seed)<.5){					//with 50% probability, swap in place
			//edge from i--->j becomes from j--->i
#ifdef directedGraph
			nodes.inDeg[edges.end[i]]-=1;
			nodes.inDeg[edges.start[i]]+=1;
			nodes.outDeg[edges.end[i]]+=1;
			nodes.outDeg[edges.start[i]]-=1;
#endif
			edges.start[i]+=edges.end[i];
			edges.end[i]=edges.start[i]-edges.end[i];		//swap in place
			edges.start[i]-=edges.end[i];
		}
	}
}