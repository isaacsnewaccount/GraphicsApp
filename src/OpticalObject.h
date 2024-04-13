#ifndef OPTICAL_OBJECT_H
#define OPTICAL_OBJECT_H

#include <cmath>

class OpticalObject {
public:
    OpticalObject(int x, int y); // x and y are canvas positions, not screen positions
    int getX() const;
    int getY() const;
private:
    int m_x;
    int m_y;
};

class Lens : public OpticalObject {
public:
    Lens(int x, int y, double focalLength);
    double getFocalLength() const;
private:
    double m_focalLength;
};

class Ray : public OpticalObject {
public:
    Ray(int x, int y, int p2x, int p2y);
    double getAngle() const;
private:
    double m_angle;
};

#endif // OPTICAL_OBJECT_H