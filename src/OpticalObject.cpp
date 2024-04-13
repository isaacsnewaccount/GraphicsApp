#include "OpticalObject.h"

OpticalObject::OpticalObject(int x, int y) : m_x(x), m_y(y) {}

int OpticalObject::getX() const {
    return m_x;
}

int OpticalObject::getY() const {
    return m_y;
}