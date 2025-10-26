#include <stdio.h>
#include <ctype.h>

int hash_lastname(const char *lastname) {
    if (lastname == NULL || lastname[0] == '\0')
        return -1;
    char first = toupper(lastname[0]);
    if (first < 'A' || first > 'Z')
        return -1; 
    return first - 'A'; 
}

int main() {
    char lastname[100];
    printf("Enter last name: ");
    scanf("%99s", lastname);

    int hash = hash_lastname(lastname);
    if (hash >= 0)
        printf("Hash index for last name: %d\n", hash);
    else
        printf("Invalid last name input.\n");

    return 0;
}
