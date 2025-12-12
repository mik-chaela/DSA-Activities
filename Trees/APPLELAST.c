
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
//BST deleteNode(BST root, const char *key);
BST deleteNode(BST root, const char *key);

BST makeAppleTree(Apple apples[], int n); 	// Exam #3 = Make Apple Tree 


void inorderTraversal(BST root);
void preorderTraversal(BST root);
		
BST harvestRecursive(BST root, Box *box);   // Exam #1 = Harvest ripe then put in box
BST harvestRotten(BST root, Box *box);		// Exam #2 = Harvest rotten then put in box

void initBox(Box *box, int capacity);


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

    // Harvest rotten apples
    printf("\n\nRotten Apples:\n");
    harvestRotten(tree, &box);

    return 0;
}


BST makeAppleTree(Apple apples[], int n){  	// Exam #3 = Make Apple Tree 

	BST tree = NULL;
	int a;
	
	for(a=0;a<n;a++){
		tree = insertBST(tree,&apples[a]);
	}
	return tree;
}


BST createNode(Apple *a){
	BST root =malloc(sizeof(Node));
	if(root==NULL)return NULL;
	root->app =malloc(sizeof(Apple));
	
	root->LC = NULL;
	root->RC = NULL;
	
	strcpy(root->app->name,a->name);
	strcpy(root->app->color,a->color);
	root->app->hardness = a->hardness;
	root->app->size_cm = a->size_cm;
	root->app->ripe = a->ripe;
	
	return root;
}



BST insertBST(BST root, Apple *a){
	
	if(root==NULL){
		return createNode(a);
	}
	
	if(a->size_cm < root->app->size_cm){
		root->LC = insertBST(root->LC,a); 
	}else if(a->size_cm > root->app->size_cm){
		root->RC = insertBST(root->RC,a); 
	}else{
		if(strcmp(a->name,root->app->name)<0){
		root->LC = insertBST(root->LC,a); 
		}else if(strcmp(a->name,root->app->name)>0){
		root->RC = insertBST(root->RC,a); 
		}else{
			printf("Already exists");
		}
	}
	return root;
}
//BST deleteNode(BST root, const char *key);
BST deleteNode(BST root, const char *key) { // key = name
    if (root == NULL) return NULL;

    if (strcmp(key, root->app->name) < 0) {
        root->LC = deleteNode(root->LC, key);
    } else if (strcmp(key, root->app->name) > 0) {
        root->RC = deleteNode(root->RC, key);
    } else {
        // Node to delete found
        if (root->LC == NULL && root->RC == NULL) {
            free(root->app);
            free(root);
            return NULL;
        } else if (root->LC == NULL) {
            BST temp = root->RC;
            free(root->app);
            free(root);
            return temp;
        } else if (root->RC == NULL) {
            BST temp = root->LC;
            free(root->app);
            free(root);
            return temp;
        } else {
            // Node with two children
            BST succ = root->RC;
            while (succ->LC != NULL) succ = succ->LC;

            // Copy successor data
            strcpy(root->app->name, succ->app->name);
            strcpy(root->app->color, succ->app->color);
            root->app->hardness = succ->app->hardness;
            root->app->size_cm = succ->app->size_cm;
            root->app->ripe = succ->app->ripe;

            // -----------------------------
            // Changed: delete the successor node by key
            root->RC=deleteNode(root->RC,succ->app->name); // **key passed**
        }
    }
    return root;
}




void inorderTraversal(BST root){
	Node *stack[100];
	int top =-1;
	
	Node *curr = root;
	while(curr!=NULL || top!=-1){
		while(curr!=NULL){
			stack[++top]=curr;
			curr = curr->LC;
		}
		curr = stack[top--];
		printf("%s, %s, %d, %d ,%d\n",curr->app->name,
							curr->app->color,curr->app->hardness,
							curr->app->size_cm,curr->app->ripe);
		curr = curr->RC;
	}
}


void preorderTraversal(BST root){
	Node *stack[100];
	int top=-1;
	stack[++top]=root;
	while(top!=-1){
		Node *curr = stack[top--];
		printf("%s, %s, %d, %d ,%d\n",curr->app->name,
							curr->app->color,curr->app->hardness,
							curr->app->size_cm,curr->app->ripe);
		if(curr->RC!=NULL){
			stack[++top]= curr->RC;
		}
		if(curr->LC!=NULL){
			stack[++top]= curr->LC;
		}
	}
}
		
BST harvestRecursive(BST root, Box *box){   // Exam #1 = Harvest ripe then put in box
	if(root==NULL)return NULL;
		
	root->LC = harvestRecursive(root->LC,box);
	Apple *app = root->app;
	int criteria = 0;
	
	if(strcmp(app->color,"red")==0 && app->hardness > 6
	 && app->size_cm > 7 && app->ripe){
		criteria = 1;
	}
	if(criteria == 1){
		if(box->count <box->capacity){
			box->apples[box->count]= *app;
			printf("%s is Ripe\n",app->name);
			box->count++;
		}
		root = deleteNode(root,app->name);
		return harvestRecursive(root,box);
	}
	root->RC=harvestRecursive(root->RC,box);
	return root;
}



BST harvestRotten(BST root, Box *box){ 	// Exam #2 = Harvest rotten then put in box
	if(root==NULL)return NULL;
	
	root->LC = harvestRotten(root->LC,box);
	Apple *app = root->app;
	int criteria = 0;
	
	if(app->ripe==0){
		criteria = 1;
	}
	if(criteria==1){
		if(box->count < box->capacity){
			box->apples[box->count]= *app;
			printf("%s is Rotten\n",app->name);
			box->count++;
		}
		root = deleteNode(root,app->name);
		return harvestRotten(root,box);
	}
	root->RC = harvestRotten(root->RC,box);
	return root;
}

void initBox(Box *box, int capacity){
	box->count=0;
	box->capacity= capacity;
}
