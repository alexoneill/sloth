//  screen.c
//  aoneill - 05/10/16

#include "screen.h"

int screen_init(screen_t* scr) {
  scr -> disp = XOpenDisplay(NULL);
  if(scr -> disp == NULL)
    return 0;

  return 1;
}

int screen_dpms(screen_t* scr) {
  int tmp;
  return DPMSQueryExtension(scr -> disp, &tmp, &tmp);
}

int screen_set(screen_t* scr, int mode) {
  if(mode != SCREEN_OFF && mode != SCREEN_STANDBY && mode != SCREEN_SUSPEND)
    return 0;

  DPMSEnable(scr -> disp);
  usleep(100000);

  switch(mode) {
    case SCREEN_OFF:
      DPMSForceLevel(scr -> disp, DPMSModeOff);
      break;

    case SCREEN_STANDBY:
      DPMSForceLevel(scr -> disp, DPMSModeStandby);
      break;
    case SCREEN_SUSPEND:
      DPMSForceLevel(scr -> disp, DPMSModeSuspend);
      break;
  }

  XCloseDisplay(scr -> disp);
  return 1;
}
