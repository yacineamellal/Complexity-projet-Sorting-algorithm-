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
//Write the key function (I/ x, i: integer): integer; which returns either the units
//digit, or the tens digit, or the hundreds digit...
int key(int i, int j){

    int p1 = pow(10, j+1);
    int p2 = p1/10;
    int t = ((i % p1) - (i % p2))/p2;
    return t;
}

//Write the function SortAux(T, n, i) which reorders the elements of A such that:
//key(A[1], i) ≤ key(A[2], i) ≤ . . . ≤ key(A[n],i). SortAux must execute in linear time
//depending on the size n of the array.

void SortAux(int* T, int n, int i){
    int cles[10];
    int *resultat = (int*)malloc(n * sizeof(int));

    for(int k=0; k<10; k++) cles[k] = 0;

    for(int j=0; j<n; j++){
        cles[key(T[j], i)]++;
    }

    for(int k=1; k<10; k++) cles[k] += cles[k-1];

    for(int j=n-1; j>=0; j--){
        resultat[cles[key(T[j], i)] - 1] = T[j];
        cles[key(T[j], i)]--;
    }

    for(int j=0; j<n; j++) T[j] = resultat[j];

}

//Using the SortAux procedure, write the function RadixSort(T, n, k) to sort by distribution the array A.

void RadixSort(int* T, int n, int k){
    for(int i=0; i<k; i++){
        SortAux(T, n, i);
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

  for(int j=0; j<5;j++) //we test the same value of n after 5 try
  {
  random_case(p, n);
  t1 = clock();
   RadixSort(p,n,6);
  t2 = clock();

  t[j] = (float)(t2 - t1) / CLOCKS_PER_SEC;

  printf("\n time = %.9f \n", t[j]);
   sprintf(lines[k], "%d,%f,%f,%f,%f,%f \n", n, t[0],t[1],t[2],t[3],t[4]);
   }
  }
    FILE* fp = fopen("RadixSort_WorstResultats.txt", "w");
   for(int i=0; i<10; i++){
        fprintf(fp , lines[i]);
    }

    fclose(fp);


  return 0;
}

