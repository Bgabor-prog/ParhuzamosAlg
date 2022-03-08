#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <time.h>
#include <Windows.h>

//dolgozási idõ
const int mainthsleep = 8;
const int extensionsleep = 4;

void MainthStartsWork(void* _);
void ExtWork(void* _);
void ExtStartsWork(void* _);
void MainthWork(void* _);

 //Main
int main(int argc, char* argv[])
{
printf(">>Fo szal kezdi a munkat!<<\n");
  pthread_t mainth,ext;
  printf(".:Fo szal inditasa:.\n");
  pthread_create(&mainth,NULL,MainthStartsWork,NULL);
  sleep(mainthsleep);
  printf("-Fo szal kesz!-\n");
  pthread_join(mainth, NULL);
  printf(".:Vege!:.\n\n");

printf(">>Mellek szal kezdi a munkat!<<\n");
    printf(".:Mellek szal inditasa!\n:.");
    pthread_create(&ext,NULL,ExtStartsWork,NULL);
    sleep(extensionsleep);
    printf("-Mellek szal kesz!-\n");
    pthread_join(ext,NULL);
    printf(".:Vege!:.\n");

  return 0;
}
//mellek szal elinditja a foszalat
void ExtStartsWork(void* _){
    pthread_t mainth;
    printf("Fo szal inditasa!\n");
    pthread_create(&mainth,NULL,MainthWork,NULL);
    pthread_join(mainth,NULL);
}
void MainthWork(void* _){
    sleep(mainthsleep);
    printf("-Foszal kesz!-\n");
}


//foszal elinditja a mellek szalat
void MainthStartsWork(void* _){
    pthread_t ext;
    printf(".:Mellek szal inditasa:.\n");
    pthread_create(&ext,NULL,ExtWork,NULL);
    pthread_join(ext, NULL);
}

//mellekszal dolgozik
void ExtWork(void* _){
    sleep(extensionsleep);
    printf("-Mellek szal kesz!-\n");
}
