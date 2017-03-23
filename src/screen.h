//  screen.h
//  aoneill - 05/10/16

#ifndef SCREEN_H
#define SCREEN_H

#include <unistd.h>

#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <X11/extensions/dpms.h>

#define SCREEN_OFF     0x1
#define SCREEN_STANDBY 0x2
#define SCREEN_SUSPEND 0x3

typedef struct {
  Display* disp;
} screen_t;

int screen_init(screen_t* scr);
int screen_dpms(screen_t* scr);
int screen_set(screen_t* scr, int mode);

#endif
