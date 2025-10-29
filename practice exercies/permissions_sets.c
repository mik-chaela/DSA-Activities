/*
C Coding Exercise: Permission System Using Bitwise Sets
Objective: Implement a system to manage user file permissions using a short int as a set of bits.
Each bit represents one permission flag:

Bit	Permission
0	    Read
1	    Write
2	    Execute
3	    Delete
4	    Share
5–15	(reserved)

*/

#include <stdio.h>
#include <stdbool.h>

typedef unsigned short PermissionWord;

// Sets or clears a specific permission bit (0 or 1)
void grantPermission(PermissionWord* user, int permIndex);
void revokePermission(PermissionWord* user, int permIndex);

// Checks if a permission bit is set
bool hasPermission(PermissionWord user, int permIndex);

// Counts how many permissions are currently set to 1
int countPermissions(PermissionWord user);

// Prints all permission bits as binary (from bit 9 to bit 0)
void printPermissions(PermissionWord user);

// Set operations
PermissionWord unionPermissions(PermissionWord a, PermissionWord b);
PermissionWord intersectPermissions(PermissionWord a, PermissionWord b);
PermissionWord differencePermissions(PermissionWord a, PermissionWord b);


int main() {
    PermissionWord alice = 0;
    PermissionWord bob = 0;

    // Grant permissions
    grantPermission(&alice, 0); // Read
    grantPermission(&alice, 1); // Write
    grantPermission(&alice, 3); // Delete

    grantPermission(&bob, 0);   // Read
    grantPermission(&bob, 2);   // Execute
    grantPermission(&bob, 4);   // Share

    printf("Alice's permissions: ");
    printPermissions(alice);

    printf("Bob's permissions:   ");
    printPermissions(bob);

    printf("\nAlice has %d permissions\n", countPermissions(alice));
    printf("Bob has %d permissions\n\n", countPermissions(bob));

    printf("Common permissions: ");
    printPermissions(intersectPermissions(alice, bob));

    printf("All permissions:    ");
    printPermissions(unionPermissions(alice, bob));

    printf("Alice-only perms:   ");
    printPermissions(differencePermissions(alice, bob));

    // Check specific permission
    printf("\nBob has write permission? %s\n",
           hasPermission(bob, 1) ? "Yes" : "No");

    printf("Alice has delete permission? %s\n",
           hasPermission(alice, 3) ? "Yes" : "No");

    return 0;
}

// Sets the bit at permIndex to 1
void grantPermission(PermissionWord* user, int permIndex) {
    // TODO: Implement bitwise OR operation
    *user |= permIndex;
    
}

// Clears the bit at permIndex (sets to 0)
void revokePermission(PermissionWord* user, int permIndex) {
    // TODO: Implement bitwise AND with NOT mask
    *user &= ~permIndex;
}

// Returns true if the bit at permIndex is 1
bool hasPermission(PermissionWord user, int permIndex) {
    // TODO: Implement bitwise AND check
    return false;
}

// Counts number of 1 bits (permissions granted)
int countPermissions(PermissionWord user) {
    // TODO: Loop and count bits set to 1
    return 0;
}

// Prints all 10 bits (from bit 9 down to bit 0)
void printPermissions(PermissionWord user) {
    // TODO: Print each bit as 0 or 1
    for(int i = 9; i >= 0; i--){
        printf("%d", (user >> i) & 1);
    }
    printf("\n");
}

// Returns bitwise OR of two PermissionWords
PermissionWord unionPermissions(PermissionWord a, PermissionWord b) {
    // TODO: Implement union
    return (a | b);
}

// Returns bitwise AND of two PermissionWords
PermissionWord intersectPermissions(PermissionWord a, PermissionWord b) {
    // TODO: Implement intersection
    return (a & b);
}

// Returns permissions that are in a but not in b
PermissionWord differencePermissions(PermissionWord a, PermissionWord b) {
    // TODO: Implement difference
    return (a & ~b);
}