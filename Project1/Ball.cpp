#include "Ball.h"

Ball::Ball() : ball_x(100), ball_y(100), ball_speed_x(300), ball_speed_y(300), ball_radius(15) {}

void Ball::ballMov(int screenWidth, int screenHeight, float frameTime) {
	
        ball_x += ball_speed_x * frameTime;
        ball_y += ball_speed_y * frameTime;

        if (ball_x + ball_radius >= screenWidth)
        {
            ball_x = screenWidth - ball_radius;
            ball_speed_x *= -1;
        }
        if (ball_x - ball_radius <= 0) {
            ball_x = ball_radius;
            ball_speed_x *= -1;
        }

        if (ball_y + ball_radius >= screenHeight)
        {
            ball_y = screenHeight / 2;
            ball_x = screenWidth / 2;
            ball_speed_y *= -1;
        }
        if (ball_y - ball_radius <= 0) {
            ball_y = screenHeight / 2;
            ball_x = screenWidth / 2;
            ball_speed_y *= -1;
        }
    }


void Ball::drawBall() {
        DrawCircle(ball_x, ball_y, ball_radius, WHITE);
    }



