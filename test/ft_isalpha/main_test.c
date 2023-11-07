#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include "libft.h"
#include "libft_test.h"

#define MAX_TEST 1000000

static void behavior_test(void) {
  int index = -100;

  while (index < 1000) {
    if ((isalpha(index)) != (ft_isalpha(index)))
      exit(1);
    ++index;
  }
}

static void benchmark_original(void) {
  int index = 0;
  int ret = 0;

  while (index < MAX_TEST)
    ret = isalpha(index++);
}

static void benchmark_forgery(void) {
  int index = 0;

  while (index < MAX_TEST)
    ft_isalpha(index++);
}

int main(void) {
  behavior_test();

  long long original = time_measure(&benchmark_original);
  long long forgery  = time_measure(&benchmark_forgery);

  if (forgery < original) {
    float relative = (float)original / (float)forgery;
    printf(">> relative performance: %.2f time faster\n", relative);
  } else {
    float relative = (float)forgery / (float)original;
    printf(">> relative performance: %.2f time slower\n", relative);
  }
  return 0;
}
