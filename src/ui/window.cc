#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <iostream>
#include <cstdlib>
#include <string>
#include <unistd.h>
#include <bits/stdc++.h> 
#include "window.h"

using namespace std;

XWindow::XWindow(int width, int height): width{width}, height{height} {
	// This setup is mostly taken from a2's maze solver
	d = XOpenDisplay(NULL);
	if (d == NULL) {
		initialized = false;
		cerr << "Cannot open display" << endl;
		return;
	}
	
	s = DefaultScreen(d);
	w = XCreateSimpleWindow(
		d, RootWindow(d, s), 10, 10, width, height, 
		1, BlackPixel(d, s), WhitePixel(d, s)
	);

	Pixmap pix = XCreatePixmap(
		d, w, width, height, 
		DefaultDepth(d, DefaultScreen(d))
	);

	gc = XCreateGC(d, pix, 0, 0);

	// Setting up colours
	XColor xcolour;
	Colormap cmap;

	// Colours from https://en.wikipedia.org/wiki/X11_color_names
	char color_vals[NUM_COLOURS][10] = 
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
		"gray",
		"brown",
		"pink"
	};

	cmap = DefaultColormap(d, DefaultScreen(d));
	
	for (unsigned int i = 0; i < NUM_COLOURS; ++i) {
		XParseColor(d, cmap, color_vals[i], &xcolour);
		XAllocColor(d, cmap, &xcolour);
		colours[i] = xcolour.pixel;
	}

	 // Make window non-resizeable
	XSizeHints hints;
	hints.flags = (USPosition | PSize | PMinSize | PMaxSize );
	hints.height = hints.base_height = hints.min_height = hints.max_height = height;
	hints.width = hints.base_width = hints.min_width = hints.max_width = width;
	XSetNormalHints(d, w, &hints);

	// Open window and bring it to the front
	XMapRaised(d, w);
	XFlush(d);
	
	// Give some time for the window to initialize
	sleep(1);
}

XWindow::~XWindow() {
	XFreeGC(d, gc);
	XCloseDisplay(d);
}

// Draw a rectangle with a black border of thickness borderWidth
void XWindow::fillRectangleWithBorder(int x, int y, int width, int height, int colour, int borderWidth) {
	fillRectangle(x, y, width + borderWidth, height + borderWidth, Black);
	fillRectangle(x + borderWidth, y + borderWidth, width - borderWidth, height - borderWidth, colour);
}

// Colours should be specified using the colour enums (i.e. XWindow::Purple)
void XWindow::fillRectangle(int x, int y, int width, int height, int colour) {
	XSetForeground(d, gc, colours[colour]);
	XFillRectangle(d, w, gc, x, y, width, height);
	XFlush(d);
}

// Draw the specified string using the default font
void XWindow::drawString(int x, int y, std::string msg) {
	XTextItem items [1] = {{const_cast<char *>(msg.c_str()), msg.length(), 0, None}};
	XDrawText(d, w, DefaultGC(d, s), x, y, items, 1);
	XFlush(d);
}

int XWindow::getWidth() {
	return width;
}

int XWindow::getHeight() {
	return height;
}

bool XWindow::isInitialized() {
	return initialized;
}
