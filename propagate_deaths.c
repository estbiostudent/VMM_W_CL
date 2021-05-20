#include "header.h"


int accept;
int tempI;

int propagate_deaths(int timestep){

    
	/*  this is designed _only_ for the case of nodes needing qk_{in} neighbors alive.
		a system where nodes supply a variable amount is not represented here
	 */
	accept=0;
	while(accept==0){
		accept=1;
        
            //first, determine the current supply chain
		for(tempI=0;tempI<N;tempI++){
			fedBy[tempI]=0;			//no one is fed yet
		}

		
		
		for(tempI=0;tempI<M;tempI++){
			if(nodes.status[edges.start[tempI]]==1){		//if the feeder is alive
      			fedBy[edges.end[tempI]]+=1;				//the node is fed by one more start node
			}
		}
                       
		for(tempI=0;tempI<N;tempI++){
			if(fedBy[tempI]<((int)nodes.neededSupply[tempI]) & nodes.status[tempI]==1){
				accept=0;
				nodes.status[tempI]=0;
                nodes.timeOfDeath[tempI]=timestep;
				
        	}
		}
        
    }

	
    accept=0;
    for(tempI=0;tempI<N;tempI++){
        accept+=nodes.status[tempI];
    }
	return(accept);
    

}