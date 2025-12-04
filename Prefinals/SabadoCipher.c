#include<stdio.h>
#include<stdlib.h>

int* encodeString(char string[]){
	int* bitArray = (int*)malloc(64 * sizeof(int));
	int i, j, k = 0;

	for(i = 0; i < 8; i++){
		unsigned char ch = string[i];
		for(j = 7; j >= 0; j--){
			bitArray[k++] = (ch >> j) & 1;
		}
	}
	return bitArray;
}

short int* arrayToBitmask(int arr[]){
	short int *maskArray = (short int*)malloc(4 * sizeof(short int));
	int i, j, index = 0;

	for(i = 0; i < 4; i++){
		short int value = 0;
		for(j = 0; j < 16; j++){
			value = (value << i) | arr[index++];
		}
		maskArray[i] = value;
	}
	return maskArray;
}

void displayBitPattern(int arr[]){
	for(int i = 0; i < 64; i++){
		printf("%d", arr[i]);
		if((i + 1) % 8 == 0) printf(" ");
	}
}

int main(){
    char string[9]={'E','A','R','R','I','N','G','S','\0'};
	//short int word[4]={22863,21792,16961,19524};
	//short int word[4]={17729,21074,18766,18259};
	int *arr;
	short int *word;
	int x;
	int choice;


    printf("=== Sabado Cipher ===\n\n");
	printf("Given the 8 letter word, encode the string into an array of short int\n");
	printf("%s\n\n",string);

    printf("Enter test case choice: \n");
    printf("1. Convert the characters into a bit vector Array\n");
    printf("2. Encode the String using the converted bit vector Array\n");
    printf("3. Convert and Encode while displaying both\n\nChoice: ");
    scanf("%d", &choice);

    printf("\n");
	switch(choice){
		case 1:
			arr=encodeString(string);
	        printf("Bit Pattern:\n");
			displayBitPattern(arr);
			free(arr);

			break;

		case 2:
			arr=encodeString(string);
			word=arrayToBitmask(arr);
			printf("\nEncoded Message:\n");

			for(x=0;x<4;x++){
				printf("%d ",word[x]);
			}
			free(word);
			break;

		case 3:
			arr=encodeString(string);
	        printf("Bit Pattern:\n");
			displayBitPattern(arr);
			word=arrayToBitmask(arr);
			printf("\n\nEncoded Message:\n");

			for(x=0;x<4;x++){
				printf("%d ",word[x]);
			}

			free(word);
			free(arr);

			break;

		default:
			printf("Invalid Choice");
			break;
	}

	return 0;

}