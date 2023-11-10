#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

void behavior_test(void) {
  int index = -128;

  while (index < 128) {
    if (isascii(index) != ft_isascii(index)) {
      printf("   |> param given: %d\n", index);
      printf("   |>    original: %d\n", isascii(index));
      printf("   |>     forgery: %d\n", ft_isascii(index));
      exit(1);
    }
    ++index;
  }
}
