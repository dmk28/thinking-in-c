#include <stdio.h>
#include <stdlib.h>
#include <time.h>
typedef struct {
    int difficulty;
    int value1;
    int value2;
    int operation;
    int result;
} Calculate;


void playGame();

void showInfo(Calculate calc);
int sum(int response, Calculate calc);
int subtraction(int response, Calculate calc);
int multiplying(int response, Calculate calc);
int points = 0;


int main() {


   srand(time(NULL));
   playGame();
   return 0;
}


void playGame() {

    Calculate calc;
    int difficulty;

    printf("Inform the difficulty level [1, 2, 3 or 4]\n");
    scanf("%d", &difficulty);
    getchar();
    calc.difficulty = difficulty;
    calc.operation = rand() % 3;

    if (calc.difficulty == 1) {
        calc.value1 = rand() % 11;
        calc.value2 = rand() % 11;

    } else if (calc.difficulty == 2) {
        calc.value1 = rand() % 101;
        calc.value2 = rand() % 101;
    } else if (calc.difficulty == 3) {
        calc.value1 = rand() % 1001;
        calc.value2 = rand() % 1001;

    } else if (calc.difficulty == 4) {
        calc.value1 = rand() % 10001;
        calc.value2 = rand() % 10001;
    } else {
        printf("Ultra level engaged");
        calc.difficulty = 6;
        calc.value1 = rand() %  1000001;
        calc.value2 = rand() % 1000001;
    }

    int response;
    printf("\nInform result for the following operation: \n");

    if (calc.operation == 0) {
        printf("%d + %d", calc.value1, calc.value2);
        scanf("%d", &response);
        getchar();

        if (sum(response, calc)) {
            points = points + 1 * calc.difficulty;
            printf("\nYou scored %d point(s)", points);
        }
    }

    else if (calc.operation == 1) {
        printf("%d - %d = ?", calc.value1, calc.value2);
        scanf("%d", &response);
        getchar();
        if (subtraction(response, calc)) 
        {
            points = points + 1 * calc.difficulty;
            printf("You scored %d point(s)", points);
        }

      }
    else if (calc.operation == 2) {
        printf("%d * %d = ?", calc.value1, calc.value2);
        scanf("%d", &response);

     if (multiplying(response, calc)) 
        {
                points = points + 1 * calc.difficulty;
                printf("You scored %d point(s)", points);
        }


    }
        
    else {
        printf("Unknown choice:  %d", calc.operation);

    }
  
        printf("\nDo you wish to continue playing the game? 1 - Yes, 0 - No\n");
        int contGame;
        scanf("%d", &contGame);
        getchar();
        if (contGame == 1) {
            playGame();
        } else {
            printf("\nGoodbye, then!\n");
            printf("Your Score: %d points", points);
            exit(0);
        }
}

void showInfo(Calculate calc) {
    char option[25];

  if (calc.operation == 0) {
    sprintf(option, "Adding");
  } else if (calc.operation == 1) {
    sprintf(option, "Subtracting");
  } else if (calc.operation == 2) {
    sprintf(option, "Multiplying");
  } else {
    sprintf(option, "Unknown.");
  }

  printf("Valor 1:  %d\n, Valor 2:  %d\n, Diff:  %d\n, Operation:  %s\n", calc.value1, calc.value2, calc.difficulty, calc.operation);
}
    

int sum(int response, Calculate calc) {

    int resultado = calc.value1 + calc.value2;
    calc.result = resultado;

    int correct = 0;

    if (response == calc.result) {
        printf("Right answer\n"); 
        correct = 1;}
    else {
        printf("Wrong answer"); 
        correct = 0;
    }

    printf("%d + %d = %d", calc.value1, calc.value2, calc.result);
    return correct;
}

int subtraction(int response, Calculate calc) {

    int result = calc.value1 - calc.value2;
    calc.result = result;
    int correct = 0;

    if (response == calc.result) {
        printf("Right answer!\n");
        correct = 1;
        
    } else {
        printf("Wrong answer\n");
        correct = 0;
        
    }

    printf("%d + %d = %d", calc.value1, calc.value2, calc.result);
    return correct;

}

int multiplying(int response, Calculate calc) {

    int result = calc.value1 * calc.value2;
    calc.result = result;
    int correct = 0;

    if (response == calc.result) {
        printf("Right answer!\n");
        correct = 1;
        
    } else {
        printf("Wrong answer\n");
        correct = 0;
        
    }
    printf("%d * %d = %d", calc.value1, calc.value2, calc.result);
    return correct;

}