#include "vec2.h"

Vec2f::Vec2f() {
    x = 0.0f;
    y = 0.0f;
};
Vec2f::Vec2f(float _x, float _y) {
    x = _x;
    y = _y;
};

Vec2f Vec2f::operator + (Vec2f const &obj) {
    Vec2f res;
    res.x = x + obj.x;
    res.y = y + obj.y;
    return res;
}
Vec2f Vec2f::operator - (Vec2f const &obj) {
    Vec2f res;
    res.x = x - obj.x;
    res.y = y - obj.y;
    return res;
}
Vec2f Vec2f::operator * (Vec2f const &obj) {
    Vec2f res;
    res.x = x * obj.x;
    res.y = y * obj.y;
    return res;
}
Vec2f Vec2f::operator / (Vec2f const &obj) {
    Vec2f res;
    res.x = x / obj.x;
    res.y = y / obj.y;
    return res;
}

Vec2f Vec2f::operator*(const float &obj) {
    Vec2f res;
    res.x = x * obj;
    res.y = y * obj;
    return res;
}
