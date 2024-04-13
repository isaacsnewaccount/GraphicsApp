#include "Object.h"

Object::Object(int x, int y) : m_x(x), m_y(y) {}

int Object::getX() const {
    return m_x;
}

int Object::getY() const {
    return m_y;
}