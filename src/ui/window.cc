#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <iostream>
#include <cstdlib>
#include <string>
#include <unistd.h>
#include <bits/stdc++.h> 
#include "window.h"

XWindow::XWindow(int width, int height): width{width}, height{height} {
	// This setup is mostly taken from a2's maze solver
	display = XOpenDisplay(NULL);
	if (display == NULL) {
		initialized = false;
		std::cerr << "Cannot open display" << std::endl;
		return;
	}
	
	defaultScreenNum = DefaultScreen(display);

	auto borderColour = BlackPixel(display, defaultScreenNum);
	auto backgroundColour = WhitePixel(display, defaultScreenNum);
	window = XCreateSimpleWindow(
		display, RootWindow(display, defaultScreenNum), START_X, START_Y, width, height, 
		DISPLAY_BORDER_WIDTH, borderColour, backgroundColour
	);

	Pixmap pix = XCreatePixmap(
		display, window, width, height, 
		DefaultDepth(display, DefaultScreen(display))
	);

	gc = XCreateGC(display, pix, 0, 0);

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

	cmap = DefaultColormap(display, DefaultScreen(display));
	
	for (unsigned int i = 0; i < NUM_COLOURS; ++i) {
		XParseColor(display, cmap, color_vals[i], &xcolour);
		XAllocColor(display, cmap, &xcolour);
		colours[i] = xcolour.pixel;
	}

	 // Make window non-resizeable
	XSizeHints hints;
	hints.flags = (USPosition | PSize | PMinSize | PMaxSize );
	hints.height = hints.base_height = hints.min_height = hints.max_height = height;
	hints.width = hints.base_width = hints.min_width = hints.max_width = width;
	XSetNormalHints(display, window, &hints);

	// Open window and bring it to the front
	XMapRaised(display, window);
	XFlush(display);
	
	// Give some time for the window to initialize
	sleep(1);
}

XWindow::~XWindow() {
	XFreeGC(display, gc);
	XCloseDisplay(display);
}

// Draw a rectangle with a black border of thickness borderWidth
void XWindow::fillRectangleWithBorder(int x, int y, int width, int height, int colour, int borderWidth) {
	fillRectangle(x, y, width + borderWidth, height + borderWidth, Black);
	fillRectangle(x + borderWidth, y + borderWidth, width - borderWidth, height - borderWidth, colour);
}

// Colours should be specified using the colour enums (i.e. XWindow::Purple)
void XWindow::fillRectangle(int x, int y, int width, int height, int colour) {
	XSetForeground(display, gc, colours[colour]);
	XFillRectangle(display, window, gc, x, y, width, height);
	XFlush(display);
}

// Draw the specified string using the default font
void XWindow::drawString(int x, int y, std::string msg) {
	XTextItem items [1] = {{const_cast<char *>(msg.c_str()), msg.length(), 0, None}};
	XDrawText(display, window, DefaultGC(display, defaultScreenNum), x, y, items, 1);
	XFlush(display);
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
