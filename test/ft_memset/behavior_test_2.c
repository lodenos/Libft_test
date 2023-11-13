#include <stdio.h>
#include <stdlib.h>
#include "libft.h"
#include "libft_test.h"

void behavior_test(void) {
  limit_memory_t *lm_original, *lm_forgery;
  int len_ptr = 65536;

  if (!(lm_original = limit_memory_create(len_ptr, 128, 128)))
    goto exit;
  if (!(lm_forgery  = limit_memory_create(len_ptr, 128, 128)))
    goto free_lm_original;

  memset(lm_original->ptr, (int)'X', len_ptr);
  memset( lm_forgery->ptr, (int)'X', len_ptr);

  char *ret_original =    memset(lm_original->ptr, (int)'.', len_ptr);
  char *ret_forgery  = ft_memset( lm_forgery->ptr, (int)'.', len_ptr);

  if (!(ret_original == lm_original->ptr)
      != !(ret_forgery == lm_forgery->ptr)) {
    printf("   |> return address: not the same\n");
    printf("   |>       original: %p : %p\n", ret_original, lm_original->ptr);
    printf("   |>        forgery: %p : %p\n", ret_forgery,  lm_forgery->ptr);
    goto free_lm_forgery;
  }

  if (limit_memory_detect_outbound(lm_original)) {
    printf("   |> outbound memory override detected\n");
    printf("   |> TODO: Add a print for debug\n");
    goto free_lm_forgery;
  }

  if (limit_memory_detect_outbound(lm_forgery)) {
    printf("   |> outbound memory override detected\n");
    printf("   |> TODO: Add a print for debug\n");
    goto free_lm_forgery;
  }

  if (memcmp(lm_original->ptr, lm_forgery->ptr, len_ptr)) {
    printf("   |> error\n");
    goto free_lm_forgery;
  }

  return ;

  free_lm_forgery:
    limit_memory_delete(&lm_forgery);
  free_lm_original:
    limit_memory_delete(&lm_original);
  exit:
    exit(1);
}
