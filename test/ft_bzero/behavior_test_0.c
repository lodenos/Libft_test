#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

void behavior_test(void) {
  char data_original[] = "x";
  char data_forgery[]  = "x";
  int  len_data = 2;

  bzero(data_original, 1);
  ft_bzero(data_forgery, 1);

  if (!memcmp(data_original, data_forgery, len_data)) {
    printf("> just fail\n");
    exit(1);
  }
}
