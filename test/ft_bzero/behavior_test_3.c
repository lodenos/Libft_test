#include <stdio.h>
#include <stdlib.h>
#include "libft.h"
#include "libft_test.h"

void behavior_test(void) {
  limit_memory_t *lm_original, *lm_forgery;
  int len_ptr = 16777216;

  if (!(lm_original = limit_memory_create(len_ptr, 128, 128)))
    goto exit;
  if (!(lm_forgery  = limit_memory_create(len_ptr, 128, 128)))
    goto free_lm_original;

  memset(lm_original->ptr, (int)'X', len_ptr);
  memset( lm_forgery->ptr, (int)'X', len_ptr);

     bzero(lm_original->ptr, len_ptr);
  ft_bzero( lm_forgery->ptr, len_ptr);

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
