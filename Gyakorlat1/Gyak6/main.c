#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{


    int alsoHatar = 1;
    int felsoHatar = 30;
    int bekertNum;

    srand(time(NULL));
    int randNum = (rand() % (felsoHatar - alsoHatar + 1)) + alsoHatar;
    int randNum1 = (rand() % (felsoHatar - alsoHatar + 1)) + alsoHatar;

    int numOsszeg = randNum + randNum1;

    clock_t begin = clock();
    printf("Mennyi a %d es %d osszege?\n",randNum,randNum1);
    scanf("%d",&bekertNum);

    if(numOsszeg != bekertNum){
        printf("Hibas megoldas!\n");
    }else{
        printf("Helyes megoldas!\n");

    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("Megoldashoz szukseges ido %.2f\n", time_spent);
    }

    printf("A megoldas %d\n",numOsszeg);

    return 0;
}
