#include <stdio.h>
#include <time.h>


struct schedulingData {
    char time[10];
    char date[50];
    char appointment[110];
} schedule[2];


int main() {

    for (int i = 0; i < 2; i++) {

    printf("Informe a hora do compromisso");
        fgets(schedule[i].time, 10, stdin);
        printf("Informe a data do compromisso");
        fgets(schedule[i].date, 50, stdin);
        printf("Informe o nome do compromisso");
        fgets(schedule[i].appointment, 110, stdin);

    }
    
    if (schedule != NULL) {
        for (int i = 0; i < 2; i++) {
            printf("O compromisso foi marcado para as %s no dia %s. Detalhes do compromisso: %s", schedule[i].time, schedule[i].date, schedule[i].appointment);
        }
          
    }
  

    return 0;




}