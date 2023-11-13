#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

static t_list* create_link_list(uint32_t nbr) {
  char buffer[64];
  uint32_t index = 0;

  if (!nbr)
    return NULL;

  t_list *head = calloc(sizeof(t_list), 1);
  sprintf(buffer, "lst value: %d", index++);
  head->content = strdup(buffer);
  t_list *lst = head;

  while (index < nbr) {
    lst->next = calloc(sizeof(t_list), 1);
    lst = lst->next;
    sprintf(buffer, "lst value: %d", index);
    lst->content = strdup(buffer);
    ++index;
  }

  return head;
}

void behavior_test(void) {
  int deep = 2;
  int size = 0;

  t_list *lst = create_link_list(deep);

  size = ft_lstsize(lst);

  if (size != deep) {
    printf("   > the size should be 0\n");
    printf("   > given: %d\n", size);
    exit(1);
  }
}
