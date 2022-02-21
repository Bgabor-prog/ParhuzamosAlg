#include <stdio.h>
#include <stdlib.h>
#define M 10

void arrLoad (int Array[],int size);
void arrWrite (int Array[]);
void fileWrite (int Array[]);
void fileRead (char* filename);

void arrLoadFloat (float Array[],int size);
void arrWriteFloat (float Array[]);
void fileWriteFloat (float Array[]);

void arrLoadLong (long Array[],int size);
void arrWriteLong (long Array[]);
void fileWriteLong (long Array[]);

long int findSize(char name[]);


int main()
{
    int array[M];
    float arrayF[M];
    long arrayL[M];

    arrLoad(array,M);
    arrWrite(array);
    fileWrite(array);
    fileRead("Test.txt");

    arrLoadFloat(arrayF,M);
    arrWriteFloat(arrayF);
    fileWriteFloat(arrayF);
    fileRead("TestFloat.txt");

    arrLoadLong(arrayL,M);
    arrWriteLong(arrayL);
    fileWriteLong(arrayL);
    fileRead("TestLong.txt");




    char file_name[] = {"Test.txt"};
    long int res = findSize(file_name);
    if (res != -1)
        printf("Size of the file is %ld bytes \n", res);


return 0;
}

long int findSize(char name[])
{

    FILE* fp = fopen(name, "r");

    if (fp == NULL) {
        printf("File Not Found!\n");
        return -1;
    }
    fseek(fp, 0L, SEEK_END);

    long int res = ftell(fp);

    fclose(fp);

    return res;
}

void fileWriteLong (long Array[]){
    FILE *fptr;

    fptr = fopen("TestLong.txt","w");

    if(fptr == NULL)
    {
        printf("Error!");
        exit(1);
    }

    for(int i = 0; i < M;i++){
        fprintf(fptr," %ld |",Array[i]);
    }

    fclose(fptr);
}

void arrLoadLong (long Array[],int size){
    int i;

    printf("\nToltse fel a tombot tetszoleges nagy egesz szammal!\n");
    for(i=0;i<M;i++){
        printf("\n--->:");
        scanf("%ld",&Array[i]);
}

}
void arrWriteLong (long Array[]){

    printf("Tomb elemek:\n");
    for(int i=0;i<M;i++){
        printf("%ld | ",Array[i]);
    }
    printf("\n----------------------------------");

}

void fileWriteFloat (float Array[]){
    FILE *fptr;

    fptr = fopen("TestFloat.txt","w");

    if(fptr == NULL)
    {
        printf("Error!");
        exit(1);
    }

    for(int i = 0; i < M;i++){
        fprintf(fptr," %.2f |",Array[i]);
    }

    fclose(fptr);
}

void arrWriteFloat (float Array[]){

    printf("Tomb elemek:\n");
    for(int i=0;i<M;i++){
        printf("%.2f | ",Array[i]);
    }
    printf("\n----------------------------------");

}

void arrLoadFloat (float Array[],int size){
    int i;

    printf("\nToltse fel a tombot tetszoleges valos szammal!\n");
    for(i=0;i<M;i++){
        printf("\n--->:");
        scanf("%f",&Array[i]);

    }
}

void fileRead (char* filename){

    FILE * fPointer;
    fPointer = fopen(filename,"r");
    int ch;
     if (fPointer == NULL)
    {
      perror("Error while opening the file.\n");
        exit(EXIT_FAILURE);
    }
    printf("\nFile ertekei:\n");
    while((ch = fgetc(fPointer)) != EOF)
    printf("%c", ch);

    fclose(fPointer);

}

void fileWrite (int Array[]){
    FILE *fptr;

    fptr = fopen("Test.txt","w");

    if(fptr == NULL)
    {
        printf("Error!");
        exit(1);
    }

    for(int i = 0; i < M;i++){
        fprintf(fptr," %d |",Array[i]);
    }

    fclose(fptr);
}
void arrLoad (int Array[],int size){
    int i;

    printf("Toltse fel a tombot tetszoleges egesz szammal!\n");
    for(i=0;i<M;i++){
        printf("\n--->:");
        scanf("%d",&Array[i]);
}

}
void arrWrite (int Array[]){

    printf("Tomb elemek:\n");
    for(int i=0;i<M;i++){
        printf("%d | ",Array[i]);
    }
    printf("\n----------------------------------");

}
