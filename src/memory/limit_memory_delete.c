#include "limit_memory.h"

void limit_memory_delete(limit_memory_t **limit_memory) {

  limit_memory_t *tmp = *limit_memory;

  free(tmp->head_pattern);
  free(tmp->tail_pattern);
  free(tmp->memory);
  *limit_memory = NULL;
}
