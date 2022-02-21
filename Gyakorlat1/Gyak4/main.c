#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main()
{
    int lower = 500, upper = 1000;

    srand((unsigned int)time(NULL));

    int num1 = (rand() % (upper-lower + 1)) + lower;


    double num2 = (upper - lower) * ((double)rand() / RAND_MAX) + lower;

    printf("Random num: %d\n", num1);
    printf("Random num: %.2lf", num2);

    return 0;
}
