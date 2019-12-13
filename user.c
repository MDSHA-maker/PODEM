#include "input.h"


int untestable;
int and[5][5]={{0,0,0,0,0},{0,1,2,3,4},{0,2,2,2,2},{0,3,2,3,0},{0,4,2,0,4}};
//int nand[3][3]={{1,1,1},{1,0,2},{1,2,2}};
int or[5][5]={{0,1,2,3,4},{1,1,1,1,1},{2,1,2,2,2},{3,1,2,3,1},{4,1,2,1,4}};
//int nor[3][3]={{1,0,2},{0,0,0},{2,0,2}};
int xor[3][3]={{0,1,2},{1,0,2},{2,2,2}};
//int xnor[3][3]={{1,0,2},{0,1,2},{2,2,2}};
int inv[5]={1,0,2,4,3};
int from[5]={0,1,2,3,4};
int superflag=0;
int faultsite=-1;
int faultvalue=-1;
LIST *Dfrontier;
int MAXSIZE = 10000;       
int stack[10000];     
int top = -1;            
FILE *Res;       
int isempty() {

   if(top == -1)
      return 1;
   else
      return 0;
}
   
int isfull() {

   if(top == MAXSIZE)
      return 1;
   else
      return 0;
}

int peek() {
   return stack[top];
}

int pop() {
   int data;
	
   if(!isempty()) {
      data = stack[top];
      top = top - 1;   
      return data;
   } else {
      printf("Could not retrieve data, Stack is empty.\n");
   }
}

int push(int data) {

   if(!isfull()) {
      top = top + 1;   
      stack[top] = data;
   } else {
      printf("Could not insert data, Stack is full.\n");
   }
}

int chartoint(char c)
{
if(c == 'x')
{
return 2;

}
else {return (c-'0');}

}

char inttochar(int c)
{
if(c == 2)
{
return 'x';

}
else {return c+'0';}

}
int shahrul(int gate,int a,int b)


{
if (gate==INPT)
{

return from[a];
}
if(gate==AND)
{
return and[a][b];
}

if(gate==NAND) 
{

return and[a][b];
}
if(gate==OR)
{
return or[a][b];
}
if(gate==NOR)
{
return or[a][b];
}
if(gate==XOR)
{
return xor[a][b];
}
if(gate==XNOR)
{
return xor[a][b];
}

if(gate==BUFF)
{
return from[a];
}
if(gate==NOT)
{
return inv[a];
}

if(gate==FROM)
{

return from[a];
}


}

void PrintValidInpGats(GATE *Node,int Tgat)
{
int i;
fprintf( Res, "\n\n");

for(i=1;i<=Tgat;i++){
  if(Node[i].Type!=0&&Node[i].Type==1){
		

    printf("%d",Node[i].Val);
    		//fprintf( Res, "\n\n");
    				fprintf(Res, "%d",Node[i].Val);
    //PrintList(Node[i].Fin);  printf("\t\t");
    //PrintList(Node[i].Fot); 
}
	
}
	fprintf( Res, "\n\n");
return;
}




void PODEMTOTAL(GATE* graph, int nodeCount, FILE *Resss)

{int i;
untestable=0;
int saf;
Res=Resss;   
for(i=1;i<=nodeCount;i++){
  if(graph[i].Type!=0){
 //   printf("\n%d\t%s\t%d\t%d\t%d\t%d\t%d\t\t",i,Node[i].Name,Node[i].Type,Node[i].Nfi,Node[i].Nfo,Node[i].Mark,Node[i].Val);
    //PrintList(Node[i].Fin);  printf("\t\t");
  //  PrintList(Node[i].Fot); 
//InitializeDontcare(graph,nodeCount);
//printf("\n\nNew simulation\n\n");
while(!isempty())
{
  // printf("%d\n", peek() ); 
   pop();
}


InitializeDontcare(graph,nodeCount);

//graph[i].Val=0;//faultfree after sim it will have value D
saf=1;//stuck at 0 to be justified
//printf("\n%s",graph[i].Name);
superflag=1;
faultsite=i;
faultvalue=saf;
printf("\n\n\nthe fault site is:%d and doing simulaiton for stuck at 0\n",faultsite);
	fprintf( Res, "\nthe fault site is:%dand doing simulaiton for stuck at 0:",faultsite);
podemone(graph,i,saf,nodeCount);

PrintValidInpGats(graph,nodeCount);

}


}
//156 0
for(i=1;i<=nodeCount;i++){
  if(graph[i].Type!=0){
 //   printf("\n%d\t%s\t%d\t%d\t%d\t%d\t%d\t\t",i,Node[i].Name,Node[i].Type,Node[i].Nfi,Node[i].Nfo,Node[i].Mark,Node[i].Val);
    //PrintList(Node[i].Fin);  printf("\t\t");
  //  PrintList(Node[i].Fot); 
//InitializeDontcare(graph,nodeCount);
//printf("\n\nNew simulation\n\n");

InitializeDontcare(graph,nodeCount);
//graph[i].Val=0;//faultfree after sim it will have value D
saf=0;//stuck at 0 to be justified
//printf("\n%s",graph[i].Name);

while(!isempty())
{
   //printf("%d\n", peek() ); 
   pop();
}



superflag=1;
faultsite=i;
faultvalue=saf;

printf("\n\n\nthe fault site is:%dand doing simulaiton for stuck at 1\n",faultsite);
	fprintf( Res, "\nthe fault site is:%dand doing simulaiton for stuck at 1:",faultsite);
podemone(graph,i,saf,nodeCount);

PrintValidInpGats(graph,nodeCount);

}


}


//InitializeDontcare(graph,nodeCount);

//InitializeDontcare(graph,nodeCount);
//graph[i].Val=0;//faultfree after sim it will have value D
//saf=1;//stuck at 0 to be justified
//printf("\n%s",graph[i].Name);
//i=11;
//printf("\nEnter the fault site to be tested:\n");
//scanf("%d",&i);
//printf("\nEnter the value to be justified at fault site:\n");
//scanf("%d",&saf);
//superflag=1;
//faultsite=i;
//faultvalue=saf;
//printf("the fault site is:%dand value to be placed is%d ",faultsite,faultvalue);
//podemone(graph,i,saf,nodeCount);
//
//PrintValidInpGats(graph,nodeCount);
//PrintGats(graph,nodeCount);
//podemone(graph,i,saf,nodeCount);
//PrintGats(graph,nodeCount);
//podemone(graph,i,saf,nodeCount);
//PrintGats(graph,nodeCount); 
//saf=0;
//InitializeDontcare(graph,nodeCount);
//podemone(graph,i,saf,nodeCount);
//podemone(graph,i,saf,nodeCount);
//podemone(graph,i,saf,nodeCount);  289
//PrintGats(graph,nodeCount); 
/*for(i=1;i<=nodeCount;i++){
  if(graph[i].Type!=0){
    
//
	
InitializeDontcare(graph,nodeCount);
graph[i].Val=1;//faultfree after sim it will have value D
podemone(graph,i,graph[i].Val);
PrintGats(graph,nodeCount);  
InitializeDontcare(graph,nodeCount);

graph[i].Val=0;	//
//InitializeDontcare(graph,nodeCount);
podemone(graph,i,graph[i].Val); 
PrintGats(graph,nodeCount);    
    //printf("\n%d\t%s\t%d\t%d\t%d\t%d\t%d\t\t",i,Node[i].Name,Node[i].Type,Node[i].Nfi,Node[i].Nfo,Node[i].Mark,Node[i].Val);
    //PrintList(Node[i].Fin);  printf("\t\t");
    //PrintList(Node[i].Fot); 




}


}*/
fprintf(Res,"\n\ntotal no of Testable fault is: %d",(2*nodeCount-untestable));
fprintf(Res,"\n\ntotal no of untestable fault is: %d",untestable);
fclose(Res);

}

int getObjectiveindex(GATE* graph, int nodeCount)
{
LIST* tempNode = NULL;
LIST* tempNode1=NULL;
if(!Dfrontier){
	printf("Dfrontier is empty");
		}
else{
tempNode=Dfrontier;
while(tempNode!=NULL){   
  	//printf("%d  ", tmp->Id);
		if(graph[tempNode->Id].Val==3||graph[tempNode->Id].Val==4) continue;//already D or D' at output
		else if ( graph[ tempNode->Id].Fin != NULL )
					{


					tempNode1 = graph[tempNode->Id].Fin;
					while(	tempNode1!=NULL	)
					{
						
								if(graph[tempNode1->Id].Val==2)
								{
									//InsertEle(&Dfrontier,i);
										//printf("\nDfrotnier input id from getobjective%d",tempNode1->Id);//Dfrotnier er ekta input er id pathacchi 
										int noncontrollingvalue=findnoncontrollingvalue(graph,nodeCount,tempNode->Id);
										//printf("\nDfrontier value to be justified:\t%d",noncontrollingvalue);
											if(noncontrollingvalue==-1) printf("this shouldnt have happedned");
										int result=podemone(graph,tempNode1->Id,noncontrollingvalue,nodeCount);
										return result;
											//I am sure that this index is a input with X value with other input as D
										//break;
										
									
								}
								tempNode1=tempNode1->Next;
								
											
						
						}


					}
  tempNode = tempNode->Next; } 



}

return -1;

}


void getDfrontier(GATE *Node,int Tgat)
{
int i;
LIST* tempNode = NULL;
//printf("\nId\tName\tType\t#In\t#Out\tMark\tValue\t\tFanin\t\tFanout");
for(i=1;i<=Tgat;i++){
  if(Node[i].Type!=0){
    //printf("\n%d\t%s\t%d\t%d\t%d\t%d\t%d\t\t",i,Node[i].Name,Node[i].Type,Node[i].Nfi,Node[i].Nfo,Node[i].Mark,Node[i].Val);
    //PrintList(Node[i].Fin);  printf("\t\t");
    //PrintList(Node[i].Fot); 
		if(Node[i].Val==2){
				
					if ( Node[ i].Fin != NULL )
					{tempNode = Node[i].Fin;
					while(	tempNode!=NULL	)
					{
						
								if(Node[tempNode->Id].Val==3||Node[tempNode->Id].Val==4)
								{
									InsertEle(&Dfrontier,i);
										//printf("\n%d has been inserted into D Frontier",i);
										
										break;
									
								}
								tempNode=tempNode->Next;
								
											
						
						}


					}
			}
							
	
}

}
return;
}


void clearDfrontier()
{
FreeList(&Dfrontier);
}

///generate a function to get i
int podemone(GATE* graph,int i,int val,int nodeCount)
{
//backtrace
//GATE inptval;
int result;


int returntype;
//if(graph[i].po==1){printf("\nfault at primary output");}
int inptgateindex=backtrace(graph,i,val);
push(inptgateindex);
printf("\n The input gate:%d",inptgateindex);
//printf("\nindex:%dval:\t%d",inptgateindex,graph[inptgateindex].Val);
//printf("\nThe input gate index returned from backtrace:%d",inptgateindex);
//printf("before simulation:");
//PrintGats(graph,nodeCount);
result=simulateCircuitforfault(graph,nodeCount,i,val);
//printf("\nthe result returned from simulation%d",result);
//PrintGats(graph,nodeCount);
//clearDfrontier();
//PrintGats(graph,nodeCount);
//getDfrontier(graph,nodeCount);
//printf("\nDfrontier:\t");
if(result==1)
{
printf("\nreached desired value");
result=1;
return ;

}
PrintList(Dfrontier);
if(!Dfrontier&&superflag==0&&result!=1){
printf("\nDfrontier is empty in main loop");
result=2;
}
if(result==2)
{
printf("\nrevert last input");
//backtrack
//int data=pop();
int data;
while(result==2||(!Dfrontier&&superflag==0&&result!=1)){
	if(isempty()){
			fprintf( Res, "\nthe fault is untestable\n");
		printf("the fault is untestable");
untestable++;
		result=8;
//	while(1){}
		break;
	}
	data=pop();
	graph[data].Val=inv[graph[data].Val];
result=simulateCircuitforfault(graph,nodeCount,i,val);

	

printf("\n The input gate:%d",data);

if(result==2||(!Dfrontier&&superflag==0&&result!=1))
{graph[data].Val=2;
	
	
}

}

if(result=8) return;
printf("The result now:%d",result);




}

//else 
//printf("result:%d",result);
 if(result==0)
{printf("\nreached X in fault value");
//printf("\nsending to function%d,with objective: %d",i,val);
podemone(graph,i,val,nodeCount);
//simulate with same i as it is still x
}


if(result==4)
{//input satisfied the objective get next objective
//i,val=getObjective();
int indexobjective=getObjectiveindex(graph,nodeCount);//indexObjective must have a value 2
if(indexobjective==-1){printf("\nall objective satisfied");
result=podemone(graph,i,val,nodeCount);}

//return result;
//return;
}



/*if(val==1){

graph[i].Val=3;//value to D

}
if(val==0){

graph[i].Val=4;//value to D'

}/*/


//i has the index of gate
//simulate



//checkconflictanddfrontier


//ifnoconflictreturn


//ifconflictorfrontieremptychangeinpt


//simulate

return result;
//ifstillcnflictreturnerroruntestable[5][5]={{0,0,0,0,0},{0,1,2,3,4},{0,2,2,2,2},{0,3,2,3,0},{0,4,2,0,4}};
 



}
//noncontorolling value
int findnoncontrollingvalue(GATE *graph,int Tgat,int indexobjective)
{

if(graph[indexobjective].Type==AND) return 1;


if(graph[indexobjective].Type==OR) return 0;

if(graph[indexobjective].Type==NAND) return 1;

if(graph[indexobjective].Type==NOR) return 0;
if(graph[indexobjective].Type==NOT) return 1;
//return -1;
return -1;
}















//i is index of current node

int backtrace(GATE* graph,int i,int val)
{

int counter=0;//invnumber
				//bactrace
LIST* tempNode;
//tempNode->Id=i;				//int j;

//printf("%s",graph[i].Name);
while(graph[i].Type!=INPT)
{		tempNode = graph[i].Fin;
					while ( tempNode != NULL )
					{//printf("%d",graph[tempNode->Id].Type);
						
								if(graph[tempNode->Id].Val==2)
								{
										if(graph[i].Type==NOT||graph[i].Type==NAND||graph[i].Type==NOR)
												{counter++;
											//printf("%s\n",graph[tempNode->Id].Name);
                                                                                                      }
									i=tempNode->Id;
										break;
								}
								tempNode=tempNode->Next;
								
													
					}


}


if(counter%2==0)//even
{
graph[i].Val=val;	
}
else//even
{//printf("inverted");
graph[i].Val=inv[val];
} 
//printf("\n%s\t%d",graph[i].Name,graph[i].Val);
return i;//returns input gate with the specified value

}
/*typedef struct GATE_type
{
  char *Name;                            //Name of the gate
  int Type,Nfi,Nfo,Mark,Val;             //Type, No of fanins, No of fanouts, Marker,Value
  LIST *Fin,*Fot;                        //Fanin members, Fanout members 
 int po;
} GATE;\
typedef struct LIST_type {
   int  Id;		   //Id for current element		
   struct LIST_type *Next; //Pointer to next element (if there is no element,it will be NULL)		
} LIST;*/
//simulate for fault
int simulateCircuitforfault( GATE* graph, int nodeCount,int fnode,int saf)
{
	int  circuitLoopCount;
	int a;
	LIST* tempNode = NULL;
	int flag=0;

		for ( circuitLoopCount = 0; circuitLoopCount <= nodeCount; circuitLoopCount++ )
		{
		
			
		    
				if ( graph[ circuitLoopCount ].Fin != NULL )
				{
					tempNode = graph[ circuitLoopCount ].Fin;
					 a=graph[ tempNode->Id].Val; // store this value to send to the propogation table
                                                      //printf("%d\n%d",a,circuitLoopCount );
					while ( tempNode != NULL )
					{
					
						if ( tempNode->Next != NULL )
						{
							
							a=shahrul(graph[ circuitLoopCount ].Type,a,graph[ tempNode->Next->Id ].Val); // this is the second argument to the lookup table
						                //printf("%d\n",graph[ circuitLoopCount ].Type);
                                                           //if(a==2){p16	16gat	6	2	2	0	3	rintf("%d\n",graph[ circuitLoopCount ].Type);}
 						  
// call and store the return of the lookup table
							/*
							 * this must be able to handle multi-input gates! This is not as difficult as it sounds.
							 * Remember, a four input AND gate is the same as two two input AND gates in series, so all
							 * you have to do is store the results of one loop ( one AND gate ), grab the next loops fan in value, and use the previous
							 * loops result as an argument to the lookup table. Repeat!
							 */
						}
                                          
						else if(graph[ circuitLoopCount ].Type == NOT||graph[ circuitLoopCount ].Type == BUFF||graph[ circuitLoopCount ].Type == FROM)
							{a = shahrul( graph[ circuitLoopCount ].Type, a, graph[ 0 ].Val);}
						tempNode = tempNode->Next;
					}
                               //printf("\n%d\t%d",circuitLoopCount,a);19

				graph[ circuitLoopCount ].Val = a;// set this value = to the lookup table's logic
                                      if(	graph[ circuitLoopCount ].Type==NAND || 		graph[ circuitLoopCount ].Type==NOR||graph[ circuitLoopCount ].Type==XNOR)
						{
                                                         

								graph[ circuitLoopCount ].Val=shahrul( NOT, graph[ circuitLoopCount ].Val, 0);
							}	// NAND 	
						

						
					
				}
					


						
						if(circuitLoopCount ==faultsite && graph[faultsite].Val==faultvalue&&superflag==0)
						{	//printf("here");

							if(faultvalue==1){		graph[circuitLoopCount].Val=3;//should only place D bar for the first time
														printf("D placed again");//flag=1;//for now;
														
									}
							else if(faultvalue==0){		
												graph[circuitLoopCount].Val=4;
														printf("D' placedagain");	
									}

							}


					
						





						



						if(circuitLoopCount ==fnode && graph[circuitLoopCount].Val==saf)
						{	//printf("\n%d\t%d\t%d",graph[circuitLoopCount].Val,saf,circuitLoopCount);	
								flag=4;
								//break;
							if(saf==1&&superflag==1){
									graph[circuitLoopCount].Val=3;//should only place D bar for the first time
										//printf("D placed");//flag=1;//for now;
										superflag=0;
									}
								else if(saf==0&&superflag==1){
									graph[circuitLoopCount].Val=4;
										//printf("D' placed");		//flag=1;//for now
											superflag=0;
									}	
								
							
										}
						else if(circuitLoopCount ==fnode && graph[circuitLoopCount].Val==inv[saf])
						{
							
							flag=2;//failure
						}
						
				if(graph[circuitLoopCount].po==1&&(graph[circuitLoopCount].Val==3||graph[circuitLoopCount].Val==4))
							{
							  flag=1;//done
								}
			
		}  

	clearDfrontier();
//PrintGats(graph,nodeCount);
getDfrontier(graph,nodeCount);

	return flag;
}











