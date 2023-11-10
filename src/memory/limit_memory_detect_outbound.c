#include <string.h>
#include "limit_memory.h"

bool limit_memory_detect_outbound(limit_memory_t *lm) {
  if (memcmp(lm->memory, lm->head_pattern, lm->head_length))
    return true;
  if (memcmp(lm->memory + lm->memory_length - lm->tail_length,
      lm->tail_pattern, lm->tail_length))
    return true;
  return false;
}
