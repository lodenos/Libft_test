#include <stdlib.h>
#include <string.h>
#include "limit_memory.h"

limit_memory_t *limit_memory_create(uint32_t ptr_length,
    uint32_t head_length, uint32_t tail_length) {
  limit_memory_t *lm;

  if (!ptr_length || !(lm = calloc(1, sizeof(limit_memory_t))))
    return NULL;

  lm->head_length = head_length;
  lm->tail_length = tail_length;
  lm->memory_length = head_length + ptr_length + tail_length;

  if (!(lm->memory = malloc(lm->memory_length)))
    goto free_limit_memory;

  if (head_length) {
    if (!(lm->head_pattern = malloc(head_length)))
      goto free_limit_memory;
    memset((uint8_t *)lm->head_pattern, DEFAULT_HEAD_PATTERN, head_length);
    memset((uint8_t *)lm->memory, DEFAULT_HEAD_PATTERN, head_length);
  }

  if (tail_length) {
    if (!(lm->tail_pattern = malloc(tail_length)))
      goto free_head_pattern;
    memset((uint8_t *)lm->tail_pattern, DEFAULT_TAIL_PATTERN, tail_length);
    memset((uint8_t *)lm->memory + head_length + ptr_length,
      DEFAULT_TAIL_PATTERN, tail_length);
  }

  lm->ptr = memset((uint8_t *)lm->memory + head_length, 0, ptr_length);

  return lm;

  free_head_pattern:
    free(lm->head_pattern);
  free_limit_memory:
    free(lm);

  return NULL;
}
