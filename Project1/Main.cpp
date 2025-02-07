#include <iostream>
#include <raylib.h>
#include "Ball.h"
#include "Paddle.h"

using namespace std;


int main() {
    const int screenWidth = 1024;
    const int screenHeight = 768;
    cout << "Third time is the charm!" << endl;
    InitWindow(screenWidth, screenHeight, "My PONG RAYLIB program!");
    SetTargetFPS(75);
    //Color Dark_Green = Color{ 20, 160, 133, 255 };
    Color Black = Color{ 0, 0, 0, 255 };

    Ball ball = Ball();
    std::cout << GetScreenWidth() << " " << GetScreenHeight() << std::endl;
	Paddle paddle = Paddle(1, 1024, 768);
	Paddle paddle2 = Paddle(2, GetScreenWidth(), GetScreenHeight());

	Vector3 v3 = { 2, 2, 2 };

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
        DrawLine(0, GetScreenHeight() / 2, GetScreenWidth(), GetScreenHeight()/2, GREEN);

		//DrawRectangleGradientV(0, 0, screenWidth, screenHeight, BLACK, DARKGREEN);
        
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
        paddle2.paddleMov(screenWidth, screenHeight, mousePosition);
		paddle2.paddleDraw();

		if (CheckCollisionCircleRec(Vector2{ (float)ball.ball_x, (float)ball.ball_y }, (float)ball.ball_radius, Rectangle{ (float)paddle.paddle_x, (float)paddle.paddle_y, (float)paddle.paddle_size_x, (float)paddle.paddle_size_y })) {
            if (ball.ball_speed_y < 0)
                ball.ball_speed_y *= -1;
            paddle.score++;

		}
        if (CheckCollisionCircleRec(Vector2{ (float)ball.ball_x, (float)ball.ball_y }, (float)ball.ball_radius, Rectangle{ (float)paddle2.paddle_x, (float)paddle2.paddle_y, (float)paddle2.paddle_size_x, (float)paddle2.paddle_size_y })) {
            if (ball.ball_speed_y > 0)
                ball.ball_speed_y *= -1;
            paddle2.score++;
		}
        DrawText(TextFormat("Player 1: %i", paddle.score), 200, 200, 20, RED);
        DrawText(TextFormat("Player 2: %i", paddle2.score), 640, 480, 20, WHITE);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}