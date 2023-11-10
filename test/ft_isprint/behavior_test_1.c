#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

void behavior_test(void) {
  int index = -128;

  while (index < 128) {
    if (isprint(index) != ft_isprint(index)) {
      printf("   |> param given: %d\n", index);
      printf("   |>    original: %d\n", isprint(index));
      printf("   |>     forgery: %d\n", ft_isprint(index));
      exit(1);
    }
    ++index;
  }
}
