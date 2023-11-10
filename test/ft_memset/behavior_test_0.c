#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

void behavior_test(void) {
  char str_original[] = "";
  char str_forgery[]  = "";
  int  c = 'x';
  int  len = 0;

  char *ret_original = memset(str_original, c, len);
  char *ret_forgery  = ft_memset(str_forgery, c, len);

  if (!(ret_original == str_original) && (ret_original == str_original)) {
    printf("   |> return address: not the same\n");
    printf("   |>       original: %p : %p\n", ret_original, str_original);
    printf("   |>        forgery: %p : %p\n", ret_forgery,  str_forgery);
    exit(1);
  }
}
