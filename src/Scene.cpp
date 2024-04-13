#include "Scene.h"
#include <iostream>

void Scene::addObject(const OpticalObject& obj) {
    objects.push_back(obj);
}

void Scene::printObjects() const {
    std::cout << "Objects in the scene:" << std::endl;
    for (const auto& obj : objects) {
        std::cout << "X: " << obj.getX() << ", Y: " << obj.getY() << std::endl;
    }
}