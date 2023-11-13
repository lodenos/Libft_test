#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

void behavior_test(void) {
  int index = -32768;

  while (index < 32768) {
    if (isalpha(index) != ft_isalpha(index)) {
      printf("   |> param given: %d\n", index);
      printf("   |>    original: %d\n", isalpha(index));
      printf("   |>     forgery: %d\n", ft_isalpha(index));
      exit(1);
    }
    ++index;
  }
}
