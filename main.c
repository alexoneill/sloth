//  main.c
//  aoneill - 05/10/16

#include <stdio.h>
#include <string.h>

#include "src/screen.h"

int main(int argc, char** argv) {
  int mode = SCREEN_STANDBY;
  if(argc == 2) {
    if(strcmp(argv[1], "off") == 0)
      mode = SCREEN_OFF;
    else if(strcmp(argv[1], "standby") == 0)
      mode = SCREEN_STANDBY;
    else if(strcmp(argv[1], "suspend") == 0)
      mode = SCREEN_SUSPEND;
    else {
      printf("err: Invalid mode (%s)\n", argv[1]);
      return 1;
    }
  }

  screen_t scr;
  screen_init(&scr);

  if(!screen_dpms(&scr)) {
    printf("err: DPMS not available\n");
    return 1;
  }

  return screen_set(&scr, mode);
}
