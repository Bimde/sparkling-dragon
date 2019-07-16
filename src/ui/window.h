#ifndef UI_WINDOW_H
#define UI_WINDOW_H

#include <X11/Xlib.h>
#include <iostream>
#include <string>

class Xwindow {
		Display *d;
		Window w;
		int s;
		GC gc;
		int width;
		int height;
		unsigned long colours[10];

	public:
		enum {White=0, Black, Red, Green, Blue, Cyan, Purple, Teal, Yellow, Gray};
		Xwindow(int, int);
		~Xwindow();
		Xwindow(const Xwindow&) = delete;
		Xwindow &operator=(const Xwindow&) = delete;
		void fillRectangle(int, int, int, int, int);
		void fillRectangleWithBorder(int, int, int, int, int, int);
		void drawString(int, int, std::string);
		int getWidth();
		int getHeight();
};

#endif
