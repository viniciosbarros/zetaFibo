/*
  by Vinicios Barros - July 2014
  vinicios.barros@ieee.org - vsilva@parks.com. br

  Algoritmo para calcular zetaFibonacci

*/
#include <stdio.h>
#include <time.h>
#include <sys/time.h>

#define BASE  10
#define ESPERTO

int vector[100];
int vector_final[100];
int vector_indice[100];


int fibonacci(int n);


int main(int argc, char *argv[])
{

  long limit,
  ret, i, j = 0, last_value,
  num_rec = -1;
  struct timeval tv1,tv2;

  // primeiros termos da serie
  vector[0]=0;
  vector[1]=1;

  if( argc < 2 ){
    printf("ERROR: Must be one argument value \n Ex: %s 15 \n",argv[0]);
    return 1;
  }
    
    
  limit = strtol(argv[1], NULL ,BASE);

  gettimeofday(&tv1, NULL);

  while(ret < limit){
    num_rec++;
    vector[num_rec] = fibonacci(num_rec);
    ret =+ vector[num_rec];
  }

  gettimeofday(&tv2, NULL);

  printf ("Total time = %f seconds\n",
   (double) (tv2.tv_usec - tv1.tv_usec) / 1000000 +
   (double) (tv2.tv_sec - tv1.tv_sec));

  gettimeofday(&tv1, NULL);

  vector_final[j] = vector[num_rec-1];
  vector_indice[j] = num_rec-1;
  last_value = vector_final[j];
  j++;

  for (i=num_rec-1; i >= 0; --i){
    last_value = last_value + vector[i];
    if (last_value > limit){
      last_value = last_value - vector[i];
    }
    else{
      vector_final[j] = vector[i];
      vector_indice[j]=i;
      j++;
    }
  }

  gettimeofday(&tv2, NULL);
  printf ("Total time = %f seconds\n",
    (double) (tv2.tv_usec - tv1.tv_usec) / 1000000 +
    (double) (tv2.tv_sec - tv1.tv_sec));


  for (i = 0; i < j; i++)
    printf("\nzf(%d)= %d ", vector_indice[i], vector_final[i]);

    printf("\n");
    return 0;
}

#ifdef ESPERTO
int fibonacci(n)
{

  int fib;

  if (n == 0)
    return vector[0];
  else{
    fib = vector[n];
    if (fib == 0)
      fib = fibonacci(n-2) + fibonacci(n-1);
    vector[n] = fib;
  }
  return fib;
}
#endif

#ifndef ESPERTO
int fibonacci(n)
{
   
   if (n == 0)
    return 0;
   else if (n == 1)
     return 1;
   else
     return fibonacci(n-2) + fibonacci(n-1);
}
#endif