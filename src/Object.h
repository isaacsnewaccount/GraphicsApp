#ifndef OBJECT_H
#define OBJECT_H

class Object {
public:
    Object(int x, int y); //x and y are canvas positions, not screen positions
    int getX() const;
    int getY() const;
private:
    int m_x;
    int m_y;
};

#endif // OBJECT_H