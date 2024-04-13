#ifndef SCENE_H
#define SCENE_H

#include <vector>
#include "Object.h"

class Scene {
public:
    void addObject(const Object& obj);
    void printObjects() const;
private:
    std::vector<Object> objects;
};

#endif // SCENE_H
