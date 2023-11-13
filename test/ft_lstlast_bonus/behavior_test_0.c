#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

void behavior_test(void) {
  t_list *lst = calloc(sizeof(t_list), 1);

  t_list *ret = ft_lstlast(lst);

  if (ret != lst) {
    printf("> Wrong address\n");
    exit(1);
  }
}
