#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>

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


void supprimer_min(int T[],int a)
{
    int x;
    x = T[a];
    T[a] = T[0];
    T[0] = x;
}

void creer_tas(int T[], int n, int i)
{
    int p = i;
    int gauche = 2 * i + 1; // fils gauche
    int droite = 2 * i + 2; // fils droit
    int x;

    if (gauche < n && T[gauche] < T[p])
    {
        p = gauche;
    }

    if (droite < n && T[droite] < T[p])
    {
        p = droite;
    }

    if (p != i) {
        x = T[i];
        T[i] = T[p];
        T[p] = x;

        creer_tas(T, n, p);
    }
}

void tri_tas(int T[], int n)
{
    int x;
    int i;
    i = (n/2) - 1;
    while(i>=0)
    {
        creer_tas(T, n, i);
        i--;
    }
    i = n-1;
    while(i>=0)
    {
        supprimer_min(T,i);
        creer_tas(T, i, 0);
        i--;
    }


    //inverser les élements du tableau
    for(i=0;i<n/2;i++)
    {
        x = T[i];
        T[i] = T[n-i-1];
        T[n-i-1] = x;
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
  //printf("Donner la taile de tablue : \n");
  //int p[n];
  int* p = malloc(n * sizeof(int));

  // remplire tablue avec des number alletoire entre 0 et 100
  for(int j=0; j<5;j++)
  {
  //croissant_case(p, n);
  decroissant_case(p,n);
//middle_case(p,n);
  t1 = clock();
   tri_tas(p,n);
  t2 = clock();
     // execution time calculations
  t[j] = (float)(t2 - t1) / CLOCKS_PER_SEC;

  printf("\n time = %.9f \n", t[j]);
   sprintf(lines[k], "%d,%f,%f,%f,%f,%f \n", n, t[0],t[1],t[2],t[3],t[4]);
  }
  }
    //FILE* fp = fopen("tri_par_tas_best.txt", "w");
    FILE* fp = fopen("tri_par_tas_worst.txt", "w");
    //FILE* fp = fopen("tri_par_tas.txt", "w");
   for(int i=0; i<10; i++){
        fprintf(fp, lines[i]);
    }

    fclose(fp);


  return 0;
}