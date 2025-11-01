#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <unistd.h>
#include<conio.h>
#include<windows.h>
#include"header.c"

int main(){
	int i;
	int n;
	int numBits;

	//gotoxy(35,11);
	printf("Enter the SIZE of the BINARY SEQUENCE: ");
	scanf("%d", &n);

	system("cls");

	numBits = n;
	int inputSignal[numBits];

//	gotoxy(45,12);
	printf("Example Binary Sequence: 1 0 1 1 ");
//	gotoxy(25, 11);
	printf("Enter the BINARY SEQUENCE ( %d is the size ): \n", n);
//	gotoxy(71,11);
		for (i = 0; i < numBits; i++) {
			scanf("%d", &inputSignal[i]);
		}

	system("cls");

	printf("\n");
	printf("Binary Sequence to be processed: ");
	for (i = 0; i < numBits; i++) {
		printf("%d ", inputSignal[i]);

	}
	printf("\n");

	printf("\n");
	unipolarNRZ(inputSignal, numBits);
	printf("\n");
	polarNRZ_L(inputSignal, numBits);
	printf("\n");
	polarNRZ_I(inputSignal, numBits, 1);
	printf("\n");
	polarNRZ_I(inputSignal, numBits, 0);
	printf("\n");
	polarRZ(inputSignal, numBits);
	printf("\n");
	polarBiphaseManchester(inputSignal, numBits);
	printf("\n");
	polarBiphaseDiffMan(inputSignal, numBits, 1);
	printf("\n");
	polarBiphaseDiffMan(inputSignal, numBits, 0);
	//printf("\n");
	bipolarAMI(inputSignal, numBits);
	//printf("\n");
	bipolarPseudoternary(inputSignal, numBits);
	//printf("\n");
	printf("\n");

return 0;

}
