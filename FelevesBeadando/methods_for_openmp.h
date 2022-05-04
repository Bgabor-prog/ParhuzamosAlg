#ifndef METHODS_FOR_OPENMP_H_INCLUDED
#define METHODS_FOR_OPENMP_H_INCLUDED


double searchForPlayerOneDoubleGoals(int array[], int S){

    int firstPlayerDoubleScores = 0;
    //counting how many times  player one scored twice

    #pragma omp for
    for(int i = 0;i < S;i++){
        //player one has 0,40% chance to score twice
        
        {

        if(array[i] == 00 || array[i] == 11 || array[i] == 22 || array[i] == 33){
            firstPlayerDoubleScores++;
        }
        }
    }


    //Chances that player one scores twice from 500 attempts

    double probability = (double)firstPlayerDoubleScores/S;

    printf("\n\nFirst player scored twice in a row: %d",firstPlayerDoubleScores);
    printf("\nChances that the first player scores twice in a row:%.3lf",probability);
    printf("\nPlayer one has %.2lf%% to win from %d attempts",probability*100,S);

    return firstPlayerDoubleScores;
}

double searchForPlayerTwoDoubleGoals(int array[], int S){

    int secondPlayerDoubleScores = 0;
    //counting how many times  player two scored twice

    #pragma omp for
    for(int i = 0;i < S;i++){
        //player two has 0,50% chance to score twice
        
        if(array[i] == 44 || array[i] == 55 || array[i] == 66 || array[i] == 77 || array[i] == 88){
            secondPlayerDoubleScores++;
        }
    }

    //Chances that player two scores twice from 500 attempts

    double probability = (double)secondPlayerDoubleScores/S;

    printf("\n\nSecond player scored twice in a row: %d",secondPlayerDoubleScores);
    printf("\nChances that the second player scores twice in a row:%.3lf",probability);
    printf("\nPlayer two has %.2lf%% to win from %d attempts",probability*100,S);

    return secondPlayerDoubleScores;
}

//print out the generated array elements
void writeOut(int array[], int S){
    printf("Array elements:\n");
    #pragma omp for
    for(int i = 0;i<S;i++){
       printf("%02d ",array[i]);
    }

}

//generating random numbers in to the array
void generateRandomInts(int array[],int min,int max, int S){
    srand(time(0));
    #pragma omp for
    for(int i = 0;i<S;i++){
        array[i] = (rand() % (max - min + 1)) + min;
    }


}



#endif // METHODS_FOR_OPENMP_H_INCLUDED
