
//A] Macro definitions and inclusion of header file

#define ARR_LENGTH  0XA
#include <stdio.h>
#include <string.h>


//B] Data Structure Definition
 
typedef struct {
    char FN[24], MI, LN[16];
}nametype;

typedef struct {
	 char ID[9];
    nametype name;
    char course[8];
    int yrlevel;
}studtype;

typedef struct {
    studtype studs[ARR_LENGTH];
    int count;
}List;

//C] Function Prototypes
void initList(List *A);                  //Initializes the list to be empty
void insertLast(List *A, studtype S);    //Inserts an element at the end of the list if there is still space; otherwise
                                         //    Display "List is full. Cannot insert Element with ID ___". 
                                                 

void displayHeader();
void displayStudent(studtype S);              //Displays info of a student record in 1 horizontal line
void displayList(List A);                //Displays the list. Calls displayStudent()

void deleteElem(List *A, char ID[]);     //Deletes the element bearing the given ID if the element is found; otherwise
                                              //    Display "Element with ID ___ is not found"

/*****************************************************************
 * Function Definitions                                          *
 *****************************************************************/

//----- Display Functions ------
void displayHeader()
{
	printf("\n\n");
	printf("%-10s", "Id Number");
   printf("%-13s", "FirstName");
   printf("%-3s", "MI");
   printf("%-13s", "LastName");
   printf("%-10s", "Program");
   printf("%-10s", "Year");		
}

void displayStudent(studtype S)
{
	printf("\n");
	printf("%-10s", S.ID);
   printf("%-13s", S.name.FN);
   printf("%-3c",  S.name.MI);
   printf("%-13s", S.name.LN);
   printf("%-10s", S.course);
   printf("%-10d", S.yrlevel);	
}  
            
void displayList(List A)
{
	int x;
	
	displayHeader();
	
	//Complete this function by traversing the list from the 1st element to the last element and
	//Call displayStudent()
   for(x = 0; x < A.count; x++){
      displayStudent(A.studs[x]);
   }

	printf("\n\nList has %d elements",  A.count);   //complete this line and uncomment
}  

void initList(List *A)
{
	//Complete this function 
   A->count = 0;
	
}

void insertLast(List *A, studtype S)   
{
   //Complete this function 	
   if (A->count >= ARR_LENGTH){
      printf("\n\nList is full. Cannot insert Element with ID %s", S.ID);
      return;
   }

   A->studs[A->count] = S;
   A->count++;
}   

void deleteElem(List *A, char ID[])
{
	//Complete this function
   int i;
   for(i = 0; i < A->count && strcmp (A->studs[i].ID, ID) != 0; i++);
   if(i < A->count){
       

   }
}    


