 #include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <Windows.h>

int genRandArray(int lower,int upper);
int SetArraySize();
void UploadArray(int array[],int size,int lower,int upper);
bool DuplicateElement();
double setChanceForDupl(double upper);
void UniqueArray(int array[],int size);

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
    UniqueArray(Array,m);

    return 0;
}

void UniqueArray(int array[],int size){
    int db = 0;
    bool unique = false;
    bool notunique = false;
    for(int i=0;i<size;i++){
        for(int j = i+1;j<size-1;j++){
             if (i != j) {
                if (array[i] == array[j]) {
                     notunique = true;
                     break;
                }
                unique = true;
            }
        }
    }
    if(unique && !notunique){
        printf("Minden elem egyedi!\n");
    }else if(notunique){
        printf("Talaltam azonost!\n");
    }
}


void UploadArray(int array[],int size,int lower,int upper){
    bool decide = false;
    srand((unsigned int)time(NULL));
    int max = 1;
    for(int i = 0;i<size;i++){
    double chance = (max - 0) * (double)rand() / RAND_MAX + 0;
        array[i] = (rand() % (upper-lower + 1)) + lower;
        if(chance >= 0.5){
            printf("Duplikalas %d.helyen\n",i+1);
            array[i+1]=array[i];
            i++;
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
