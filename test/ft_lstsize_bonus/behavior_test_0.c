#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

void behavior_test(void) {
  int length = ft_lstsize(NULL);

  if (length != 0) {
    printf("   > the length should be 0\n");
    printf("   > given: %d\n", length);
    exit(1);
  }
}
