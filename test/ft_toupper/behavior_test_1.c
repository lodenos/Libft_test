#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

void behavior_test(void) {
  int index = -128;

  while (index < 128) {
    if (toupper(index) != ft_toupper(index)) {
      printf("   |> param given: %d\n", index);
      printf("   |>    original: %d\n", toupper(index));
      printf("   |>     forgery: %d\n", ft_toupper(index));
      exit(1);
    }
    ++index;
  }
}
