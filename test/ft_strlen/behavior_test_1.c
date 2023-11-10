#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

void behavior_test(void) {
  char *str_original = calloc(1, 1);
  char *str_forgery  = calloc(1, 1);

  size_t len_original = strlen(str_original);
  size_t len_forgery  = ft_strlen(str_forgery);

  if (len_original != len_forgery) {
    printf("   |> param given: empty string\n");
    printf("   |>    original: %zu\n", len_original);
    printf("   |>     forgery: %zu\n", len_forgery);
    exit(1);
  }
}
