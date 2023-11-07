#include <ctype.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include "libft.h"
#include "libft_test.h"

#define NBR_TEST 100000000

static void behavior_test(void) {
  int64_t index = INT_MIN;

  while (index <= INT_MAX) {
    if ((isprint(index)) != (ft_isprint(index))) {
      printf("   |> param given: %lld\n", index);
      printf("   |>    original: %d\n", isprint(index));
      printf("   |>     forgery: %d\n", ft_isprint(index));
      exit(1);
    }
    ++index;
  }
}

static void benchmark_original(void) {
  int index = 0;
  int ret = 0;

  while (index < NBR_TEST)
    ret = isprint(index++);
}

static void benchmark_forgery(void) {
  int index = 0;
  int ret = 0;

  while (index < NBR_TEST)
    ret = ft_isprint(index++);
}

int main(void) {
  behavior_test();

  long long original = time_measure(&benchmark_original);
  long long forgery  = time_measure(&benchmark_forgery);

  if (forgery < original) {
    float relative = (float)original / (float)forgery;
    printf("   |> relative performance: %.2f time faster\n", relative);
  } else {
    float relative = (float)forgery / (float)original;
    printf("   |> relative performance: %.2f time slower\n", relative);
  }

  printf("   |> original - speed average: %.2f ns per test\n", (float)original / NBR_TEST);
  printf("   |> forgery  - speed average: %.2f ns per test\n",  (float)forgery / NBR_TEST);
  return 0;
}
