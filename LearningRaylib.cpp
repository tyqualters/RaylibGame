// LearningRaylib.cpp : Defines the entry point for the application.

#include "LearningRaylib.h"

#include "Player.h"
#include "CollidableBlock.h"

#include <vector>

using namespace std;

std::string VecToStr(Vector2 v2) {
	return std::format("({}, {})", v2.x, v2.y);
}

int main()
{
	constexpr int WINDOW_WIDTH = 800, WINDOW_HEIGHT = 600;

	Boundaries gameBounds = { 0, 0, WINDOW_WIDTH, WINDOW_HEIGHT };

	InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Raylib game");
	SetTargetFPS(60);

	bool mouseClicked = false;

	Player mainPlayer(30, 30, 25, gameBounds);
	CollidableBlock block(100, 100, 30);
	
	//std::vector<const CollidableBlock&> blocks{ block };

	while (!WindowShouldClose()) {
		// Frame specific variables
		float deltaTime = GetFrameTime();
		Vector2 mousePos = GetMousePosition();
		// Frame specific variables
		
		// Game Loop
		mainPlayer.handleInput(deltaTime);
		// Game Loop

		// Drawing
		BeginDrawing();
		ClearBackground(WHITE);
		mainPlayer.draw();
		block.draw();
		EndDrawing();
		// Drawing
	}

	CloseWindow();

	return 0;
}
