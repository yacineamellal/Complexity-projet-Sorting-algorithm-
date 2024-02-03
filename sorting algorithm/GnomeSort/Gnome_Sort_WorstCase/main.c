#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>
//Prints the elements of an array.
void printtable(int T[], int n)
{

  for (int i = 0; i < n; i++)
  {
    // printf("T[%d] = %d \n",i,T[i]);
    if (i != (n - 1))
    {
      printf("[%d]---", T[i]);
    }
    else
    {
      printf("[%d]", T[i]);
    }
  }
}
// Fills an array with random numbers between 0 and 999.
void random_case(int T[], int n)
{
  srand(time(0));
  for (int i = 0; i <= n; i++)
  {
    T[i] = rand() % 1000;
  }
}
// Fills an array with numbers in ascending order.
//best case
void croissant_case(int T[], int n)
{
  for (int i = 0; i <= n; i++)
  {
    T[i] = i;
  }
}
// Fills an array with numbers in descending order.
//worst case
void decroissant_case(int T[], int n)
{
  for (int i = 0; i <= n; i++)
  {
    T[i] = n-i;
  }
}


/*void gnome_sort(int *array, int size) {
    int i, tmp;
    // Iterate through the array
    for (i = 1; i < size; ) {
        // Check if the current element and the previous element are in the correct order
        if (array[i - 1] <= array[i])
            ++i;  // If in order, move to the next element
        else {
            // Swap the current and previous elements
            tmp = array[i];
            array[i] = array[i - 1];
            array[i - 1] = tmp;
            // Move back one position, unless at the beginning of the array
            --i;
            if (i == 0)
                i = 1;
        }
    }
}
*/
void gnomeSort(int arr[], int n) {
    int index = 1;

    while (index < n) {
        if (index == 0) {
            index++;
        }
        if (arr[index] >= arr[index - 1]) {
            index++;
        } else {
            int temp = arr[index];
            arr[index] = arr[index - 1];
            arr[index - 1] = temp;
            index--;
        }
    }
}
int main()
{
  clock_t t1, t2;
  float t[5]={0,0,0,0,0};
  int vals[10] = {1000, 4000, 6000, 8000 ,9000 ,10000 ,20000 ,30000,100000 ,200000};
  char lines[10][255];

  for(int k=0; k<10; k++){
  int n = vals[k];
  printf("n = %d \n",n);
  int p[n];
  for(int j=0;j<=5;j++){
  //random_case(p,n);
   decroissant_case(p, n);
   //croissant_case(p,n);
  t1 = clock();
   gnomeSort(p, n);
  t2 = clock();
  t[j] = (float)(t2 - t1) / CLOCKS_PER_SEC;

  printf("\n time = %.9f \n", t[j]);
   sprintf(lines[k], "%d,%f,%f,%f,%f,%f \n", n, t[0],t[1],t[2],t[3],t[4]);
  //}
  }
}

    FILE* fp = fopen("Gnome_sort_worstcase.txt", "w");
   for(int i=0; i<10; i++){
        fprintf(fp, lines[i]);
    }

    fclose(fp);


  return 0;
}

/*

Gnome sort

Worst case performance: O(n^2)
Best case performance: Ω(n)
Average performance: Θ(n^2)
Worst case space complexity: O(1)

*/
