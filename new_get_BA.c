#include "header.h"

double probList[Nnodes];
double probNorm;
double ranVal;

extern double ran2(int *seed);
int findPos(double x,int tempK);
int findPos_Ran(double x,int tempK);

int tempI;
int accept;
double tempVal;

void get_BA(int kinVal);
void get_Ran(int kinVal);



void get_BA(int kinVal){
    
	if(kinVal!=2){
		printf("-------------WARNING---------------------------");
		printf("variable k is no longer supported in this code\n");
		printf("The networks currently generated are not to be trusted\n");
		printf("older, valid method found in copies of the older get_BA.c\n");
		printf("\n");
	}
	
	
	/*
	 //ensure that the arrays are initialized before running this function
	 //node degrees _are not_ set to zero before iteration
	 */
	
    
	for(i=0;i<N;i++){
		nodes.deg[i]=0;
		nodes.inDeg[i]=0;
		nodes.outDeg[i]=0;
	}
	
	for(i=0;i<kinVal;i++){
		nodes.deg[i]=1;
		nodes.inDeg[i]=1;
		nodes.outDeg[i]=1;
	}

	k=0;
	for(i=0;i<kinVal-1;i++){
		for(j=i+1;j<kinVal;j++){
			
			edges.end[k]=i;
			edges.end[k+1]=j;
			edges.start[k]=j;		//create a fully connected core
			edges.start[k+1]=i;
			k+=2;
							
		}
	}
	
	//start with kinVal nodes, each of which have one virtual degree.
	
	/*  INITIALIZE  WITH VIRTUAL EDGES  */
	
	
	
	
	
//	k=0;
    for(i=kinVal;i<N;i++){		//insert a new node i, which has kinVal edges
		
		
		for(l=0;l<kinVal;l++){	//loop over 0...kinVal edges
			
			
			accept=0;
			while(accept==0){				//ensure that we don't repeat edges.
				j=findPos(ran2(&seed),i);	//pick a node to add a new edge to
				accept=1;					//check to see if this edge (i to j) or (j to i) exists already
				if(i==j){
					accept=0;
				}

//				printf("%d %d\n",i,j);
			}//end of while loop.  Ensures that we don't repeat an edge
			
			
			if(nodes.deg[i]%2==0){			//if even degree already, have an edge leading from i to j
				edges.end[k]=i;				
				edges.start[k]=j;
				nodes.inDeg[i]+=1;
				nodes.outDeg[j]+=1;
				nodes.deg[i]+=1;
				nodes.deg[j]+=1;
			}
			else{							//otherwise orient leading j to i
				edges.end[k]=j;				
				edges.start[k]=i;			
				nodes.inDeg[j]+=1;
				nodes.outDeg[i]+=1;
				nodes.deg[i]+=1;
				nodes.deg[j]+=1;

			}
			k+=1;						//update edge iteration
			
			if(k>M){
				printf("over edge count while building:  %d %d\n",k,M);
			}
			
		}
    }    
    
	
	
	
	
	
	
	
	
	
	
	
	
}


void get_Ran(int kinVal){
    
	if(kinVal!=2){
		printf("-------------WARNING---------------------------");
		printf("variable k is no longer supported in this code\n");
		printf("The networks currently generated are not to be trusted\n");
		printf("older, valid method found in copies of the older get_BA.c\n");
		printf("\n");
	}
	
	
	/*
	 //ensure that the arrays are initialized before running this function
	 //node degrees _are not_ set to zero before iteration
	 */
	
    
	for(i=0;i<N;i++){
		nodes.deg[i]=0;
		nodes.inDeg[i]=0;
		nodes.outDeg[i]=0;
	}
	
	for(i=0;i<kinVal;i++){
		nodes.deg[i]=1;
		nodes.inDeg[i]=1;
		nodes.outDeg[i]=1;
	}
	
	k=0;
	for(i=0;i<kinVal-1;i++){
		for(j=i+1;j<kinVal;j++){
			
			edges.end[k]=i;
			edges.end[k+1]=j;
			edges.start[k]=j;		//create a fully connected core
			edges.start[k+1]=i;
			k+=2;
			
		}
	}
	
	//start with kinVal nodes, each of which have one virtual degree.
	
	/*  INITIALIZE  WITH VIRTUAL EDGES  */
	
	
	
	
	
	//	k=0;
    for(i=kinVal;i<N;i++){		//insert a new node i, which has kinVal edges
		
		
		for(l=0;l<kinVal;l++){	//loop over 0...kinVal edges
			
			
			accept=0;
			while(accept==0){				//ensure that we don't repeat edges.
				j=findPos_Ran(ran2(&seed),i);	//pick a node to add a new edge to
				accept=1;					//check to see if this edge (i to j) or (j to i) exists already
				if(i==j){
					accept=0;
				}
				
				
			}//end of while loop.  Ensures that we don't repeat an edge
			
			
			if(nodes.deg[i]%2==0){			//if even degree already, have an edge leading from i to j
				edges.end[k]=i;				
				edges.start[k]=j;
				nodes.inDeg[i]+=1;
				nodes.outDeg[j]+=1;
				nodes.deg[i]+=1;
				nodes.deg[j]+=1;
			}
			else{							//otherwise orient leading j to i
				edges.end[k]=j;				
				edges.start[k]=i;			
				nodes.inDeg[j]+=1;
				nodes.outDeg[i]+=1;
				nodes.deg[i]+=1;
				nodes.deg[j]+=1;
				
			}
			k+=1;						//update edge iteration
			
			if(k>M){
				printf("over edge count while building:  %d %d\n",k,M);
			}
			
		}
    }    
    
	
	
	
	
	
	
	
	
	
	
	
	
}


int findPos_Ran(double x,int tempK){
	probNorm=0;
	tempVal=0;
	
	for(tempI=0;tempI<tempK;tempI++){
		probNorm+=((double)(1));
	}    
	tempVal=((double)(1))/probNorm;
    tempI=0;
	
	
    while(0<1){
        if(x<=tempVal){
            return tempI;
        }
        else{
			if(tempVal>1){		//if there is a problem, give up!
				printf("BA method failed:  probabilities not normalized at %d %d\n",i,l);
                return -1;
            }			
            tempI+=1;
            tempVal+=((double)(1))/probNorm;
        }
        
    }
    
}

int findPos(double x,int tempK){
	probNorm=0;
	tempVal=0;
	
	for(tempI=0;tempI<tempK;tempI++){
		probNorm+=((double)(nodes.deg[tempI]));
	}    
	tempVal=((double)(nodes.deg[0]))/probNorm;
    tempI=0;
	
	
    while(0<1){
        if(x<=tempVal){
            return tempI;
        }
        else{
			if(tempVal>1){		//if there is a problem, give up!
				printf("BA method failed:  probabilities not normalized at %d %d\n",i,l);
                return -1;
            }			
            tempI+=1;
            tempVal+=((double)(nodes.deg[tempI]))/probNorm;
        }
        
    }
    
}