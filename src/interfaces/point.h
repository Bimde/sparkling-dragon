#ifndef INTERFACES_POINT_H
#define INTERFACES_POINT_H

struct Point {
	int x;
	int y;

	Point(int x = 0, int y = 0) : x{x}, y{y} {};

	Point operator+(const Point& other) const { 
		return Point{x + other.x, y + other.y};
	}
};

#endif