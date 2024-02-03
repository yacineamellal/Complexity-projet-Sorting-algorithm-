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

// Fonction clé qui renvoie le chiffre à la position i d'un entier x
int cle(int x, int i) {
    int p1 = pow(10, i + 1);
    int p2 = p1 / 10;
    int chiffre = ((x % p1) - (x % p2)) / p2;
    return chiffre;
}

// Fonction SortAux qui réorganise les éléments de T en fonction de la clé à la position i
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
  int vals[10] = {1000, 4000, 6000, 8000 ,9000 ,10000 ,20000 ,30000,100000 ,200000};
  char lines[10][255];

  for(int k=0; k<10; k++){
  int n = vals[k];
  printf("n = %d \n",n);
  int p[n];

  for(int j=0; j<5;j++) //we test the same value of n after 5 try
  {
  croissant_case(p, n);
  t1 = clock();
   TriBase(p,n,6);
  t2 = clock();
     // execution time calculations
  t[j] = (float)(t2 - t1) / CLOCKS_PER_SEC;

  printf("\n time = %.9f \n", t[j]);
   sprintf(lines[k], "%d,%f,%f,%f,%f,%f \n", n, t[0],t[1],t[2],t[3],t[4]);
   }
  }
    FILE* fp = fopen("RadixSort_BestResultats.txt", "w");
   for(int i=0; i<10; i++){
        fprintf(fp , lines[i]);
    }

    fclose(fp);


  return 0;
}

/*

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Fonction clé qui renvoie le chiffre à la position i d'un entier x
int cle(int x, int i) {
    int p1 = pow(10, i + 1);
    int p2 = p1 / 10;
    int chiffre = ((x % p1) - (x % p2)) / p2;
    return chiffre;
}

// Fonction SortAux qui réorganise les éléments de T en fonction de la clé à la position i
void SortAux(int* T, int n, int i) {
    int* cles = (int*)malloc(10 * sizeof(int));
    int* resultat = (int*)malloc(n * sizeof(int));

    for (int k = 0; k < 10; k++)
        cles[k] = 0;

    for (int j = 0; j < n; j++) {
        cles[cle(T[j], i)]++;
    }

    for (int k = 1; k < 10; k++)
        cles[k] += cles[k - 1];

    for (int j = n - 1; j >= 0; j--) {
        resultat[cles[cle(T[j], i)] - 1] = T[j];
        cles[cle(T[j], i)]--;
    }

    for (int j = 0; j < n; j++)
        T[j] = resultat[j];

    free(cles);
    free(resultat);
}

// Fonction RadixSort qui trie le tableau T par distribution
void RadixSort(int* T, int n, int k) {
    for (int i = 0; i < k; i++) {
        SortAux(T, n, i);
    }
}

int main() {
    // Exemple d'utilisation
    int n = 5;
    int A[] = {141, 232, 045, 112, 143};

    printf("Avant le tri : ");
    for (int i = 0; i < n; i++) {
        printf("%d ", A[i]);
    }

    RadixSort(A, n, 3); // Tri par distribution jusqu'au chiffre des centaines

    printf("\nAprès le tri : ");
    for (int i = 0; i < n; i++) {
        printf("%d ", A[i]);
    }

    return 0;
}
*/