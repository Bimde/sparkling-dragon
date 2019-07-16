#ifndef UI_WINDOW_H
#define UI_WINDOW_H

#include <X11/Xlib.h>
#include <iostream>
#include <string>

class XWindow {
		static const int NUM_COLOURS = 12;

		Display *d;
		Window w;
		int s;
		GC gc;
		int width;
		int height;
		unsigned long colours[NUM_COLOURS];
		bool initialized = true;

	public:
		// Colour enums
		enum {White=0, Black, Red, Green, Blue, Cyan, Purple, Teal, Yellow, Gray, Brown, Pink};

		XWindow(int, int);
		~XWindow();
		XWindow(const XWindow&) = delete;
		XWindow &operator=(const XWindow&) = delete;
		
		void fillRectangle(int, int, int, int, int);
		void fillRectangleWithBorder(int, int, int, int, int, int);
		void drawString(int, int, std::string);
		int getWidth();
		int getHeight();
		bool isInitialized();
};

#endif
