#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <unistd.h>
#include<conio.h>
#include<windows.h>

void gotoxy(int x, int y) {

    printf("\033[%d;%dH", y, x);

return;
}

void unipolarNRZ(int inputSignal[], int size) {
	int i;

	printf("Unipolar NRZ Output:\n");
	printf("|");

		for (i = 0; i < size; i++) {
			if (inputSignal[i] == 1) {
        printf("| hi |");
      }
			else {
        printf("| lo |");
      }
	  }

	printf("|");
  printf("\n");

	return;
}

void polarNRZ_L(int inputSignal[], int size) {
	int i;

	printf("Polar NRZ-L Output:\n");
	printf("|");

		for (i = 0; i < size; i++) {
			if (inputSignal[i] == 1) {
        printf("| neg |");
      }
			else {
        printf("| pos |");
      }
		}

	printf("|");
  printf("\n");

	return;
}

void polarNRZ_I(int inputSignal[], int size, int initialStateHi) {
	int i;
  int currentState;

	printf("Polar NRZ-I Output (Initially %s):\n", initialStateHi ? "High" : "Low");
	printf("|");

	currentState = initialStateHi;

		for (i = 0; i < size; i++) {
			if (inputSignal[i] == 1) {
			currentState = !currentState;
				if (currentState) {
          printf("| inv & pos |");
        }
				else {
          printf("| inv & neg |");
        }
			}
      else {
				if (currentState) {
          printf("| no inv & pos |");
        }
				else {
          printf("| no inv & neg |");
        }
			}
		}

	printf("|");
  printf("\n");

	return;
}

void polarRZ(int inputSignal[], int size) {
	int i;

	printf("Polar RZ Output:\n");
	printf("|");

		for (i = 0; i < size; i++) {
			if (inputSignal[i] == 1) {
        printf("| pos RZ |");
      }
			else {
        printf("| neg RZ |");
      }
    }

	printf("|");
	printf("\n");

	return;
}

void polarBiphaseManchester(int inputSignal[], int size) {
	int i;

	printf("Polar Biphase Manchester Output:\n");
	printf("|");

		for (i = 0; i < size; i++) {
			if (inputSignal[i] == 1) {
        printf("| nTp |");
      }
			else {
        printf("| pTn |");
      }
	  }

	printf("|");
  printf("\n");

	return;
}

void polarBiphaseDiffMan(int inputSignal[], int size, int initialStateHi) {
	int i;
  int currentState;

	printf("Polar Biphase Differential Manchester Output (Initially %s):\n", initialStateHi ? "High" : "Low");
	printf("|");

	currentState = initialStateHi;

		for (i = 0; i < size; i++) {
			if (inputSignal[i + 1] == 1) {
			  currentState = !currentState;
				if (currentState) {
            printf("| nTp & no inv |");
        }
				else {
          printf("| pTn & no inv |");
        }
      }
      else if(i == size -1){
        currentState = !currentState;
        if(currentState){
          printf("| nTp |");
        }
        else{
          printf("| pTn |");
        }
      }
      else{
        if(currentState){
          printf("| pTn & inv |");
        }
    		else{
           printf("| nTp & inv |");
        }
			}
		}

	printf("|");
  printf("\n");

	return;
}

void bipolarAMI(int inputSignal[], int size) {
  int i;
  int lastPolar;

  printf("\nBipolar AMI Output:\n");

  lastPolar = 1;

    for (i = 0; i < size; i++) {
      if (inputSignal[i] == 1) {
        if (lastPolar == 1) {
          printf("| neg |");
          lastPolar = -1;

        }
        else {
          printf("| pos |");
          lastPolar = 1;
        }
      }
      else {
        printf("| zero |");
      }
    }

  printf("|");
  printf("\n");

  return;
}

void bipolarPseudoternary(int inputSignal[], int size) {
  int i;
  int lastPolar;

  printf("\nBipolar Pseudoternary Output:\n");

  lastPolar = 1;

      for (i = 0; i < size; i++) {
        if (inputSignal[i] == 0) {
          if (lastPolar == 1) {
            printf("| neg |");
            lastPolar = -1;
          }
          else {
            printf("| pos |");
            lastPolar = 1;
          }
        }
        else {
          printf("| zero |");
        }
      }

  printf("|");
  printf("\n");

  return;
}
