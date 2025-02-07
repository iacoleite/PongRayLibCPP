//#pragma once
#include <raylib.h>

class Paddle
{
public:
    int player =1;
    int paddle_speed_x = 5;
    int paddle_speed_y = 5;
    int paddle_size_x = 60;
    int paddle_size_y = 15;
    int paddle_x = 0;
    int paddle_y = 0;
    int score = 0;
    

public:
    Paddle(int player, int screenWidth, int screenHeight) {
        this->player = player;
        if (player == 1) {
             paddle_x = 0;
             paddle_y = 0;

        }
        //if (player == 2) {
        else {
             paddle_x = 0;
             paddle_y = screenHeight - paddle_size_y;

        }
    };



public:
    void paddleMov(int screenWidth, int screenHeight, Vector2 mouse) {
        if (player == 1) {
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
        else if (player == 2) {

            if (paddle_x + paddle_size_x >= screenWidth)
            {
                paddle_x = screenWidth - paddle_size_x;
            }

            if (paddle_x <= 0)
            {
                paddle_x = 0;
            }
            if (IsKeyDown(KEY_RIGHT))
                paddle_x += 5;
            if (IsKeyDown(KEY_LEFT))
                paddle_x -= 5;
        }
    }

public:
    void paddleDraw() {
        DrawRectangle(paddle_x, paddle_y, paddle_size_x, paddle_size_y, YELLOW);
    }
};

