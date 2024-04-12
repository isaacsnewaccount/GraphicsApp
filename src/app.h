//app.h - header for the application class

#ifndef app_h
#define app_h

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

#endif