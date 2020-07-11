#include <iostream>
#include <stdio.h>
#include <stdlib.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
/* invierte el orden del array de enteros P 
 * OJO: el elemento '0' del array P *no* se procesa; y P[N] *sí* cuenta
 */
 
 void process(int* P, int N, int* total) { 
  int i;  
  printf("  1,2,3,4,5");
  printf("\n");
  printf("  ");
  for (i=N; i>0; i--) {
    printf("%d", P[i]);
    if(i!=1){
    	printf(",");
	}
  }  
 
  printf("\n");
  printf("------------");
    printf("\n");
  (*total) ++;
}

/* esto seguro que sabes lo que hace ... */
void swap(int *x, int *y) { 
  int temp = *x;
  *x = *y;
  *y = temp;
}

 
void reverse (int *P, int N) {
  int i = 1;  
  while ( i < (N+1-i) ) {
    swap(&P[i], &P[N+1-i]);
    i ++;
  }
}

int B(int N, int c) {  
  return ( (N % 2) != 0 ? 1 : c );
}

/* permutaciones en orden lexicografico; cuenta tambien el total 
 * OJO: el elemento '0' del array P *no* se procesa; y P[N] *sí* cuenta
 */
void lexperms (int *P, int N, int *total) {
  
  int i;
  int c[N];
  for (i = N; i > 1; i --) {
    c[i] = 1;
  }
  i = 2;
  
  process(P,N,total);   
  do {
    if (c[i] < i) {
      swap(&P[i],&P[c[i]]);
      reverse(P,i-1); /* inversion parcial! */
      process(P,N,total);
      c[i] ++;
      i = 2;
    } else {
      c[i] = 1;
      i ++;
    }
  } while (i <= N);
}


int main(int argc, char **argv) {
  int n, i, P[5], total;
  
  for (i=1; i<6; i++) P[i] = i;

  if (argv[1] == NULL) {
    printf("Conjunto de las permutaciones de 1,2,3,4,5");
    printf("\n");
    n = 5 + 1;  
  }
  else {
    n = atoi(argv[1]) + 1;
  }
  
  total = 0;
  lexperms(P,n-1, &total);
  printf("Total: %d permutaciones\n", total);
  system("PAUSE");
  return 0;
}

