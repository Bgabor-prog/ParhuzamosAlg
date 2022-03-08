#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <time.h>
#include <Windows.h>

#define THREADS 10

typedef struct Limits{
    int low ;
    int up ;
}Limits;

void primNum(Limits* lim);
void Array(int size);
int main()
{
    pthread_t prime[THREADS];
    pthread_t primeHundred[THREADS];

    Limits limit;
    limit.low = 0;
    limit.up = 10;

    printf(".:Elso fazis kezdi a szamitast:.\n");
    for(int i = 0;i<THREADS;i++){
        pthread_create(&prime[i],NULL,primNum,&limit);
        pthread_join(prime[i],NULL);
        limit.up +=10;
        limit.low += -1;
    }

    printf("\n.:Masodik fazis kezdi a szamitast:.\n");
        for(int i = 0;i<THREADS;i++){
        pthread_create(&primeHundred[i],NULL,primNum,&limit);
        pthread_join(primeHundred[i],NULL);
        limit.up +=10;
        limit.low +=-1;
    }

    printf("\n.:Kesz!:.");
    return 0;
}

void primNum(Limits* lim){
    int count;
    int i;
     while(lim->low <= lim->up)
    {
        count = 0;
        i = 2;
    while(i <= lim->low/2)
    {
      if(lim->low%i == 0)
      {
        count++;

	break;
      }
      i++;
    }

    if(count == 0 && lim->low != 1 )
    {
        printf("%d ", lim->low);
    }
    lim->low++;
  }
}
