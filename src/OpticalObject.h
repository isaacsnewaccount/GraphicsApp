#ifndef OPTICAL_OBJECT_H
#define OPTICAL_OBJECT_H

class OpticalObject {
public:
    OpticalObject(int x, int y); // x and y are canvas positions, not screen positions
    int getX() const;
    int getY() const;
private:
    int m_x;
    int m_y;
};

#endif // OPTICAL_OBJECT_H
