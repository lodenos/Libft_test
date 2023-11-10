#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

void behavior_test(void) {
  char buffer[12];
  int  nbr = -2147483648;

  sprintf(buffer, "%d", nbr);

  int ret_value = ft_atoi(buffer);
  if (ret_value != nbr) {
    printf("   |> param given: %s\n", buffer);
    printf("   |>    expected: %d\n", nbr);
    printf("   |>       given: %d\n", ret_value);
    exit(1);
  }
}
