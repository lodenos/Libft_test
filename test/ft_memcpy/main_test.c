#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libft_test.h"

#define DATA "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx" \
             "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx"
#define MAX_TEST 1000000

#define HEAD 8
#define TAIL 8

void *ft_memcpy(void *dst, void const *src, size_t n);

static void behavior_test(void) {
  int shift = HEAD + TAIL;
  int len_data = strlen(DATA);
  int max = len_data - shift;

  char *dst_ref = memset(malloc(len_data), 'o', len_data);
  char *src_ref = memset(malloc(len_data), '.', len_data);
  memcpy(src_ref + HEAD, DATA, max);

  char *dst_cpy = memset(malloc(len_data), 'o', len_data);
  char *src_cpy = memset(malloc(len_data), '.', len_data);
  memcpy(src_cpy + HEAD, DATA, max);

  char *ret_ref = memcpy(dst_ref + HEAD, src_ref + HEAD, max);
  char *ret_cpy = ft_memcpy(dst_cpy + HEAD, src_cpy + HEAD, max);

  if ((ret_ref == dst_ref) != (ret_cpy == dst_cpy))
    printf("> error: return address are different\n");

  if (memcmp(src_ref, src_cpy, len_data)) {
    printf("> error: src are override\n");
  }

  if (detect_memory_outbound(dst_cpy, len_data, 'o', HEAD, TAIL)) {
    printf("> potential segmentation fault detected\n");
  }

  if (memcmp(dst_ref + HEAD, dst_cpy + HEAD, max)) {
    print_memory_diff(dst_ref + HEAD, dst_cpy + HEAD, max);
  }
}

static void benchmark_original(void) {
  char *dst = calloc(1, 80);
  char *src = memcpy(calloc(1, 80), DATA, 80);
  int index = 0;

  while (index < MAX_TEST) {
    memcpy(dst, src, 80);
    ++index;
  }
}

static void benchmark_forgery(void) {
  char *dst = calloc(1, 80);
  char *src = memcpy(calloc(1, 80), DATA, 80);
  int index = 0;

  while (index < MAX_TEST) {
    ft_memcpy(dst, src, 80);
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
