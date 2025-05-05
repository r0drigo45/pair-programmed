#ifndef _SOLUTIONS_C_COMMONS_SLICE_H
#define _SOLUTIONS_C_COMMONS_SLICE_H

#include <stdio.h>

#define slice(T)     \
  struct {           \
    T *data;         \
    size_t len, cap; \
  }

// init: slice(int) s; slice_init(s);
#define slice_init(s) \
  do {                \
    (s).data = NULL;  \
    (s).len = 0;      \
    (s).cap = 0;      \
  } while (0)

// free backing array; invalidates all views
#define slice_free(s)      \
  do {                     \
    free((s).data);        \
    (s).data = NULL;       \
    (s).len = (s).cap = 0; \
  } while (0)

#define slice_append(s, v)                                      \
  do {                                                          \
    if ((s).len == (s).cap) {                                   \
      size_t newcap = (s).cap ? (s).cap * 2 : 1;                \
      void *tmp = realloc((s).data, newcap * sizeof *(s).data); \
      if (!tmp) {                                               \
        fprintf(stderr, "OOM in slice_append\n");               \
        abort();                                                \
      }                                                         \
      (s).data = tmp;                                           \
      (s).cap = newcap;                                         \
    }                                                           \
    (s).data[(s).len++] = (v);                                  \
  } while (0)

// subslice: shares storage; do NOT free the returned slice
#define slice_sub(s, start, end)              \
  ({                                          \
    typeof(s) _r;                             \
    if ((start) > (end) || (end) > (s).len) { \
      fprintf(stderr, "slice_sub OOB\n");     \
      abort();                                \
    }                                         \
    _r.data = (s).data + (start);             \
    _r.len = (end) - (start);                 \
    _r.cap = (s).cap - (start);               \
    _r;                                       \
  })

#endif
