#pragma once
#include <raylib.h>
#ifndef BALL_H
#define BALL_H

class Ball
{
public:
    int ball_x;
    int ball_y;
    int ball_speed_x;
    int ball_speed_y;
    int ball_radius;

    public:
        Ball();

    public:
        void ballMov(int screenWidth, int screenHeight, float frameTime);

public:
    void drawBall();
#endif
};