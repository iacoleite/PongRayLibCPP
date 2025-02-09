//#pragma once
#include <raylib.h>
#ifndef PADDLE_H
#define PADDLE_H

class Paddle
{
public:
    int player = 1;
    int paddle_speed_x = 5;
    int paddle_speed_y = 5;
    int paddle_size_x = 60;
    int paddle_size_y = 15;
    int paddle_x = 0;
    int paddle_y = 0;
    int score = 0;


public:
    Paddle();
    Paddle(int player, int screenWidth, int screenHeight);
    void paddleMov(int screenWidth, int screenHeight, Vector2 mouse);
    void paddleDraw();
#endif
};
