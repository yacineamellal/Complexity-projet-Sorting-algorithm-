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
//fonction tri � bulles
//complexit� temporelle effectue dans le pire cas est de O(n^2) "le tableau n'est pas tri�e "
// dans le meilleure cas le tableau est tri�e deja donc elle est d'ordre Omega(n)
void tribulles(int T[], int n)
{
  int x;
  int change = 1;//vrai
  while (change == 1)
  {
    change = 0;// le mit a faux (pas de changement)
    for (int j = 0; j < n - 1; j++)
    {
      if (T[j] > T[j + 1])
      {
        x = T[j];
        T[j] = T[j + 1];
        T[j + 1] = x;
       // printf("\n");
       // printtable(T, n);
        change = 1;
      }
    }
  }
}

int main()
{
  //Des variables utilis�es pour calculer le temps n�cessaire � l'ex�cution de l'algorithme entre t1 et t2.
 clock_t t1, t2;
  float t[5]={0,0,0,0,0};
  //different values of n that the algorithm will be tested on.
       int vals[40] = {2500, 5000, 7500, 10000, 12500, 15000, 17500, 20000, 22500, 25000, 27500, 30000, 32500, 35000,
       37500, 40000, 42500, 45000, 47500, 50000, 52500, 55000, 57500, 60000, 62500, 65000, 67500, 70000, 72500, 75000
       , 77500, 80000, 82500, 85000, 87500, 90000, 92500, 95000, 97500, 100000};
    char lines[40][255];
  // dynamyic declaration of our tables because of memeory needed for bigger values of n
  for(int k=0; k<40; k++){
  int n = vals[k];
  printf("n = %d \n",n);
  //printf("Donner la taile de tablue : \n");
  int p[n];

  // remplire tablue avec des number alletoire entre 0 et 100
  for(int j=0; j<5;j++) we test the same value of n after 5 try
  {
  random_case(p, n);
  //printtable(p, n);

  t1 = clock();
   tribulles(p,n);
  t2 = clock();
     // execution time calculations
  t[j] = (float)(t2 - t1) / CLOCKS_PER_SEC;

  printf("\n time = %.9f \n", t[j]);
   sprintf(lines[k], "%d,%f,%f,%f,%f,%f \n", n, t[0],t[1],t[2],t[3],t[4]);
   }
  }
    FILE* fp = fopen("TriBulle_resultat.txt", "w");
   for(int i=0; i<31; i++){
        fprintf(fp , lines[i]);
    }

    fclose(fp);


  return 0;
}
