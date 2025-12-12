#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// -----------------------------
// Struct Declarations
// -----------------------------
typedef struct apple {
   char name[20];
   char color[10];
   int hardness;   // 1-10
   int size_cm;
   bool ripe;
} Apple;

typedef struct node {
   Apple *app;            // Pointer to Apple
   struct node *LC;       // Left child
   struct node *RC;       // Right child
} Node, *BST;              // Node is the struct, BST is a pointer type

typedef struct box {
   Apple apples[50]; // array of Apple structs
   int count;
   int capacity;
} Box;

// -----------------------------
// Function Prototypes
// -----------------------------
BST createNode(Apple *a);
BST insertBST(BST root, Apple *a);
BST deleteNode(BST root, const char *key);
BST makeAppleTree(Apple apples[], int n);   // Exam #3 = Make Apple Tree

void inorderTraversal(BST root);
void preorderTraversal(BST root);
     
BST harvestRecursive(BST root, Box *box);   // Exam #1 = Harvest ripe then put in box
BST harvestRotten(BST root, Box *box);     // Exam #2 = Harvest rotten then put in box

void initBox(Box *box, int capacity);
void displayBox (Box* box);

// -----------------------------
// Main Function
// -----------------------------
int main() {
   // Initialize Box
   Box box;
   initBox(&box, 10);

   // Define apples in main (important, do not remove this)
   Apple apples[10] = {      
       {"Fuji", "red", 7, 8, true},
       {"Gala", "green", 6, 7, true},
       {"Honeycrisp", "red", 5, 6, false},
       {"Golden", "yellow", 8, 9, true},
       {"RedDel", "red", 6, 7, true},
       {"Granny", "green", 7, 8, true},
       {"Jonathan", "red", 8, 9, true},
       {"McIntosh", "red", 4, 7, true},
       {"PinkLady", "pink", 6, 7, true},
       {"Empire", "red", 7, 8, false}
   };

   // Build the Apple tree by calling makeAppleTree
   BST tree = makeAppleTree(apples, 10);

   printf("In-order traversal of BST:\n");
   inorderTraversal(tree);

   printf("\n\nPre-order traversal of BST:\n");
   preorderTraversal(tree);

   // Harvest ripe apples
   printf("\n\nHarvested Ripe Apples:\n");
   harvestRecursive(tree, &box);
   displayBox(&box);

   // Harvest rotten apples
   printf("\n\nRotten Apples:\n");
   harvestRotten(tree, &box);
   displayBox(&box);

   return 0;
}

void initBox(Box *box, int capacity){
    box->count = 0;
    box->capacity = capacity;
}

BST makeAppleTree(Apple apples[], int n){
    BST root = NULL;
    for(int i = 0 ; i < n; i++){
        root = insertBST(root, &apples[i]);
    }
    return root;
}

BST createNode(Apple *a){
    BST newNode = (BST)malloc(sizeof(Node));
    newNode->app = a;
    newNode->LC = NULL;
    newNode->RC = NULL;

    return newNode;
}

BST insertBST(BST root, Apple *a){
    if(root == NULL){
        return createNode(a);
    }

    int compare = strcmp(a->name, root->app->name);
    if(compare < 0){
        root->LC = insertBST(root->LC, a);
    } else if (compare > 0){
        root->RC = insertBST(root->RC, a);
    }

    return root;
}

void inorderTraversal(BST root){ //left, root, right
    if(root != NULL){
        inorderTraversal(root->LC);
        printf("%s\n", root->app->name);
        inorderTraversal(root->RC);
    }
}

void preorderTraversal(BST root){ //root, left, right
    if(root != NULL){
        printf("%s\n", root->app->name);
        preorderTraversal(root->LC);
        preorderTraversal(root->RC);
    }
}

BST deleteNode(BST root, const char *key){
    if(root == NULL){
        return NULL;
    }

    int compare = strcmp(key, root->app->name);
    if(compare < 0){
        root->LC = deleteNode(root->LC, key);
    } else if (compare > 0){
        root->RC = deleteNode(root->RC, key);
    } else {
        //Leaf Node
        if(root->LC == NULL && root->RC == NULL){
            free(root);
            return NULL;
        }

        //Right Only
        else if (root->LC == NULL){
            BST temp = root->RC;
            free(root);
            return temp;
        }

        //Left Only
        else if(root->RC == NULL){
            BST temp = root->LC;
            free(root);
            return temp;
        }

        //Two children
        BST successorParent = root;
        BST successor = root->RC;

        while (successor->LC != NULL){
            successorParent = successor;
            successor = successor->LC;
        }

        root->app = successor->app;

        if(successorParent->LC == successor){
            successorParent->LC = successor->RC;
        } else {
            successorParent->RC = successor->RC;
        }
        free(successor);
    }
    return root;
}

BST harvestRecursive(BST root, Box *box){
    if(root == NULL){
        return NULL;
    }

    root->LC = harvestRecursive(root->LC, box);
    root->RC = harvestRecursive(root->RC, box);

    if(root->app->ripe){
        if(box->count < box->capacity){
            box->apples[box->count++] = *(root->app);
        }
        root = deleteNode(root, root->app->name);
    }

    return root;
}

BST harvestRotten(BST root, Box *box){
    if(root == NULL){
        return NULL;
    }

    root->LC = harvestRotten(root->LC, box);
    root->RC = harvestRotten(root->RC, box);

    if(!root->app->ripe){
        if(box->count < box->capacity){
            box->apples[box->count++] = *(root->app);
        }
        root = deleteNode(root, root->app->name);
    }

    return root;
}

void displayBox (Box* box){
    if(box->count == 0){
        printf("No apples in the box.\n");
        return;
    }

    for (int i = 0; i < box->count; i++) {
        printf("%s (Color: %s, Size: %d cm, Hardness: %d, Ripe: %s)\n",
               box->apples[i].name,
               box->apples[i].color,
               box->apples[i].size_cm,
               box->apples[i].hardness,
               box->apples[i].ripe ? "Yes" : "No");
    }
}