#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <omp.h>
#include "methods_for_openmp.h"

int main(int argc, char **argv)
{
    int min,max,S;
    double time_spent;

    int firstPlayerDoubleScores;
    int secondPlayerDoubleScores;

    S = atoi(argv[1]);
    min = 0;
    max = 99;
    clock_t begin = clock();
    int array[S];

    omp_set_dynamic(0);
    #pragma omp parallel num_threads(1)
    {
    int numOfThreads = omp_get_num_threads();
    printf("A szalak szama: %d\n", numOfThreads);

    generateRandomInts(array, min, max, S);
    writeOut(array, S);

    firstPlayerDoubleScores = searchForPlayerOneDoubleGoals(array, S);
    secondPlayerDoubleScores = searchForPlayerTwoDoubleGoals(array, S);
    }

    clock_t end = clock();
    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;

    printf("\n\nTime spent calculating:%.2f", time_spent);
    return 0;
}
