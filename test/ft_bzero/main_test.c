#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libft_test.h"

#define MAX_TEST 100000
#define MEM_SIZE 64

void *ft_bzero(void *ptr, size_t n);

static void behavior_test(void) {
  char *ptr_ref = malloc(MEM_SIZE);
  char *ptr_cpy = malloc(MEM_SIZE);

  memset(ptr_ref, 'x', MEM_SIZE);
  memset(ptr_cpy, 'o', MEM_SIZE);

  char *ret_ref = bzero(ptr_ref, MEM_SIZE);
  char *ret_cpy = ft_bzero(ptr_cpy, MEM_SIZE);

  if ((ret_ref == ptr_ref) != (ret_cpy == ptr_cpy)) {
    printf("> error: return address are different\n");
  }

  if (memcmp(ptr_ref, ptr_cpy, MEM_SIZE)) {
    print_memory_diff(ptr_ref, ptr_cpy, MEM_SIZE);
  }
}

static void benchmark_original(void) {
  int index = 0;
  char *memory = malloc(1024);

  while (index < MAX_TEST) {
    bzero(memory, 1024);
    ++index;
  }

  free(memory);
}

static void benchmark_forgery(void) {
  int index = 0;
  char *memory = malloc(1024);

  while (index < MAX_TEST) {
    ft_bzero(memory, 1024);
    ++index;
  }

  free(memory);
}

int main(void) {
  behavior_test();

  long long original = time_measure(&benchmark_original);
  long long forgery  = time_measure(&benchmark_forgery);
  float relative = (float)forgery / (float)original;

  printf("> Relative Performance: %.2f time slower\n", relative);

  return 0;
}
