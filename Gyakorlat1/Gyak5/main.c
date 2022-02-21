#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int alsoHatar;
    int felsoHatar;
    int ok;
    char c;

    do{
        ok = 1;
        printf("Adjon meg egy also hatart(0-1000 kozott)!\n");
        if(scanf("%d",&alsoHatar) != 1 || alsoHatar < 0 || alsoHatar > 1000){
            ok = 0;
            printf("Hibas ertek!\n");

            while((c=getchar()) != '\n');

        }
    }while(!ok);

    do{
        ok = 1;
        printf("Adjon meg egy felso hatart(%d-1000 kozott)!\n",alsoHatar);
        if(scanf("%d",&felsoHatar) != 1 || felsoHatar < alsoHatar || felsoHatar > 1000){
            ok = 0;
            printf("Hibas ertek!\n");

            while((c=getchar()) != '\n');

        }
    }while(!ok);



    srand(time(NULL));
    int randNum = (rand() % (felsoHatar - alsoHatar + 1)) + alsoHatar;

    printf("A hatarok kozotti random generalt szam:%d",randNum);


    return 0;
}
