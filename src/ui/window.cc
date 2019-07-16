#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <iostream>
#include <cstdlib>
#include <string>
#include <unistd.h>
#include <bits/stdc++.h> 
#include "window.h"

using namespace std;

Xwindow::Xwindow(int width, int height): width{width}, height{height} {
	d = XOpenDisplay(NULL);
	if (d == NULL) {
		cerr << "Cannot open display" << endl;
		return;
	}
	
	s = DefaultScreen(d);
	// display, parent window, x, y, width, height, border-width, border-colour, background-colour
	w = XCreateSimpleWindow(
		d, RootWindow(d, s), 10, 10, width, height, 
		1, BlackPixel(d, s), WhitePixel(d, s)
	);

	XSelectInput(d, w, ExposureMask | KeyPressMask);

	Pixmap pix = XCreatePixmap(
		d, w, width, height, 
		DefaultDepth(d, DefaultScreen(d))
	);

	gc = XCreateGC(d, pix, 0, 0);

	// Set up colours.
	XColor xcolour;
	Colormap cmap;

	const size_t numColours = 10;

	// Colours from https://en.wikipedia.org/wiki/X11_color_names
	char color_vals[numColours][10] = 
	{
		"white", 
		"black", 
		"red", 
		"green", 
		"blue", 
		"cyan", 
		"purple", 
		"teal", 
		"yellow",
		"gray"
	};

	cmap = DefaultColormap(d, DefaultScreen(d));
	
	for (unsigned int i = 0; i < numColours; ++i) {
		XParseColor(d, cmap, color_vals[i], &xcolour);
		XAllocColor(d, cmap, &xcolour);
		colours[i] = xcolour.pixel;
	}

	XSetForeground(d, gc, colours[Black]);

	 // Make window non-resizeable.
	XSizeHints hints;
	hints.flags = (USPosition | PSize | PMinSize | PMaxSize );
	hints.height = hints.base_height = hints.min_height = hints.max_height = height;
	hints.width = hints.base_width = hints.min_width = hints.max_width = width;
	XSetNormalHints(d, w, &hints);

	// map window and flush
	XMapRaised(d, w);
	XFlush(d);
	
	// wait 1 second for setup
	sleep(1);
}

Xwindow::~Xwindow() {
	XFreeGC(d, gc);
	XCloseDisplay(d);
}

void Xwindow::fillRectangleWithBorder(int x, int y, int width, int height, int colour, int borderWidth) {
	fillRectangle(x, y, width + borderWidth, height + borderWidth, Black);
	fillRectangle(x + borderWidth, y + borderWidth, width - borderWidth, height - borderWidth, colour);
}

void Xwindow::fillRectangle(int x, int y, int width, int height, int colour) {
	XSetForeground(d, gc, colours[colour]);
	XFillRectangle(d, w, gc, x, y, width, height);
	XFlush(d);
}

void Xwindow::drawString(int x, int y, std::string msg) {
	//XDrawString(d, w, DefaultGC(d, s), x, y, msg.c_str(), msg.length());
	// char char_array[msg.length() + 1];
	// std::strcpy(char_array, msg.c_str()); 

  // XFontStruct* font = XLoadQueryFont(d, None);
  // if (!font) {
  //   cout << "font not found Times New Romans" << endl;
  //   return;
  // }

	XTextItem items [1] = {{const_cast<char *>(msg.c_str()), msg.length(), 0, None}};
	XDrawText(d, w, DefaultGC(d, s), x, y, items, 1);
	// XDrawString(d, w, DefaultGC(d, s), x, y, msg.c_str(), msg.length());
	XFlush(d);
}

int Xwindow::getWidth() {
	return width;
}

int Xwindow::getHeight() {
	return height;
}
