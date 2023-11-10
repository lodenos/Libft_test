#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

void behavior_test(void) {
  int index = -128;

  while (index < 128) {
    if ((isalnum(index)) != (ft_isalnum(index))) {
      printf("   |> param given: %d\n", index);
      printf("   |>    original: %d\n", isalnum(index));
      printf("   |>     forgery: %d\n", ft_isalnum(index));
      exit(1);
    }
    ++index;
  }
}
