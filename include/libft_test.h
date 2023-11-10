#ifndef LIBFT_TEST_H
#define LIBFT_TEST_H

#include <stdbool.h>
#include <stdint.h>

#include "limit_memory.h"

long long time_measure(void (*ft)(void));
void print_memory(void *ptr, uint32_t len);
void print_memory_diff(void *ptr_1, void *ptr_2, uint32_t len);
bool detect_memory_outbound(void *ptr, uint32_t size, unsigned char data,
                            uint32_t len_head, uint32_t len_tail);
#endif
