#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

void behavior_test(void) {
  t_list *lst = NULL;
  t_list *new = NULL;

  ft_lstadd_back(&lst, new);

  if (!lst) {
    printf("   > supposed to be NULL\n");
    exit(1);
  }
}
