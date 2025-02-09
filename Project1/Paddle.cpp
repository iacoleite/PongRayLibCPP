#include "Paddle.h"

Paddle::Paddle() : paddle_x(0), paddle_y(0), paddle_speed_x(5), paddle_speed_y(5), paddle_size_x(60), paddle_size_y(15), player(1), score(0) {};

Paddle::Paddle(int player, int screenWidth, int screenHeight) {
	this->player = player;
	if (player == 1) {
		paddle_x = 0;
		paddle_y = 0;
	} else {
		paddle_x = 0;
		paddle_y = screenHeight - paddle_size_y;
	}
};

void Paddle::paddleDraw() {
	DrawRectangle(paddle_x, paddle_y, paddle_size_x, paddle_size_y, YELLOW);
}; 

void Paddle::paddleMov(int screenWidth, int screenHeight, Vector2 mouse) {
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
};
