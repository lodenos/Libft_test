#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

void behavior_test(void) {
  char ref_data[]   = "0123456789";
  int  len_ref_data = 11;

  char mem_original[] = "xxxxxxxxxx";
  char mem_forgery[]  = "xxxxxxxxxx";

  char *ret_original =    memcpy(mem_original, ref_data, len_ref_data);
  char *ret_forgery  = ft_memcpy(mem_forgery,  ref_data, len_ref_data);

  if (!((ret_original != mem_original) == (ret_forgery != mem_forgery))) {
    printf(" just error\n");
    exit(1);
  }

  if ((memcmp(mem_original, ref_data, len_ref_data)
      != memcmp(mem_forgery, ref_data, len_ref_data))) {
    printf(" just error\n");
    exit(1);
  }
}
