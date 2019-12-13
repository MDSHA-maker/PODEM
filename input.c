#include "input.h"
/***************************************************************************************************
Insert an element "X" at end of LIST "Cur", if "X" is not already in "Cur". 
If the "Cur" is Null, it creates a single element List using "X"
***************************************************************************************************/
void InsertEle(LIST **Cur,int X)
{
LIST *tl=NULL;
LIST *nl=NULL;

if ((tl=(LIST *) malloc(sizeof(LIST)))==NULL){ 
  printf("LIST: Out of memory\n");  
  exit(1);  }   
else{
  tl->Id=X;  tl->Next=NULL;
  if(*Cur==NULL){  
    *Cur=tl; 
    return;  }
  nl=*Cur; 
  while(nl!=NULL){
    if(nl->Id==X){       break;       }
    if(nl->Next==NULL){  nl->Next=tl; } 
    nl=nl->Next; }  
 }
return;
}

///this is initializing dont care
void InitializeDontcare(GATE *Node,int Tgat)
{

int i;

//printf("\nId\tName\tType\t#In\t#Out\tMark\tValue\t\tFanin\t\tFanout");
for(i=1;i<=Tgat;i++){
  if(Node[i].Type!=0){
    //printf("\n%d\t%s\t%d\t%d\t%d\t%d\t%d\t\t",i,Node[i].Name,Node[i].Type,Node[i].Nfi,Node[i].Nfo,Node[i].Mark,Node[i].Val);
    //PrintList(Node[i].Fin);  printf("\t\t");
    ///PrintList(Node[i].Fot); 
Node[i].Val=2;

}
}
return;

}




















//end of InsertEle
/***************************************************************************************************
Delete an element "X" from LIST "Cur",
***************************************************************************************************/	
void DeleteEle(LIST **Cur,int X)
{
LIST *fir = (*Cur);
LIST *lst = NULL;

if (fir==NULL) return;  
while((fir->Id!=X)&&(fir!= NULL)){
  lst=fir;
  fir=fir->Next; }   
if(fir!=NULL){
   if(lst==NULL){  (*Cur)=(*Cur)->Next;       }
   else{           lst->Next = fir->Next; }
   free(fir); }
else{ 
   return; }
return;
}//end of DeleteEle
/***************************************************************************************************************************
Return 1 if the element "x" is present in LIST "Cur"; Otherwise return  0  
*****************************************************************************************************************************/
int FindEle(LIST *Cur,int X)
{
LIST *temp=NULL;
	
temp=Cur;
while(temp!=NULL){
  if(temp->Id==X) return 1;
  temp=temp->Next; }
return 0;
}//end of FindEle
/***************************************************************************************************
Print the elements in LIST "Cur"          
***************************************************************************************************/
void PrintList(LIST *Cur)
{
LIST *tmp=Cur;

while(tmp!=NULL){   
  printf("%d  ", tmp->Id);
  tmp = tmp->Next; } 
return;
}//end of PrintList
/***************************************************************************************************
Count the total number  of elements in LIST "Cur"          
***************************************************************************************************/
int CountList(LIST *Cur)
{
LIST *tmp=Cur;
int size=0;

while(tmp!=NULL){   
  size++;
  tmp = tmp->Next; } 
return size;
}//end of PrintList
/***************************************************************************************************
Free all elements in  LIST "Cur"  
***************************************************************************************************/
void FreeList(LIST **Cur)
{
LIST *tmp=NULL;

if(*Cur==NULL){   return;  }
tmp=(*Cur);
while((*Cur) != NULL){
  tmp=tmp->Next;
  free(*Cur); 
  (*Cur)=tmp; }   
(*Cur)=NULL;
return;
}//end of FreeList 
/***************************************************************************************************
Initialize the paricular member of GATE structure
***************************************************************************************************/        
void InitiGat(GATE *Node,int Num)
{
Node[Num].Name=(char *) malloc(Mnam *sizeof(char));           //Dynamic memory allocation for an array
bzero(Node[Num].Name,Mnam);                                   //Clearing the string
Node[Num].Type=Node[Num].Nfi=Node[Num].Nfo=Node[Num].Mark=0;
Node[Num].Val=6;  
Node[Num].Fin=Node[Num].Fot=NULL;
//Node[Num].Rpath=Node[Num].Fpath=NULL;   
return;
}//end of InitiGat
/***************************************************************************************************
Print all contents(attribute) of all active member of GATE structure(DdNodes are not printed)
***************************************************************************************************/
void PrintGats(GATE *Node,int Tgat)
{
int i;

printf("\nId\tName\tType\t#In\t#Out\tMark\tValue\t\tFanin\t\tFanout");
for(i=1;i<=Tgat;i++){
  if(Node[i].Type!=0){
    printf("\n%d\t%s\t%d\t%d\t%d\t%d\t%d\t\t",i,Node[i].Name,Node[i].Type,Node[i].Nfi,Node[i].Nfo,Node[i].Mark,Node[i].Val);
    PrintList(Node[i].Fin);  printf("\t\t");
    PrintList(Node[i].Fot); }}
return;
}//end of PrintGats
/***************************************************************************************************
Free the memory of all contents of all members of GATE structure(DdNodes are already cleared)
***************************************************************************************************/
void ClearGat(GATE *Node,int Tgat)
{
int i;

for(i=1;i<=Tgat;i++){ 
  free(Node[i].Name);
  Node[i].Type=Node[i].Nfi=Node[i].Nfo=Node[i].Mark=Node[i].Val=0;
  FreeList(&Node[i].Fin);  FreeList(&Node[i].Fot); }
return;
}//end of ClearGat
/***************************************************************************************************
Count the Total Number of Primary inputs and outputs
***************************************************************************************************/
void CountPri(GATE *Node,int Tgat,int *Npi,int *Npo)
{
int i,j,k;

i=j=k=0;
for(i=1;i<=Tgat;i++){ 
  if(Node[i].Type!=0){
    if(Node[i].Nfi==0){      j++; }
    if(Node[i].Nfo==0){      k++; } }}
*Npi=j; *Npo=k;
return;
}//end of CountPri
/***************************************************************************************************
Convert (char *) type read to (int)     
***************************************************************************************************/
int AssignType(char *Gtyp)
{
if      ((strcmp(Gtyp,"inpt")==0) || (strcmp(Gtyp,"INPT")==0))       return 1;
else if ((strcmp(Gtyp,"from")==0) || (strcmp(Gtyp,"FROM")==0))       return 2;
else if ((strcmp(Gtyp,"buff")==0) || (strcmp(Gtyp,"BUFF")==0))       return 3;
else if ((strcmp(Gtyp,"not")==0)  || (strcmp(Gtyp,"NOT")==0))        return 4;
else if ((strcmp(Gtyp,"and")==0)  || (strcmp(Gtyp,"AND")==0))        return 5;
else if ((strcmp(Gtyp,"nand")==0) || (strcmp(Gtyp,"NAND")==0))       return 6;
else if ((strcmp(Gtyp,"or")==0)   || (strcmp(Gtyp,"OR")==0))         return 7;
else if ((strcmp(Gtyp,"nor")==0)  || (strcmp(Gtyp,"NOR")==0))        return 8;
else if ((strcmp(Gtyp,"xor")==0)  || (strcmp(Gtyp,"XOR")==0))        return 9;
else if ((strcmp(Gtyp,"xnor")==0) || (strcmp(Gtyp,"XNOR")==0))       return 10;
else                          			                     return 0;
}//end of AssignType
/***************************************************************************************************
 Function to read the Bench Mark(.isc files)
***************************************************************************************************/
int ReadIsc(FILE *fisc,GATE *graph)
{/*Node[Num].Name=(char *) malloc(Mnam *sizeof(char));           //Dynamic memory allocation for an array
bzero(Node[Num].Name,Mnam);                                   //Clearing the string
Node[Num].Type=Node[Num].Nfi=Node[Num].Nfo=Node[Num].Mark=0;
Node[Num].Val=6;  
Node[Num].Fin=Node[Num].Fot=NULL;*/
	char c,noty[Mlin],from[Mlin],str1[Mlin],str2[Mlin],name[Mlin],line[Mlin];
	int  i,id,fid,fin,fout,mid=0;

	// intialize all nodes in graph structure
	for(i=0;i<Mnod;i++){ InitiGat(graph,i); }
	//skip the comment lines
	do
		fgets(line,Mlin,fisc);
	while(line[0] == '*');
	// read line by line
	while(!feof(fisc)){
		//initialize temporary strings
		bzero(noty,strlen(noty));    bzero(from,strlen(from));
		bzero(str1,strlen(str1));    bzero(str2,strlen(str2));
		bzero(name,strlen(name));
		//break line into data
		sscanf(line, "%d %s %s %s %s",&id,name,noty,str1,str2);
		//fill in the type.
               // printf("%d %s %s %s %s\n",id,name,noty,str1,str2);
		strcpy(graph[id].Name,name);
		graph[id].Type=AssignType(noty);
		//fill in fanin and fanout numbers
		if(graph[id].Type!=FROM) {   fout= atoi(str1);  fin=atoi(str2); }
		else{                       fin=fout= 1; strcpy(from,str1);   
		//printf("%s\n",from); 
		}
		if(id > mid){ mid=id;  }
		graph[id].Nfo=fout;  graph[id].Nfi=fin;
		if(fout==0){  graph[id].po=1; }
		//create fanin and fanout lists
		switch (graph[id].Type)  {
		case 0     : printf("ReadIsc: Error in input file (Node %d)\n",id); exit(1);
		case INPT  : break;
		case AND   :
		case NAND  :
		case OR    :
		case NOR   :
		case XOR   :
		case XNOR  :
		case BUFF  :
		case NOT   : for(i=1;i<=fin;i++) {
				fscanf(fisc, "%d", &fid);
				InsertEle(&graph[id].Fin,fid);
				InsertEle(&graph[fid].Fot,id);
                       //  printf("%d\t%d\t",id,fid);
 }
printf("\n");
			fscanf(fisc,"\n");  break;
		case FROM  : for(i=mid;i>0;i--){
				if(graph[i].Type!=0){
					if(strcmp(graph[i].Name,from)==0){ 
		//	printf("%dfrom\t%d\n",id,fid);
		 fid=i; break; } } }
			InsertEle(&graph[id].Fin,fid);
			InsertEle(&graph[fid].Fot,id);   break;
		} //end case
		bzero(line,strlen(line));
		fgets(line,Mlin,fisc);
	} // end while
	return mid;
}//end of ReadIsc 


int ReadVec(FILE *fvec,PATTERN *vector)
{
	int a,b,c,d;      //random variables
	char str[Mpi];        //char array

	a=0;          //intializing the temporary variables
	while(!feof(fvec)){
		bzero(str,Mpi);                  //initialing the string
		fgets(str,Mpi,fvec);             //reading a single line
		if(*str!='\0'){
			bzero(vector[a].piv,Mpi);                           //initialing the string
			strcpy(vector[a].piv,str);                          //copy the string into a piv in vector structure
			a++; } }
	return a;
}//end of readvec
void ClearCircuit(GATE *graph,int i)
{
	int num=0;
	for(num=0;num<i;num++){
		graph[num].Type=graph[num].Nfi=graph[num].Nfo=graph[num].po=0;
		graph[num].Mark=graph[num].Val=0;
		if(graph[num].Type!=0){  bzero(graph[num].Name,Mnam);
			if(graph[num].Fin!=NULL){   FreeList(&graph[num].Fin);  graph[num].Fin = NULL;     }
			if(graph[num].Fot!=NULL){   FreeList(&graph[num].Fot);  graph[num].Fot = NULL;     } } }
	return;
}//end of ClearCircuit
/****************************************************************************************************************************/
