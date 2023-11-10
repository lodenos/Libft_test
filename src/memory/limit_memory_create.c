#include <stdlib.h>
#include <string.h>
#include "limit_memory.h"

limit_memory_t *limit_memory_create(
    uint32_t ptr_length, uint32_t head_length, uint32_t tail_length) {
  limit_memory_t *limit_memory;

  if (!ptr_length || !(limit_memory = calloc(1, sizeof(limit_memory_t))))
    return NULL;

  if (!(limit_memory->memory = malloc(head_length + ptr_length + tail_length)))
    goto free_limit_memory;

  if (head_length) {
    limit_memory->head_pattern = malloc(head_length);
    if (!limit_memory->head_pattern)
      goto free_limit_memory;
    memset((uint8_t *)limit_memory->head_pattern, DEFAULT_HEAD_PATTERN, head_length);
    memset((uint8_t *)limit_memory->memory, DEFAULT_HEAD_PATTERN, head_length);
  }

  if (tail_length) {
    limit_memory->tail_pattern = malloc(tail_length);
    if (!limit_memory->tail_pattern)
      goto free_head_pattern;
    memset((uint8_t *)limit_memory->tail_pattern, DEFAULT_TAIL_PATTERN, tail_length);
    memset((uint8_t *)limit_memory->memory + head_length + ptr_length,
        DEFAULT_TAIL_PATTERN, tail_length);
  }

  limit_memory->ptr = (uint8_t *)limit_memory->memory + head_length;

  return limit_memory;

  free_head_pattern:
    free(limit_memory->head_pattern);

  free_limit_memory:
    free(limit_memory);

  return NULL;
}
