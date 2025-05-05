#include "app.h"

int main(void) {
  App app;
  App_init(&app);
  main_loop(&app);
}
