#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

void behavior_test(void) {
  char data_ref_a[] = "data ref -> a";
  char data_ref_b[] = "data ref -> b";

  t_list *lst_a = calloc(sizeof(t_list), 1);
  t_list *lst_b = calloc(sizeof(t_list), 1);

  lst_a->content = data_ref_a;
  lst_b->content = data_ref_b;

  ft_lstadd_front(&lst_b, lst_a);

  printf("> %s\n", (char *)lst_b->content);
  printf("> %s\n", (char *)lst_b->next->content);
}
