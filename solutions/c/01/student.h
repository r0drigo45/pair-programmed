#ifndef _SOLUTIONS_C_01_STUDENT_H
#define _SOLUTIONS_C_01_STUDENT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "slice.h"

typedef struct {
  char* name;
  slice(float) grades;
  float mean;
} Student;

static inline void Student_init(Student* s, char* name) {
  s->name = strdup(name);
  if (!s->name) {
    fprintf(stderr, "OOM: strdup failed in Student_init\n");
    abort();
  }
  slice_init(s->grades);
  s->mean = 0.0f;
}

static inline void Student_free(Student* s) {
  slice_free(s->grades);
  free(s->name);
  s->mean = 0.0f;
}

static inline void add_grade(Student* s, float grade) {
  slice_append(s->grades, grade);
} 

static inline void calculate_mean(Student* s) {
  size_t len = s->grades.len;
  float temp = 0.0;
  for (size_t i = 0; i < len; i++) {
    temp += s->grades.data[i];
  }
  s->mean = temp / len;
}

#endif
