#ifndef LIBFT_TEST_H
#define LIBFT_TEST_H

#include <stdbool.h>
#include <stdint.h>

typedef struct {
  uint32_t head_length;
  uint32_t tail_length;
  uint32_t memory_length;
  uint32_t ptr_length;
  char *head_pattern;
  char *tail_pattern;
  void *memory;
  void *ptr;
} limit_memory_t;


limit_memory_t *limit_memory_create(
  uint32_t memory_length, uint32_t head_length, uint32_t tail_length);






long long time_measure(void (*ft)(void));
void print_memory(void *ptr, uint32_t len);
void print_memory_diff(void *ptr_1, void *ptr_2, uint32_t len);
bool detect_memory_outbound(void *ptr, uint32_t size, unsigned char data,
                            uint32_t len_head, uint32_t len_tail);
#endif
