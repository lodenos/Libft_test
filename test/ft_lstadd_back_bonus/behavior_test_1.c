#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

void behavior_test(void) {
  char buffer[] = "data test";

  t_list *lst = NULL;
  t_list *new = calloc(sizeof(t_list), 1);
  new->content = buffer;

  ft_lstadd_back(&lst, new);

  if (lst == NULL) {
    printf("   > supposed to be not NULL\n");
    exit(1);
  }
}
