#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>


void print_table(int T[], int n)
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
void middle_case(int T[], int n)
{
  srand(time(0));
  for (int i = 0; i < n; i++)
  {
    T[i] = rand() % 1000;
  }
}
void croissant_case(int T[], int n)
{
  for (int i = 0; i < n; i++)
  {
    T[i] = i;
  }
}
void decroissant_case(int T[], int n)
{
  for (int i = 0; i < n; i++)
  {
    T[i] = n-i;
  }
}

void swap(int *a, int *b)
{
  int t = *a;
  *a = *b;
  *b = t;
}

/* This function takes last element as pivot, places the pivot element at its correct position in sorted
  array, and places all smaller (smaller than pivot) to left of pivot and all greater elements to right
    of pivot
*/
int partition(int arr[], int low, int high)
{
  int pivot = arr[high]; // pivot
  int i = (low - 1);     // Index of smaller element

  for (int j = low; j <= high - 1; j++)
  {
    // If current element is smaller than the pivot
    if (arr[j] < pivot)
    {
      i++; // increment index of smaller element
      swap(&arr[i], &arr[j]);
    }
  }
  swap(&arr[i + 1], &arr[high]);
  return (i + 1);
}

/* The main function that implements QuickSort
arr[] --> Array to be sorted,
low --> Starting index,
high --> Ending index */
void QuickSort(int arr[], int low, int high)
{
  if (low < high)
  {
    /* pi is partitioning index, arr[p] is now
    at right place 
    pi (pivot index) */
    int pi = partition(arr, low, high);

    // Separately sort elements before
    // partition and after partition
    QuickSort(arr, low, pi - 1);
    QuickSort(arr, pi + 1, high);
  }
}




int main()
{
 clock_t t1, t2;
  float t[5]={0,0,0,0,0};
  int vals[10] = {1000/*, 4000, 6000, 8000 ,9000 ,10000 ,20000 ,30000,100000 ,200000*/};

  char lines[10][255];
  for(int k=0; k<10; k++){

  int n = vals[k];
  printf("n = %d \n",n);
  //int p[n];
  int* p = malloc(n * sizeof(int));

  for(int j=0; j<5;j++) //we test the same value of n after 5 try
  {
  croissant_case(p,n);
  //middle_case(p,n);
  //decroissant_case(p, n);
  print_table(p,n);
  t1 = clock();
   QuickSort(p,0,n-1);
  t2 = clock();
  print_table(p,n);

  t[j] = (float)(t2 - t1) / CLOCKS_PER_SEC;

   printf("\n time = %.9f \n", t[j]);
    sprintf(lines[k], "%d,%f,%f,%f,%f,%f \n", n, t[0],t[1],t[2],t[3],t[4]);

   }

  }

  FILE* fp = fopen("QuickSortWorst.txt", "w");
   for(int i=0; i<10; i++){
        fprintf(fp, lines[i]);
    }

    fclose(fp);


  return 0;
}

