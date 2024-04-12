#pragma once

// #include <iostream>

class App {
private:
    double viewportScale;
    
public:
    App();

    void init();

    void setViewportScale(double scale);

    double getViewportScale() const;
};