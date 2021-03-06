
#include "utils.h"

float timedifference_msec(struct timeval *y, struct timeval *x) {
    float a;
    float b;

  /* Perform the carry for the later subtraction by updating y. */
  if (x->tv_usec < y->tv_usec) {
    int nsec = (y->tv_usec - x->tv_usec) / 1000000 + 1;
    y->tv_usec -= 1000000 * nsec;
    y->tv_sec += nsec;
  }
  if (x->tv_usec - y->tv_usec > 1000000) {
    int nsec = (x->tv_usec - y->tv_usec) / 1000000;
    y->tv_usec += 1000000 * nsec;
    y->tv_sec -= nsec;
  }

  /* Compute the time remaining to wait.
     tv_usec is certainly positive. */
  // result->tv_sec = x->tv_sec - y->tv_sec;
  //result->tv_usec = x->tv_usec - y->tv_usec;

  a = x->tv_sec - y->tv_sec;
  b = (x->tv_usec - y->tv_usec) + a * 1000.0f;

    return b;
}


