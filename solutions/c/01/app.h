#ifndef _SOLUTIONS_C_01_APP_H
#define _SOLUTIONS_C_01_APP_H

#include <stdbool.h>
#include <stdio.h>

#include "slice.h"
#include "student.h"

typedef struct {
  slice(Student) students;
} App;

static inline void App_init(App* app) { 
  slice_init(app->students); 
}

static inline void App_free(App* app) {
  slice_free(app->students);
}

static inline bool read_new_student(App* app) {
  char buf[256];
  printf("Nome (ou -1 para sair): ");
  if (scanf("%255s", buf) != 1) return false;
  if (strcmp(buf, "-1") == 0) return false;

  Student s;
  Student_init(&s, buf);

  float grade;
  while (1) {
    printf("\tNota para %s (ou -1 para sair): ", s.name);
    if (scanf("%f", &grade) != 1) break;
    if (grade == -1.0f) break;
    add_grade(&s, grade);
  }

  calculate_mean(&s);
  slice_append(app->students, s);
  return true;
}

static inline void main_loop(App* app) {
  while (read_new_student(app)) {
  }
  printf("--- Resultados ---\n");
  for (size_t i = 0; i < app->students.len; i++) {
    Student* s = &app->students.data[i];
    printf("Nome: %s, Média: %.2f\n", s->name, s->mean);
  }
}

#endif
