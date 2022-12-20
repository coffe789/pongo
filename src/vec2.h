#pragma once

struct Vec2f
{
    Vec2f();
    Vec2f(float _x, float _y);
    float x;
    float y;
    Vec2f operator + (Vec2f const &obj);
    Vec2f operator - (Vec2f const &obj);
    Vec2f operator * (Vec2f const &obj);
    Vec2f operator * (float const &obj);
    Vec2f operator / (Vec2f const &obj);
};
