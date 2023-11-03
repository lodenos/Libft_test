#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libft_test.h"

#define MAX_TEST 10000

void *ft_calloc(size_t nmemb, size_t size);

static void behavior_test(void) {
  size_t nmemb = 1;
  size_t size = 64;

  void *ptr_ref = calloc(nmemb, size);
  void *ptr_cpy = ft_calloc(nmemb, size);

  if (memcmp(ptr_ref, ptr_cpy, nmemb * size))
    print_memory_diff(ptr_ref, ptr_cpy, nmemb * size);
}

static void benchmark_original(void) {
  int index = 0;
  char *ptr;

  while (index < MAX_TEST) {
    ptr = calloc(1, 64);
    free(ptr);
    ++index;
  }
}

static void benchmark_forgery(void) {
  int index = 0;
  char *ptr;

  while (index < MAX_TEST) {
    ptr = ft_calloc(1, 64);
    free(ptr);
    ++index;
  }
}

int main() {
  behavior_test();

  long long original = time_measure(&benchmark_original);
  long long forgery  = time_measure(&benchmark_forgery);
  float relative = (float)forgery / (float)original;

  printf("> Relative Performance: %.2f time slower\n", relative);

  return 0;
}
