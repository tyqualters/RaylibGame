#pragma once

#include <cstdio>
#include <cmath>
#include <raymath.h>

class Collider {
public:
	Collider() = delete;
	/**
	  * point1: top left of rectangle
	  * point2: bottom right of rectangle
	  */
	Collider(Vector2 point, Vector2 dimensions) : point(point), dimensions(dimensions) {}

	inline bool is_colliding(const Collider& collider2) {
		return std::max(point.x, collider2.point.x) < std::min(point.x + dimensions.x, collider2.point.x + collider2.dimensions.x)
			&& std::max(point.y, collider2.point.y) < std::min(point.y + dimensions.y, collider2.point.y + collider2.dimensions.y);
	}

	void add_force(Vector2 direction, float magnitude) {
		velocity = { velocity.x + direction.x, velocity.y + direction.y, velocity.z + magnitude };
		//printf("Added force (%f, %f, %f)\n", direction.x, direction.y, magnitude);
	}

	void negate_force(float magnitude) {
		velocity.z -= magnitude;
		if (velocity.z < 0) {
			velocity = { 0,0,0 };
		}
	}

	void apply_movement(Collider& collider2) {

		Collider simCollider({ point.x + velocity.x * velocity.z, point.y + velocity.y * velocity.z }, dimensions);
		if (simCollider.is_colliding(collider2)) {
			// velocity = (1 * v0 + 1 * v1) / 2
			
			float v0 = velocity.z, v1 = collider2.velocity.z;

			collider2.velocity.x += velocity.x;
			collider2.velocity.y += velocity.y;
			collider2.velocity.z = (v0 + v1) / 2;
			// handle momentum
			velocity.x = -velocity.x;
			velocity.y = -velocity.y;
			velocity.z = (v0 + v1) / 2;
			apply_movement(collider2);
		}
		else {
			point.x += velocity.x * velocity.z;
			point.y += velocity.y * velocity.z;
			collider2.point.x += collider2.velocity.x * collider2.velocity.z;
			collider2.point.y += collider2.velocity.y * collider2.velocity.z;
			//printf("Moved by (%f, %f)\n", velocity.x * velocity.z, velocity.y * velocity.z);
		}
	}

protected:
	Vector2 point, dimensions;
	Vector3 velocity = { 0,0,0 };
};