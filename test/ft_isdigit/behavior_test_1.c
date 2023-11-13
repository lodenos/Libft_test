#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

void behavior_test(void) {
  int index = -32768;

  while (index < 32768) {
    if (isdigit(index) != ft_isdigit(index)) {
      printf("   |> param given: %d\n", index);
      printf("   |>    original: %d\n", isdigit(index));
      printf("   |>     forgery: %d\n", ft_isdigit(index));
      exit(1);
    }
    ++index;
  }
}
