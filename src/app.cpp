#include <iostream>
#include "app.h"

using namespace std;

App::App() : viewportScale(1.0) {} // Initialize default viewport scale

void App::init() {
	cout << "Initializing app.\n";
}

void App::setViewportScale(double scale) {
    viewportScale = scale;
}

double App::getViewportScale() const {
    return viewportScale;
}



