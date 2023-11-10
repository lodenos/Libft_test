#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

void behavior_test(void) {
  int index = -128;

  while (index < 128) {
    if (tolower(index) != ft_tolower(index)) {
      printf("   |> param given: %d\n", index);
      printf("   |>    original: %d\n", tolower(index));
      printf("   |>     forgery: %d\n", ft_tolower(index));
      exit(1);
    }
    ++index;
  }
}
