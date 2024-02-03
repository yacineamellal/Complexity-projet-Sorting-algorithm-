#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>
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
void initwithnull(int T[], int n)
{
  for (int i = 0; i < n; i++)
  {
    T[i] = 0;
  }
}
void fillrandom(int T[], int n)
{
  srand(time(0));
  for (int i = 0; i <= n; i++)
  {
    T[i] = rand() % 1000;
  }
}
void fillbest(int T[], int n)
{
  for (int i = 0; i <= n; i++)
  {
    T[i] = i;
  }
}
void fillworst(int T[], int n)
{
  for (int i = 0; i <= n; i++)
  {
    T[i] = n-i;
  }
}
void tribullesopt(int T[], int n)
{
  int x;
  int change = 1;//vrai
  int m=n-1;
  while (change == 1)//si la condition est vérifier
  {
    change = 0; // on le mit a faux
    for (int j = 0; j < m; j++)
    {
      if (T[j] > T[j + 1]) // si la condition est vérifier on permute
      {
        x = T[j];
        T[j] = T[j + 1];
        T[j + 1] = x;
       // printf("\n");
       // printtable(T, n);
        change = 1;
      }
    }
    m=m-1;
  }
}

int main()
{
  // varaibles that are used to calculate the time needed for the execution of the algorithm inbetween t1 and t2
  clock_t t1, t2;
  float t[0]={0};
  //float tbest;
  //float tworse;
  //float tmoyen;
  //different values of n that the algorithm will be tested on.
      int vals[31] = {2500, 7500, 10000, 15000, 17500, 20000, 25000, 27500, 30000, 35000,
       37500, 40000, 45000, 47500, 50000, 55000, 57500, 60000, 65000, 67500, 70000, 72500, 75000
       , 77500, 80000, 85000, 87500, 90000, 95000, 97500, 100000};
    char lines[31][255];
  // dynamyic declaration of our tables because of memeory needed for bigger values of n
  for(int k=0; k<31; k++){
  int n = vals[k];
  printf("n = %d \n",n);
  //printf("Donner la taile de tablue : \n");
  int p[n];

  // remplire tablue avec des number alletoire entre 0 et 100
  //for(int j=0; j<5;j++)
  //{
  fillrandom(p, n);
  //printtable(p, n);
  t1 = clock();
   tribullesopt(p,n);
  t2 = clock();
     // execution time calculations
  t[0] = (float)(t2 - t1) / CLOCKS_PER_SEC;

  printf("\n time = %.9f \n", t[0]);
   sprintf(lines[k], "%d,%f \n\n", n, t[0]);
  //}
  }
    FILE* fp = fopen("TriBulleOpt_Resultats.txt", "w");
   for(int i=0; i<31; i++){
        fprintf(fp , lines[i]);
    }

    fclose(fp);


  return 0;
}
