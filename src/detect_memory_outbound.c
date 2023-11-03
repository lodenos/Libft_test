#include <stdbool.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>

bool detect_memory_outbound(void *ptr, uint32_t size, unsigned char data,
                            uint32_t len_head, uint32_t len_tail) {
  unsigned char *memory = (unsigned char *)ptr;
  uint32_t shift = size - len_tail;

  char *head = memset(malloc(len_head), data, len_head);

  if (memcmp(memory, head, len_head))
    goto head;

  char *tail = memset(malloc(len_tail), data, len_tail);

  if (memcmp(memory + shift, tail, len_tail))
    goto tail;

  free(tail);
  free(head);
  return false;

  tail:
    free(tail);
  head:
    free(head);
  return true;
}
