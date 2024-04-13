#ifndef SCENE_H
#define SCENE_H

#include <vector>
#include "OpticalObject.h"

class Scene {
public:
    void addObject(const OpticalObject& obj);
    void printObjects() const;
private:
    std::vector<OpticalObject> objects;
};

#endif // SCENE_H
