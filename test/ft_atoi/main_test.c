#include <stdio.h>
#include <stdlib.h>
#include "libft_test.h"

#define MAX_TEST 1000000

int ft_atoi(char *str);

static void behavior_test(char *str) {
  register int original = atoi(str);
  register int forgery = ft_atoi(str);

  if (original != forgery) {
    printf(">    atoi(): %d\n", original);
    printf("> ft_atoi(): %d\n", forgery);
  }
}

static void behavior_test_all_numbers() {
  char buffer[12];
  int index = 0x80000000;

  while (index < 0x7FFFFFFF) {
    sprintf(buffer, "%d", index++);
    behavior_test(buffer);
  }
  sprintf(buffer, "%d", index);
  behavior_test(buffer);
}

static void benchmark_original(void) {
  char buffer[] = "-2147483648";
  int index = 0;

  while (index++ < MAX_TEST)
    atoi(buffer);
}

static void benchmark_forgery(void) {
  char buffer[] = "-2147483648";
  int index = 0;

  while (index++ < MAX_TEST)
    ft_atoi(buffer);
}

int main(void) {
  behavior_test_all_numbers();

  long long original = time_measure(&benchmark_original);
  long long forgery  = time_measure(&benchmark_forgery);
  float relative = (float)forgery / (float)original;

  printf("> Relative Performance: %.2f time slower\n", relative);

  return 0;
}
