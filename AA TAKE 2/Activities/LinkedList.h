
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

void deleteAllCourse(List *A, char crs[]);  //Delete all occurrences of the given course   //For Task 3

void insertFirstUnique(List *A, studtype S);  //Insert the given elements record at the first position of the list if the given record
                                              //  does not yet exist in the list; otherwise insertion is not possible and an error 
                                              //  message is displayed "Element with ID number ___ already exists in the list"
                                              //  Note: Elements are uniquely identified through the ID     //Task 4
                                              
studtype findRetElem(List A, char ID[]);     //Find the element bearing the given ID from the given list and 
                                             //  return the element record bearing the given ID. If element does not exist
											            //  return a dummy element with "XXXX" , 0, and '\0' values for string, integer, and 
											            //  character fields respectively.           
                                             //For Task 5 

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
      printf("\n\nMemory Allocation Error. Cannot insert Element with ID %s", S.ID);
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

//----- For Task 3 -----	
void deleteAllCourse(List *A, char crs[]) 
{
	//Complete this function
   List* ptr; 
   for(ptr = A; *ptr != NULL;){
      if(strcmp((*ptr)->stud.course, crs) == 0){
         List temp = *ptr;
         *ptr = temp->link;
         free(temp);
      } else {
         ptr = &(*ptr)->link;
      }
   }
}

//----- For Task 4 -----
void insertFirstUnique(List *A, studtype S)
{
	//Complete this function
   List trav;
   for(trav = *A; trav != NULL && strcmp (trav->stud.ID, S.ID) != 0; trav = trav->link);
   if(trav == NULL){
      List new = (List)malloc(sizeof(struct node));
      if(new != NULL){
         new->stud = S;
         new->link = *A;
         *A = new;
      } else {
         printf("\n\nMemory Allocation Error. Cannot insert Element with ID %s", S.ID);
      }
   } else {
      printf("\n\nElement with ID number %s already exists in the list", S.ID);
   }
}

//----- For Task 5 -----
studtype findRetElem(List A, char ID[])
{
	//Complete this function
   List trav;
   studtype dummy = {"XXXX", {"XXXX", '\0', "XXXX"}, "XXXX", 0}; 
   for(trav = A; trav != NULL && strcmp (trav->stud.ID, ID) != 0; trav = trav->link);
   if(trav != NULL){
      return trav->stud;
   } else {
      return dummy;
   }
}
