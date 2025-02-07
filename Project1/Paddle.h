#pragma once
#include <raylib.h>

class Paddle
{
public:
    int paddle_x = 0;
    int paddle_y = 0;
    int paddle_speed_x = 5;
    int paddle_speed_y = 5;
    int paddle_size_x = 60;
    int paddle_size_y = 15;
    

public:
    Paddle() {};



public:
    void paddleMov(int screenWidth, int screenHeight, Vector2 mouse ) {
        if (paddle_x + paddle_size_x >= screenWidth)
        {
            paddle_x = screenWidth - paddle_size_x;
        }

        if (paddle_x <= 0)
        {
            paddle_x = 0;
        }
                
        //DrawCircle(ball_x, ball_y, ball_radius, WHITE);
        if ((IsKeyDown(KEY_D)) || (GetMouseDelta().x > 0))
            paddle_x += 5;
        if (IsKeyDown(KEY_A) || GetMouseDelta().x < 0)
            paddle_x -= 5;
    }

public:
    void paddleDraw() {
        DrawRectangle(paddle_x, paddle_y, paddle_size_x, paddle_size_y, YELLOW);
    }
};

