#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

int genRandArray(int lower,int upper);
int SetArraySize();
void UploadArray(int array[],int size,int lower,int upper);
bool DuplicateElement();

int main()
{

    int lower = 0;
    int upper = 1000;
    int m;

    m = SetArraySize(lower,upper);

    int Array[m];
    UploadArray(Array,m,lower,upper);

    for(int i;i<m;i++){

        printf("[%d]:%d\n",i+1,Array[i]);
    }

    return 0;
}
bool DuplicateElement(){
  float lower = 0;
  float upper = 1;

  srand((unsigned int)time(NULL));
  doublr result = (upper - lower) * ((float)rand() / RAND_MAX) + lower;
    printf("%.1f\n",result);
    if(result > 0.5){
        printf("Igaz\n");
        return true;
    }else if(result < 0.5){
        printf("Hamis\n");
        return false;
    }else

    return false;
}


void UploadArray(int array[],int size,int lower,int upper){
    bool decide = false;

    decide = DuplicateElement();
    for(int i = 0;i<size;i++){
        array[i] = genRandArray(lower,upper);
        if(decide){
            array[i+1] = array[i];
        }
    }
}

int SetArraySize(){
    int size;
    printf("Mekkora legyen a tomb?\n--->");
    scanf("%d",&size);

return size;
}

int genRandArray(int lower,int upper){
return lower + rand() / (RAND_MAX / (upper - lower + 1) + 1);;
}
