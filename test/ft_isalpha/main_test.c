#include "libft.h"
#include "libft_test.h"

#define MAX_TEST 1000000

static void behavior_test(void) {
  
  if ()


}

static void benchmark_original(void) {
  int index = 0;

  while (index < MAX_TEST)
    isalpha(index++);
}

static void benchmark_forgery(void) {
  int index = 0;
  while (index < MAX_TEST)
  ft_isalpha()

}

int main(void) {
  behavior_test();

  long long original = time_measure(&benchmark_original);
  long long forgery  = time_measure(&benchmark_forgery);
  float relative = (float)forgery / (float)original;

  printf("> Relative Performance: %.2f time slower\n", relative);

  return 0;
}
