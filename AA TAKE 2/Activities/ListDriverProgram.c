#include <stdio.h>
#include "ArrayList.h"       //Uncomment ArrayList.h  or LinkedList.h
//#include "LinkedList.h"    //Only one .h file should be included at a time
int main()
{
 //Uncomment this when ArrayList.h or LinkedList.h is included in the program   
  studtype data[] = {  {"STUD1001", {"John", 'R', "Doe"}, "BSCS", 1},
           				  {"STUD1005", {"Jane", 'L', "Smith"}, "BSIT", 1},
           				  {"STUD1002", {"Mark", 'S', "Johnson"}, "BSIS", 1},
                       {"STUD1009", {"Joey", 'K', "Lee"}, "BSIS", 2},
            		     {"STUD1015", {"Michael", 'T', "Garcia"}, "BSIT", 2},
           				  {"STUD1006", {"Emlio", 'P', "Martinez"}, "BSIT", 3},
           				  {"STUD1011", {"David", 'A', "Rodriguez"}, "BSCS", 4},
            		     {"STUD1012", {"Olivia", 'B', "Hernandez"}, "BSCS", 3},
            			  {"STUD1008", {"James", 'C', "Kim"}, "BSIS", 3},
           			     {"STUD1010", {"Mia", 'D', "Nguyen"}, "BSCS", 1}
           	  			};
  int num = sizeof(data)/sizeof(data[0]); //num holds the number of elements in the array data
   
    
  /*-----------------------------------------------------------------------------------
   Task 1: 
    a) Declare a list variable L and Initialize it to be empty by calling initList()
	  b) Populate the list with 10 elements by calling insertLast() 10 times. Use array data
    c) Display the List by calling displayList()
   -------------------------------------------------------------------------------------*/
  List L;
  initList (&L);
  printf("\n\nTask 1: Populating the list");
  for(int i = 0; i < num; i++){
    insertLast(&L, data[i]);
  }
  
  displayList(L);
   
  //printf("\n\n"); system("Pause");   //Uncomment this if needed
  
  /*-----------------------------------------------------------------------------------
   Task 2: 
    a) Call deleteElem() passing the ID number STUD1009, then call displayList()
    b) Call deleteElem() passing the ID number STUD1001, then call displayList()
    c) Call deleteElem() passing the ID number STUD1013, then call displayList()
   -------------------------------------------------------------------------------------*/

  printf("\n\nTask 2: Deleting Elements in the list");
  
  deleteElem(&L, "STUD1009");
  //displayList(L);
  deleteElem(&L, "STUD1001");
  //displayList(L);
  deleteElem(&L, "STUD1013");
  //displayList(L);

  /*-----------------------------------------------------------------------------------
   Task 3: 
     a) Call deleteAllCourse() passing the list and a given course
     b) Call displayList()
	-------------------------------------------------------------------------------------*/
  printf("\n\nTask 3: Deleting Elements in the list bearing the given course");

  //deleteAllCourse(&L, "BSIT");
  //displayList(L);

   /*-----------------------------------------------------------------------------------
   Task 4: 
     a) Declare studtype variable named myRec and initialize to store your own information.
	      For ID,start with STUD + last 4 digits of your ID number. 
	   b) Call insertFirstUnique() passing the list and myRec; then call displayList()
	   c) Insert the first 6 records of array data into list L by calling insertFirstUnique() 
	      6 times. Note: Elements may already be existing in the list will not be inserted;
     d) Call displayList()
	-------------------------------------------------------------------------------------*/
/*  printf("\n\nTask 4: Inserting elements that do not yet exist in the list");
  studtype myRec = {"STUD0693", {"Mikee", 'S', "Dionson"}, "BSIT", 4};
  insertFirstUnique (&L, myRec);
  //displayList(L);

  for(int i = 0; i <= 6; i++){
    insertFirstUnique (&L, data[i]);
  }
  //displayList(L);
*/
  /*-----------------------------------------------------------------------------------
   Task 5: 
     a) Declare a studtype variable named yourRec, call findRetElem() passing the list L and 
	      the ID number STUD1005. Use yourRec as the catcher variable; then call displayStudent()  
	   b) Call findRetElem() passing the list L and the ID number STUD1001. 
	      Make the function findRetElem() the actual parameter of displayStudent().
	   c) Call findRetElem() passing the list L and the ID number STUD2001. 
	      Use yourRec as the catcher variable; then call displayStudent()   
	-------------------------------------------------------------------------------------*/
/*
  printf("\n\nTask 5: Returning an element from the list if element exist");
  studtype yourRec = findRetElem(L, "STUD1005");
  displayStudent(yourRec);
  displayStudent(findRetElem(L, "STUD1001"));
  yourRec = findRetElem(L, "STUD2001");
  displayStudent(yourRec);
*/
  return 0;
}