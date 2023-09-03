#pragma once

#include <raylib.h>
#include <cstdio>
#include <algorithm>

struct Boundaries {
	int xmin, ymin, xmax, ymax;
};

class Player {
public:

	Player(int x0, int y0, int r0, Boundaries& gameBounds) : bounds(gameBounds) {
		x = static_cast<float>(x0);
		y = static_cast<float>(y0);
		r = static_cast<float>(r0);
	}

	inline void draw() {
		DrawCircle(static_cast<int>(x), static_cast<int>(y), static_cast<int>(r), DARKGREEN);
	}

	inline void handleInput(float deltaTime) {
		if (IsKeyDown(KEY_W)) {
			y -= 2.f + (2.f* deltaTime);
		}
		
		if (IsKeyDown(KEY_A)) {
			x -= 2.f + (2.f * deltaTime);
		}

		if (IsKeyDown(KEY_D)) {
			x += 2.f + (2.f * deltaTime);
		}

		if (IsKeyDown(KEY_S)) {
			y += 2.f + (2.f * deltaTime);
		}
		x = std::clamp<int>(x, bounds.xmin + r, bounds.xmax - r);
		y = std::clamp<int>(y, bounds.ymin + r, bounds.ymax - r);
	}

	float x, y, r;
	Boundaries& bounds;
};