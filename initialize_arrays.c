#include "header.h"


void initialize_arrays(){
	
    for(i=0;i<N;i++){
        nodes.deg[i]=0;
#ifdef weightedGraph
        nodes.strength[i]=0;
#endif
		
		
#ifdef directedGraph
        nodes.inDeg[i]=0;
        nodes.outDeg[i]=0;
#ifdef weightedGraph
        nodes.inStrength[i]=0;
        nodes.outStrength[i]=0;
#endif
#endif
		
    }
	
    
    for(i=0;i<M;i++){
        edges.start[i]=0;
        edges.end[i]=0;
#ifdef directedGraph
        edges.twoWay[i]=0;
#endif
#ifdef weightedGraph
        edges.weight[i]=1;
#endif
		
    }
    
}

