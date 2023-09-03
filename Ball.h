#pragma once

#include <raylib.h>

class Ball {
public:
	Ball(int x0, int y0) {
		x = x0;
		y = y0;
	}

	void move(int x1, int y1) {
		x = x1;
		y = y1;
	}

	inline void draw() {
		DrawCircle(x, y, 20.f, BLUE);
	}

	int x, y;
};