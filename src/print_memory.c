#include <stdint.h>
#include <stdio.h>

#define PURPLE "\033[0;35m"
#define RED    "\033[0;31m"
#define RESET  "\033[0m"

void print_memory_diff(void *ptr_1, void *ptr_2, uint32_t len) {
  unsigned char *a = (unsigned char *)ptr_1;
  unsigned char *b = (unsigned char *)ptr_2;

  uint32_t index = 0;
  
  while (index < len) {
    if (a[index] != b[index]) {
      printf("|%s%02X%s", RED, a[index], RESET);
    } else {
      printf("|%02X", a[index]);
    }
    ++index;
  }

  index = 0;
  printf("\n");

  while (index < len) {
    if (a[index] != b[index]) {
      printf("|%s%02X%s", RED, b[index], RESET);
    } else {
      printf("|%02X", a[index]);
    }
    ++index;
  }

  printf("\n");
}

void print_memory(void *ptr, uint32_t len) {
  unsigned char *data = (unsigned char *)ptr;

  while (len--)
    printf("|%02X", *data++);
}
