#include "input.h"
/***************************************************************************************************
Command Instructions
***************************************************************************************************/
//To Compile: make
//To Run: ./project c17.isc 
/***************************************************************************************************
 Main Function
***************************************************************************************************/
int main(int argc,char **argv)
{
FILE *Isc,*Pat,*Res;                  //File pointers used for .isc, .pattern, and .res files
int Npi,Npo,Tgat;                     //Tot no of PIs,Pos,Maxid,Tot no of patterns in.vec,.fau
GATE *Node;                           //Structure to store the ckt given in .isc file 
clock_t Start,End;                    //Clock variables to calculate the Cputime
double Cpu;                           //Total cpu time
int a,j;                              //Temporary variables
static PATTERN vector[Mpt]; 
printf("%s",argv[1]);

/****************PART 1.-Read the .isc file and store the information in Node structure***********/
Npi=Npo=Tgat=0;                                //Intialize values of all variables
Isc=fopen(argv[1],"r");                        //File pointer to open .isc file 
Node=(GATE *) malloc(Mnod * sizeof(GATE));     //Dynamic memory allocation for Node structure
Tgat=ReadIsc(Isc,Node);                        //Read .isc file and return index of last node
fclose(Isc);  
InitializeDontcare(Node,Tgat);                               //Close file pointer for .isc file
//PrintGats(Node,Tgat);           
Res=fopen(argv[2],"w");                   //Print the information of each active gate in Node structure after reading .isc file
PODEMTOTAL(Node,Tgat,Res);

CountPri(Node,Tgat,&Npi,&Npo);                 //Count the No of Pis and Pos
//printf("\n\nNpi: %d Npo: %d\n",Npi,Npo);       //Print the no of primary inputs and outputs
/***************************************************************************************************/
                 //print all members of graph structure
	//printf("\nTime Taken for ISC File: %f",iexe);      //print execuetion time

	//Read the .vec file and store the information in  vector structure
//*printf("%s",argv[2]);
/*printf("Hello");
	Pat=fopen(argv[2],"r");                           //file pointer to open .vec file
	Npi=0; 
Npi=ReadVec(Pat,vector);                   //read .vec file and store in vector structure and return tot number of patterns
printf("\nTot No of Pattern: %d",Npi);             //print total number of patterns in .vec file
	fclose(Pat);                                      //close file pointer for .vec file
	printf("\nIndex\tInputVector\n");
	for(a=0;a<Npi;a++){  printf("%d\t%s",a,vector[a].piv); } //print all members of vector structure*/
/*Res=fopen(argv[3],"w");                           //file pointer to open .out file for printing results

	//Perform Logic Simulationfor each Input vector and print the Pos .val in output file
      simulateCircuit(Node,Tgat,vector,Npi,Res);
	fclose(Res);                                                  //close file pointer for .out file
	ClearCircuit(Node,Mnod);                                      //clear memeory for all members of graph
	for(a=0;a<Npi;a++){ bzero(vector[a].piv,Mpi); }                //clear memeory for all members of vector


/***************************************************************************************************/

//ClearGat(Node,Tgat); 
 free(Node);                                      //Clear memeory for all members of Node
return 0;
}//end of main
/****************************************************************************************************************************/

