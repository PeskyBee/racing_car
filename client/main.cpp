#include <iostream>

#include <X11/keysym.h> 
#include <X11/Xlib.h> 
#include <X11/Xutil.h> 

#include "movement.h"

using namespace std;
using namespace rc;

// Diferent combinations are allowed as well.
unsigned int movementFromKey(char key) {
    unsigned int mask;
    switch (key) {
        case 'w':
            return FORWARD;
        case 's':
            return REVERSE;
        case 'a':
            return LEFT;
        case 'd':
            return RIGHT;
        default:
            return IDLE;
    }
}
 
int setupWindow(void) {
   Display *d;
   Window w;
   XEvent e;
   int s;
   // current movement state;
   unsigned int moveState = 0;
 
   d = XOpenDisplay(NULL);
   if (d == NULL) {
      fprintf(stderr, "Cannot open display\n");
      exit(1);
   }
 
   s = DefaultScreen(d);
   w = XCreateSimpleWindow(d, RootWindow(d, s), 10, 10, 100, 100, 1,
                           BlackPixel(d, s), WhitePixel(d, s));
   XSelectInput(d, w, KeyPressMask | KeyReleaseMask);
   XMapWindow(d, w);

   KeySym key;      /* a dealie-bob to handle KeyPress Events */    
   char text[255];     /* a char buffer for KeyPress Events */
 
   while (1) {
      XNextEvent(d, &e);
      if ((e.type == KeyPress || e.type == KeyRelease) && XLookupString(&e.xkey, text, 255, &key, 0)==1) {
          /* use the XLookupString routine to convert the invent
             KeyPress data into regular text.  Weird but necessary...
             */
          if (text[0]=='q') {
              break;
          }
          moveState = updateState(movementFromKey(text[0]), moveState);
          cout << moveState << endl;
      }
   }
 
   XCloseDisplay(d);
   return 0;
}

int main() {
    setupWindow();
    return 0;
}
