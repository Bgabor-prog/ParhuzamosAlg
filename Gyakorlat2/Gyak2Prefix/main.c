#include <stdio.h>
#include <stdlib.h>

#define M 8

void writeArray(int GoalArr[],int Size);
void Crew_Prefix(int arr[],int size,int GoalArr[]);
void EREW_PREFIX(int arr[],int size,int GoalArr[]);

int main()
{
    int arr[] = {4,7,2,1,6,5,3,5};
    //int prefix[] = [4,11,13,14,20,25,28,33];
    int GoalArr[M];

    Crew_Prefix(arr,M,GoalArr);
    WriteToFile(GoalArr,M);
    EREW_PREFIX(arr,M,GoalArr);
    return 0;
}

void EREW_PREFIX(int arr[],int size,int GoalArr[]){
    int k;
    GoalArr[1]=arr[1];
    for(int i = 2;i<size;i++){
        GoalArr[i]=arr[i-1]+arr[i];
    }
    k=2;
    while(k<size){
        for(int i = k+1;i<size;i++){
            GoalArr[i] = GoalArr[i-k]+GoalArr[i];
        }
    k=2*k;
    }
    for(int i = 0;i<size;i++){
        printf("%d ",GoalArr[i]);
    }
}


void WriteToFile(int GoalArr[],int size){
    FILE *fp = fopen("Prefix.txt","w");
    for(int i=0;i<size;i++){
        fprintf(fp,"%d ",GoalArr[i]);
    }
    fclose(fp);

}
void Crew_Prefix(int arr[],int size,int GoalArr[]){

    for(int i = 0;i<size;i++){
        GoalArr[i] = arr[i] + arr[i-1];
    }
    for(int i = 0;i<size;i++){
        GoalArr[i+1] = GoalArr[i] + arr[i+1];
    }

}

void writeArray(int GoalArr[],int Size){
    for(int i = 0;i<Size;i++){
        printf("%d ",GoalArr[i]);
    }
}
