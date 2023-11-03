#include <stdio.h>
#include <stdlib.h>
#include "libft_test.h"

#define MAX_NUMBER 100000
#define MIN_NUMBER -100000

char *ft_itoa(int nbr);

static void benchmark_original(void) {
  char *buffer;
  int nbr = MIN_NUMBER;

  while (nbr < MAX_NUMBER) {
    buffer = (char *)malloc(12);
    sprintf(buffer, "%d", nbr++);
    free(buffer);
  }
}

static void benchmark_forgery(void) {
  char *buffer;
  int nbr = MIN_NUMBER;

  while (nbr < MAX_NUMBER) {
    buffer = ft_itoa(nbr++);
    free(buffer);
  }
}

int main(void) {
  long long ref = time_measure(&benchmark_reference);
  long long imp = time_measure(&benchmark_implementation);
  printf("> Relative Performance: %.2f time slower\n", (float)imp / (float)ref);
  return 0;
}
