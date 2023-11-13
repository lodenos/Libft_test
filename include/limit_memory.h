#ifndef LIMIT_MEMORY_H
#define LIMIT_MEMORY_H

#define DEFAULT_HEAD_PATTERN '$'
#define DEFAULT_TAIL_PATTERN '$'

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>

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
    uint32_t ptr_length, uint32_t head_length, uint32_t tail_length);
void limit_memory_delete(limit_memory_t **lm);
bool limit_memory_detect_outbound(limit_memory_t *lm);

#endif
