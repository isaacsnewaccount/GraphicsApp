#include "OpticalObject.h"

OpticalObject::OpticalObject(int x, int y) : m_x(x), m_y(y) {}

int OpticalObject::getX() const {
    return m_x;
}

int OpticalObject::getY() const {
    return m_y;
}


Ray::Ray(int x, int y, int p2x, int p2y) : OpticalObject(x, y) {
    // Calculate the angle between the origin and the second point (p2)
    double dx = p2x - x;
    double dy = p2y - y;
    m_angle = atan2(dy, dx); // atan2 returns angle in radians (-π to π)
}

double Ray::getAngle() const {
    return m_angle;
}