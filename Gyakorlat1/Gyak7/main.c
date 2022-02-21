#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{

    int i, a = 1, count;

    clock_t begin = clock();
    while(a <= 10000)
    {
        count = 0;
        i = 2;
    while(i <= a/2)
    {
      if(a%i == 0)
      {
        count++;

	break;
      }
      i++;
    }

    if(count == 0 && a != 1 )
    {
        printf("%d ", a);
    }
    a++;
  }
    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("\nProgram futasanak ideje: %.2f\n", time_spent);


    return 0;
}
