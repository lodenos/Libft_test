#include <time.h>

long long time_measure(void (*ft)(void)) {
  struct timespec start, stop;

  clock_gettime(CLOCK_MONOTONIC, &start);

  ft();

  clock_gettime(CLOCK_MONOTONIC, &stop);

  long long t_0 = start.tv_sec * 1000000000 + start.tv_nsec;
  long long t_1 = stop.tv_sec * 1000000000 + stop.tv_nsec;
  return t_1 - t_0;
}
