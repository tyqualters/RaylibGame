#pragma once

#include <raylib.h>

#include "Player.h"

class CollidableBlock {
public:
	CollidableBlock(int x0, int y0, int s0) {
		x = x0;
		y = y0;
		s = s0;
	}

	inline void draw() {
		DrawRectangle(x, y, s, s, BLACK);
	}

	Boundaries getCollidableBoundaries() {
		return {
			x, y, x + s, y + s
		};
	}

	int x, y, s;
};