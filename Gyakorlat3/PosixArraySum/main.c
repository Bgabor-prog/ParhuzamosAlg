#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>

#define THREADS 2


typedef struct Arr{
    int array[10];
    int size;
    int ID;
    int sum[2];
}Arr;

void arraySum(Arr* array);

int main()
{
    Arr array;
    array.size = 10;

    printf("Tomb elemei:\n");
    srand(time(NULL));
    for(int i = 0;i<array.size;i++){
        array.array[i] = rand() % 10 + 1;
        printf("%d ",array.array[i]);
    }

    //szál létrehozása
    pthread_t thread[THREADS];
    printf("\n.:A szalak kezdik a szamitast:.");
    for(int i = 0;i<THREADS;i++){
        pthread_create(&thread[i],NULL,arraySum,&array);
    }

    for(int i = 0;i<THREADS;i++){
        pthread_join(thread[i],NULL);
    }

    //a megfelezett tömb eleminek összegének összeadása
    printf("\nTomb elemeinek osszege: %d",array.sum[0]+array.sum[1]);

    return 0;
}

//ID alapján felosztjuk a tömböt majd számoljuk az összeget az elfelezett részeknek
void arraySum(Arr* array){
    array->sum[0] = 0;
    array->sum[1] = 0;
    int size = 10;

    array->ID = 0;
    if(array->ID == 0){
        for(int i = 0;i<size/2;i++){
            array->sum[0]+=array->array[i];
        }
    array->ID = 1;
    }
    if(array->ID == 1){
        for(int i = size/2;i<size;i++){
            array->sum[1]+=array->array[i];
        }
    }
}
