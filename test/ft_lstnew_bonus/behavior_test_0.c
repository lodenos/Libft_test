#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

void behavior_test(void) {
  char *data;
  char *data_ref;
  int  len_data = 128;

  data = memset(malloc(len_data), 'x', len_data);
  data_ref = memset(malloc(len_data), 'x', len_data);

  t_list *lst = ft_lstnew(data);

  if (!lst) {
    printf("   > return NULL\n");
    exit(1);
  }

  if (lst->content != data) {
    printf("   > the content don't have the same address.\n");
    exit(1);
  }

  if (memcmp(lst->content, data_ref, len_data)) {
    printf("   > the data aren't the same\n");
    exit(1);
  }

  if (lst->next) {
    printf("   > \n");
    exit(1);
  }
}
