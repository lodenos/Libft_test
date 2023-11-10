#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "libft.h"
#include "libft_test.h"

void behavior_test(void) {
  char data_ref[] = "0123456789";
  int  len_data_ref = 11;

  limit_memory_t *mem_original, *mem_forgery;
  if (!(mem_original = limit_memory_create(len_data_ref, 16, 16)))
    goto exit;
  if (!(mem_forgery  = limit_memory_create(len_data_ref, 16, 16)))
    goto free_mem_original;

  char *ret_original =    strdup(data_ref);
  char *ret_forgery  = ft_strdup(data_ref);

  if ((!ret_original) != (!ret_forgery)) {
    printf("> fuck it up\n");
    goto free_mem_forgery;
  }

  if (memcmp(ret_forgery, data_ref, len_data_ref)) {
    printf("> fuck it up\n");
    goto free_mem_forgery;
  }

  return ;

  free_mem_forgery:
    limit_memory_delete(&mem_forgery);

  free_mem_original:
    limit_memory_delete(&mem_original);

  exit:
    exit(1);
}
