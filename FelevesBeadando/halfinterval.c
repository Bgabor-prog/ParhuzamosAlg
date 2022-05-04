#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <omp.h>
#include <time.h>
#include "methods_for_halfinterval.h"

int main(int argc, char **argv)
{

    double a,b,epsilon;
    double r;
    clock_t begin,end;
    int i;

    epsilon = atoi(argv[1]);

    begin = clock();


    for( i = -1000000; i< 0; i+=50){

         a = i;
         b = i+50;

         r = searchRoot(a, b, epsilon);
         printf("%lf\n", r);
    }

    for( i = 0; i < 1000000; i+=50){

         a = i;
         b = i+50;

         r = searchRoot(a, b, epsilon);
         printf("%lf\n", r);
    }
/*
    omp_set_dynamic(0);
    omp_set_num_threads(1);
    #pragma omp paralell
    {
        for(i = -1000000; i < 0; i+=50){

         a = i;
         b = i+50;

         r = searchRoot(a, b, epsilon);
         printf("%lf\n", r);
    }

    for(i = 0; i < 1000000; i+=50){

         a = i;
         b = i+50;

         r = searchRoot(a, b, epsilon);
         printf("%lf\n", r);
    }

    }
*/
    end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;

    printf("\n\nTime spent calculating:%.5f", time_spent);

    return 0;
}




