#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>

#define S 100000
#define THREADS 10

static int min = 0;
static int max = 99;

typedef struct Arr{
    int array[S];
    int size;
    int ID;
    int ID2;
    int sum[5];
    double probability;
    int firstPlayerDoubleScores;
    int secondPlayerDoubleScores;
}Arr;

void generateRandomInts(Arr* array);
void writeOutArr(Arr* array);
void searchForPlayerOneDoubleGoals(Arr* array);
void searchForPlayerTwoDoubleGoals(Arr* array);

int main()
{
    Arr array;
    array.size = S;

    int firstPlayerDoubleScores;
    int secondPlayerDoubleScores;

    pthread_t calcChancesOne[THREADS];
    pthread_t calcChancesTwo[THREADS];

    clock_t begin = clock();
    srand(time(NULL));
    for(int i = 0; i<S; i++){
        array.array[i] = (rand() % (max - min + 1)) + min;
        printf("%02d ", array.array[i]);
    }

    for(int i = 0; i < THREADS; i++){

        pthread_create(&calcChancesOne[i],NULL,searchForPlayerOneDoubleGoals,&array);
        pthread_join(calcChancesOne[i],NULL);
    }
    for(int i = 0; i < THREADS; i++){
        pthread_join(calcChancesTwo[i],NULL);
    }
    printf("\n\nFirst player scored twice in a row: %d", array.firstPlayerDoubleScores);
    printf("\nChances that the first player scores twice in a row:%.3lf", array.probability);
    printf("\nPlayer one has %.2lf%% to win from %d attempts", array.probability*100, S);

    array.probability = 0;
    for(int i = 0; i < THREADS; i++){
        pthread_create(&calcChancesTwo[i], NULL, searchForPlayerTwoDoubleGoals, &array);
    }
    for(int i = 0; i < THREADS;i++){
        pthread_join(calcChancesTwo[i], NULL);
    }

    printf("\n\nSecond player scored twice in a row: %d", array.secondPlayerDoubleScores);
    printf("\nChances that the second player scores twice in a row:%.3lf", array.probability);
    printf("\nPlayer two has %.2lf%% to win from %d attempts", array.probability*100, S);
    clock_t end = clock();

    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("\n\nTimes spent with the calculations:%.3f", time_spent);



return 0;
}

void searchForPlayerTwoDoubleGoals(Arr* array){

    array->secondPlayerDoubleScores = 0;

    int min = 0;
    int max = S/THREADS;
    int i;

    array->ID2 = 0;
    if(array->ID2 == 0){
        for(i = min; i < max; i++){
            //player one has 0,50% chance to score twice
            if(array->array[i] == 44 || array->array[i] == 55 || array->array[i] == 66 || array->array[i] == 77 || array->array[i] == 88){
                array->secondPlayerDoubleScores++;
            }
        }
    }

    min += S/THREADS;
    max += S/THREADS;

    array->ID2 = 1;
    if(array->ID2 == 1){
        for(i = min; i < max; i++){
            //player one has 0,50% chance to score twice
            if(array->array[i] == 44 || array->array[i] == 55 || array->array[i] == 66 || array->array[i] == 77 || array->array[i] == 88){
                array->secondPlayerDoubleScores++;
            }
        }
    }

    min += S/THREADS;
    max += S/THREADS;

    array->ID2 = 2;

    if(array->ID2 == 2){
        for(i = min; i < max; i++){
            //player one has 0,50% chance to score twice
            if(array->array[i] == 44 || array->array[i] == 55 || array->array[i] == 66 || array->array[i] == 77 || array->array[i] == 88){
                array->secondPlayerDoubleScores++;
            }
        }
    }

    min += S/THREADS;
    max += S/THREADS;

    array->ID2 = 3;

    if(array->ID2 == 3){
        for(int i = min; i < max; i++){
            //player one has 0,50% chance to score twice
            if(array->array[i] == 44 || array->array[i] == 55 || array->array[i] == 66 || array->array[i] == 77 || array->array[i] == 88){
                array->secondPlayerDoubleScores++;
            }
        }
    }

    min += S/THREADS;
    max += S/THREADS;

    array->ID2 = 4;
    if(array->ID2 == 4){
        for(i = min; i < max; i++){
            //player one has 0,50% chance to score twice
            if(array->array[i] == 44 || array->array[i] == 55 || array->array[i] == 66 || array->array[i] == 77 || array->array[i] == 88){
                array->secondPlayerDoubleScores++;
            }
        }
    }

    min += S/THREADS;
    max += S/THREADS;

    array->ID2 = 5;

    if(array->ID2 == 5){
        for(i = min; i < max; i++){
            //player one has 0,50% chance to score twice
            if(array->array[i] == 44 || array->array[i] == 55 || array->array[i] == 66 || array->array[i] == 77 || array->array[i] == 88){
                array->secondPlayerDoubleScores++;
            }
        }
    }

    min += S/THREADS;
    max += S/THREADS;

    array->ID2 = 6;
    if(array->ID2 == 6){
        for(i = min; i < max; i++){
            //player one has 0,50% chance to score twice
            if(array->array[i] == 44 || array->array[i] == 55 || array->array[i] == 66 || array->array[i] == 77 || array->array[i] == 88){
                array->secondPlayerDoubleScores++;
            }
        }
    }

    min += S/THREADS;
    max += S/THREADS;

    array->ID2 = 7;

    if(array->ID2 == 7){
        for(i = min; i < max; i++){
            //player one has 0,50% chance to score twice
            if(array->array[i] == 44 || array->array[i] == 55 || array->array[i] == 66 || array->array[i] == 77 || array->array[i] == 88){
                array->secondPlayerDoubleScores++;
            }
        }
    }

    min += S/THREADS;
    max += S/THREADS;

    array->ID2 = 8;
    if(array->ID2 == 8){
        for(i = min; i < max; i++){
            //player one has 0,50% chance to score twice
            if(array->array[i] == 44 || array->array[i] == 55 || array->array[i] == 66 || array->array[i] == 77 || array->array[i] == 88){
                array->secondPlayerDoubleScores++;
            }
        }
    }

    min += S/THREADS;
    max += S/THREADS;

    array->ID2 = 9;

    if(array->ID2 == 9){
        for(i = min; i < max; i++){
            //player one has 0,50% chance to score twice
            if(array->array[i] == 44 || array->array[i] == 55 || array->array[i] == 66 || array->array[i] == 77 || array->array[i] == 88){
                array->secondPlayerDoubleScores++;
            }
        }
    }

    //Chances that player two scores twice from 500 attempts
    array->probability = (double)array->secondPlayerDoubleScores/S;

}

void searchForPlayerOneDoubleGoals(Arr* array){

    array->firstPlayerDoubleScores = 0;

    int min = 0;
    int max = S/THREADS;
    int i;
    //counting how many times  player one scored twice
    array->ID = 0;
    if(array->ID == 0){
        for(i = min; i < max; i++){
            //player one has 0,40% chance to score twice
            if(array->array[i] == 00 || array->array[i] == 11 || array->array[i] == 22 || array->array[i] == 33){
                array->firstPlayerDoubleScores++;
            }
        }
    }

    min += S/THREADS;
    max += S/THREADS;

    array->ID = 1;
    if(array->ID == 1){
        for(i = min; i < max; i++){
            //player one has 0,40% chance to score twice
            if(array->array[i] == 00 || array->array[i] == 11 || array->array[i] == 22 || array->array[i] == 33){
                array->firstPlayerDoubleScores++;
            }
        }
    }

    min += S/THREADS;
    max += S/THREADS;

    array->ID = 2;

    if(array->ID == 2){
        for(i = min; i < max; i++){
            //player one has 0,40% chance to score twice
            if(array->array[i] == 00 || array->array[i] == 11 || array->array[i] == 22 || array->array[i] == 33){
                array->firstPlayerDoubleScores++;
            }
        }
    }

    min += S/THREADS;
    max += S/THREADS;

    array->ID = 3;

    if(array->ID == 3){
        for(i = min; i < max; i++){
            //player one has 0,40% chance to score twice
            if(array->array[i] == 00 || array->array[i] == 11 || array->array[i] == 22 || array->array[i] == 33){
                array->firstPlayerDoubleScores++;
            }
        }
    }

    min += S/THREADS;
    max += S/THREADS;

    array->ID = 4;
    if(array->ID == 4){
        for(i = min; i < max; i++){
            //player one has 0,40% chance to score twice
            if(array->array[i] == 00 || array->array[i] == 11 || array->array[i] == 22 || array->array[i] == 33){
                array->firstPlayerDoubleScores++;
            }
        }
    }

    min += S/THREADS;
    max += S/THREADS;

    array->ID = 5;

    if(array->ID == 5){
        for(i = min; i < max; i++){
            //player one has 0,40% chance to score twice
            if(array->array[i] == 00 || array->array[i] == 11 || array->array[i] == 22 || array->array[i] == 33){
                array->firstPlayerDoubleScores++;
            }
        }
    }

    min += S/THREADS;
    max += S/THREADS;

    array->ID = 6;
    if(array->ID == 6){
        for(i = min; i < max; i++){
            //player one has 0,40% chance to score twice
            if(array->array[i] == 00 || array->array[i] == 11 || array->array[i] == 22 || array->array[i] == 33){
                array->firstPlayerDoubleScores++;
            }
        }
    }
    min += S/THREADS;
    max += S/THREADS;

    array->ID = 7;

    if(array->ID == 7){
        for(i = min; i < max; i++){
            //player one has 0,40% chance to score twice
            if(array->array[i] == 00 || array->array[i] == 11 || array->array[i] == 22 || array->array[i] == 33){
                array->firstPlayerDoubleScores++;
            }
        }
    }

    min += S/THREADS;
    max += S/THREADS;

    array->ID = 8;
    if(array->ID == 8){
        for(i = min; i < max; i++){
            //player one has 0,40% chance to score twice
            if(array->array[i] == 00 || array->array[i] == 11 || array->array[i] == 22 || array->array[i] == 33){
                array->firstPlayerDoubleScores++;
            }
        }
    }
    min += S/THREADS;
    max += S/THREADS;

    array->ID = 9;

    if(array->ID == 9){
        for(i = min; i < max; i++){
            //player one has 0,40% chance to score twice
            if(array->array[i] == 00 || array->array[i] == 11 || array->array[i] == 22 || array->array[i] == 33){
                array->firstPlayerDoubleScores++;
            }
        }
    }

    //Chances that player one scores twice from 500 attempts
    array->probability = (double)array->firstPlayerDoubleScores/S;
}


