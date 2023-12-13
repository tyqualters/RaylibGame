#pragma once

#include "Common.h"

struct Point {
	int x, y;
};

// Collider Steps:
//	1. Iterate thru ea. Collider
//	2. Check if 1 point contact or 2-point (line) contact
//	3. If 1 point contact, calculate Torques
//	4. If 2-point (line) contact, calculate Pressure
//	5. Apply external accelerations and internal decceleration
//	6. Iterate thru ea. Collider
//	7. Check if 1 point contact or 2-point (line) contact
//	8. If one exists, restart UNLESS it is non-prevailing.
//  9. If not, end and allow game to update graphics

class Collider {
public:
	Collider() = default;

	// Get the angle in degrees (0 to 360)
	float getAngle() {
		float degrees = (angle * 180.f) / static_cast<float>(std::numbers::pi);
		// Don't want to clamp 361 degrees to 360 lol
		while (degrees - 360.f >= 0.f) degrees -= 360.f;
		return degrees;
	}

	auto static ProcessCollisions(std::vector<Collider&> colliders) {
		for (auto& collider : colliders) {
			
		}
	}

	auto static CalculateForce(uint32_t m, float a) {
		return static_cast<float>(static_cast<float>(m) * a);
	}

protected:

	uint32_t mass{};
	float acceleration;
	float velocity;
	float angle;
};