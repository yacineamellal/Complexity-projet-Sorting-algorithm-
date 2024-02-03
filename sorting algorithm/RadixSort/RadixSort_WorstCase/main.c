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

//return le digit du j-eme position
int cle(int i, int j){ //i=201 , j=0

    int k1 = pow(10, j+1);//10
    int k2 = k1/10;//1

    int t = ((i % k1) - (i % k2))/k2;//((201 % 10) - (201 % 1)=

    return t;
}
//cle(201,0)=1
//cle(201,1)=0
//cle(201,2)=2

/*
void triAux(int* T, int n, int i){
  // Step 1: Find the maximum digit of the current iteration
  int max = 0;
  for(int j = 0; j < n; j++){
    int digit = cle(T[j], i);
    if (digit > max) {
      max = digit;
    }
  }

  // Step 2: Initialize the count array and set all values to 0
  int count[max + 1];
  memset(count, 0, sizeof count);

  // Step 3: Count the occurrences of each digit
  for(int j = 0; j < n; j++){
    int digit = cle(T[j], i);
    count[digit]++;
  }

  // Step 4: Accumulate the count of each digit
  for(int j = 1; j <= max; j++) count[j] += count[j - 1];

  // Step 5: Place each element in its correct position in the output array
  int output[n];
  for(int j = n - 1; j >= 0; j--){
    int digit = cle(T[j], i);
    if(digit >= 0) {
      output[--count[digit]] = T[j];
    }
    else {
      output[--count[0]] = T[j];
    }
  }

  // Step 6: Copy the sorted elements back to the input array
  for(int j = 0; j < n; j++) T[j] = output[j];
}
*/
void TriAux(int *T, int n , int i)
{
  int *T1=(int *)malloc(n*sizeof(int));
  int *T2=(int *)malloc(n*sizeof(int));
  int l=0;
  for(int j=0;j<n;j++){
    T1[j]=cle(T[j],i);
  }

  for(int j=0;j<10;j++)
    {
      for(int k=0;k<n;k++)
      {
        if (T1[k] == j){
          T2[l]=T[k];
          l++;
        }
      }
    }
    for(int k=0;k<n;k++){
      T[k]=T2[k];
    }
}
void TriBase(int* T, int n, int k){
    for(int i=0; i<k; i++){
        TriAux(T, n, i);

    }

}

int main()
{
 clock_t t1, t2;
  float t[5]={0,0,0,0,0};
  int vals[10] = {1000 /*, 4000, 6000, 8000 ,9000 ,10000 ,20000 ,30000,100000 ,200000*/};

  char lines[10][255];
  for(int k=0; k<10; k++){
  int n = vals[k];
  printf("n = %d \n",n);
  //int p[n];
  int* p = malloc(n * sizeof(int));
  for(int j=0; j<5;j++) //we test the same value of n after 5 try
  {

  decroissant_case(p, n);
  print_table(p,n);
  t1 = clock();
   TriBase(p, n, 6);
  t2 = clock();
  print_table(p,n);

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

