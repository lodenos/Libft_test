#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libft.h"
#include "libft_test.h"

#define NBR_TEST 100

static void behavior_test(void) {
  size_t len_str;
  char *str;

  if (strlen("\0") != ft_strlen("\0")) {
    printf("   |> param given: empty string\n");
    printf("   |>    original: %lu\n", strlen("\0"));
    printf("   |>     forgery: %lu\n", ft_strlen("\0"));
  }

  len_str = 1;
  while (len_str < 1000000) {
    str = memset(calloc(len_str + 1, 1), (int)"x", len_str);

    if (strlen("\0") != ft_strlen("\0")) {
      printf("   |> param given: string with %zu bytes\n", len_str);
      printf("   |>    original: %lu\n", strlen("\0"));
      printf("   |>     forgery: %lu\n", ft_strlen("\0"));
      exit(1);
    }

    len_str = len_str << 1;
    free(str);
  }
}

static void benchmark_original(void) {
  int index = 0;
  int ret = 0;
  char *str = memset(calloc(1024 * 1024 + 1, 1), (int)"x", 1024 * 1024);

  while (index < NBR_TEST) {
    ret = strlen(str);
    ++index;
  }
  free(str);
}

static void benchmark_forgery(void) {
  int index = 0;
  int ret = 0;
  char *str = memset(calloc(1024 * 1024 + 1, 1), (int)"x", 1024 * 1024);

  while (index < NBR_TEST) {
    ret = ft_strlen(str);
    ++index;
  }
  free(str);
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
