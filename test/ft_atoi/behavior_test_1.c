#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

void behavior_test(void) {
  char buffer[12];
  int  index = -32768;
  int  ret_value;

  while (index < 32768) {
    sprintf(buffer, "%d", index);
    ret_value = ft_atoi(buffer);
    if (ret_value != index) {
      printf("   |> param given: %s\n", buffer);
      printf("   |>    expected: %d\n", index);
      printf("   |>       given: %d\n", ret_value);
      exit(1);
    }
    ++index;
  }
}
