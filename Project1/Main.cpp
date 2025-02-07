#include <iostream>
#include <raylib.h>
#include "Ball.h"
#include "Paddle.h"

using namespace std;


int main() {
	
    //Color Dark_Green = Color{ 20, 160, 133, 255 };
    Color Black = Color{ 0, 0, 0, 255 };

    const int screenWidth = 1024;
    const int screenHeight = 768;

    Ball ball = Ball();
	Paddle paddle = Paddle();

	Vector3 v3 = { 2, 2, 2 };

    cout << "Third time is the charm!" << endl;
        InitWindow(screenWidth, screenHeight, "My SECOND RAYLIB program!");
    SetTargetFPS(75);

    Camera3D camera = { 0 };
    camera.position = Vector3{ 10.0f, 10.0f, 10.0f }; // Camera position
    camera.target = Vector3{ 0.0f, 0.0f, 0.0f };      // Camera looking at point
    camera.up = Vector3{ 0.0f, 1.0f, 0.0f };          // Camera up vector (rotation towards target)
    camera.fovy = 45.0f;                                // Camera field-of-view Y
    camera.projection = CAMERA_PERSPECTIVE;             // Camera projection type

    Vector3 cubePosition = { 0.0f, 0.0f, 0.0f };

    DisableCursor();                    // Limit cursor to relative movement inside the window

    while (WindowShouldClose() == false) {
        UpdateCamera(&camera, CAMERA_FREE);

        if (IsKeyPressed('Z')) camera.target = Vector3 { 0.0f, 0.0f, 0.0f };

        Vector2 mousePosition = GetMousePosition();
        BeginDrawing();
        ClearBackground(BLACK);
		DrawRectangleGradientV(0, 0, screenWidth, screenHeight, BLACK, DARKGREEN);
        
        //BeginMode3D(camera);

        //DrawCube(cubePosition, 2.0f, 2.0f, 2.0f, RED);
        //DrawCubeWires(cubePosition, 2.0f, 2.0f, 2.0f, MAROON);
        //DrawSphere(Vector3{1.0f, 1.0f, 1.0f}, 2, ORANGE);

        //DrawGrid(10, 1.0f);

        //EndMode3D();

        ball.drawBall();
		ball.ballMov(screenWidth, screenHeight, GetFrameTime());
		
		paddle.paddleMov(screenWidth, screenHeight, mousePosition);
		paddle.paddleDraw();

		if (CheckCollisionCircleRec(Vector2{ (float)ball.ball_x, (float)ball.ball_y }, (float)ball.ball_radius, Rectangle{ (float)paddle.paddle_x, (float)paddle.paddle_y, (float)paddle.paddle_size_x, (float)paddle.paddle_size_y })) {
			ball.ball_speed_y *= -1;
		}

        EndDrawing();
    }

    CloseWindow();
    return 0;
}