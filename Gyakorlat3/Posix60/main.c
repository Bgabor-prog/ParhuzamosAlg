#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
#include <pthread.h>

const int threadNum = 60;

void ThreadWork(void* _);
int main()
{
    pthread_t threads[threadNum];

    clock_t begin = clock();
    for(int i = 0;i<threadNum;i++){
        pthread_create(&threads[i],NULL,ThreadWork,NULL);
        sleep(1);
    }
    for(int i = 0;i<threadNum;i++){
        pthread_join(threads[i],NULL);
    }
    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf(".:Vege!:.\n");
    printf("Eltelt ido: %.2lf\n",time_spent);

}
void ThreadWork(void* _){
    printf(".:Working!:.\n");
}
