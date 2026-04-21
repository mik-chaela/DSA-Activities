
//A] Macro definitions and inclusion of header file

#include <stdio.h>
#include <string.h>
#include <stdlib.h>


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

typedef struct node{
   studtype stud;
	struct node *link;  
}*List;

//C] Function Prototypes
void initList(List *A);                  //Initializes the list to be empty
void insertLast(List *A, studtype S);    //Inserts an element at the end of the list;  
                                         //If malloc() is not successfull, display "Memory Allocation Error. Cannot insert Element with ID ___". 
                                                 
void displayHeader();
void displayStudent(studtype S);          //Displays info of a student record in 1 horizontal line
void displayList(List A);                 //Displays the list. Calls displayStudent()

void deleteElem(List *A, char ID[]);     //Deletes the element bearing the given ID if the element is found; otherwise
                                         // Display "Element with ID ___ is not found"

void deleteAllCourse (List* A, char course[]); //Deletes all occurrence of records bearing the given course                                        
void insertFirstIfUnique (List* A, studtype S); //Inserts a data at the first of the list if unique
                                                //Display error message "Cannot insert. Data is found on the list"

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
	displayHeader();
	
	//Complete this function by traversing the list from the 1st element to the last element, and calling displayStudent()
	List trav;
   int counter = 0;
   for(trav = A; trav != NULL; trav = trav->link){
      displayStudent(trav->stud);
      counter++;
   }
	printf("\n\nList has %d elements.",  counter);   //complete this line and uncomment
}  

void initList(List *A)
{
	//Complete this function
   *A = NULL;
}

void insertLast(List *A, studtype S)
{
	//Complete this function
   List* trav;
   for(trav = A; *trav != NULL; trav = &(*trav)->link);
   List newNode = (List)malloc(sizeof(struct node));
   if(newNode != NULL){
      newNode->stud = S;
      newNode->link = NULL;
      *trav = newNode;
   } else {
      printf("Memory Allocation Error. Cannot insert Element with ID %s\n", S.ID);
   }

}   

void deleteElem(List *A, char ID[])
{
	//Complete this function
   List* trav;
   for (trav = A; *trav != NULL && strcmp ((*trav)->stud.ID, ID) != 0; trav = &(*trav)->link);
   if (*trav != NULL){
      List temp = *trav;
      *trav = temp->link;
      free(temp);
   } else {
      printf("\n\nElement with ID %s is not found", ID);
   }
}    

void deleteAllCourse (List* A, char course[])
{
   List* trav;
   for(trav = A; *trav != NULL; ){
      if (strcmp((*trav)->stud.course, course) == 0){
         List temp = *trav;
         *trav = temp->link;
         free(temp);
      } else {
         trav = &(*trav)->link;
      }
   }
}

void insertFirstIfUnique (List* A, studtype S)
{

}
