#include <stdio.h>

#define MAX 10
typedef struct {
    int id;
    char name[20];
    char program [6];
    int yearlvl;
    float gpa;
} Student;

typedef struct {
    Student studInfo[MAX];
    int count;
} List;

void printList (List A){
    printf("===== STUDENT LIST =====\n");
    for(int i = 0; i < A.count; i++){
        printf("%d | %s | %s | Year %d | GPA: %.2f\n", A.studInfo[i].id, A.studInfo[i].name, A.studInfo[i].program, A.studInfo[i].yearlvl, A.studInfo[i].gpa);
    }
    printf("\n");
}
/*
Student findHighest (List A){
    Student highest = A.studInfo[0];
    
    for(int i = 1; i < A.count && A.studInfo[i].gpa < highest.gpa; i++){
        highest = A.studInfo[i];
    }
    return highest;
}
*/
void insertFirst (List* A, Student new){
    int i;
    if (A->count < MAX){
        for(i = A->count; i > 0; i--){
            A->studInfo[i] = A->studInfo[i-1];
        }
        A->studInfo[i] = new;
        A->count++;
        printf("\nSuccess! Student inserted at beginning.\n\n");
    } else{
        printf("\nError! Student list is full. Delete some to insert more.\n");
    }
}

int main() {
    List students = {{{101, "John Cruz", "BSCS", 2, 1.75}, 
                    {102, "Maria Santos", "BSIT", 3, 1.50},
                    {103, "Xander Labide", "BSIT", 4, 1.25},
                    {104, "Mikee Dionson", "BSIT", 4, 1.36},
                    {105, "Franzane Dabuco", "BSCS", 1, 1.56}
    }, 5};
    printList (students);
    printf("1. Insert at Beginning\n");
    printf("2. Insert at End\n");
    printf("3. Delete by ID\n");
    printf("4. Search by Name\n");
    printf("5. Display All\n");
    printf("6. Compute Statistics\n");
    printf("7. Exit\n\n");
    /*
    float total = 0.00;
    for(int i = 0; i < students.count; i++){
        total += students.studInfo[i].gpa;
    }
    
    printf("\nAverage GPA: %.2f\n", total / students.count);
    Student highest = findHighest (students);
    printf("Highest GPA: %s (%.2f)\n", highest.name, highest.gpa);
    */
    int choice;
    Student new;
    while(1){
        printf("Choice: ");
        scanf("%d", &choice);
        
        switch (choice){
            case 1:
                printf("Enter New Student's ID: ");
                scanf("%d", &new.id);
                printf("Enter New Student's Name: ");
                scanf(" %[^\n]", new.name);
                printf("Enter New Student's Program: ");
                scanf(" %[^\n]", new.program);
                printf("Enter New Student's Year Level: ");
                scanf("%d", &new.yearlvl);
                printf("Enter New Student's Year GPA: ");
                scanf("%f", &new.gpa);
                
                insertFirst (&students, new);
                break;
            case 2:
                printf("Sorry! Under construction...\n");
                break;
            case 3:
                printf("Sorry! Under construction...\n");
                break;
            case 4:
                printf("Sorry! Under construction...\n");
                break;
            case 5:
                printList(students);
                break;
            case 6:
                printf("Sorry! Under construction...\n");
                break;
            case 7: 
                return 0;
        }
    }
}