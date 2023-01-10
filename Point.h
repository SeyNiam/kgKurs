#pragma once
// класс для точек
class Point {
public:
    float x;
    float y;
    float z;
    char* name;

    void namePoint(char* name);
    
    Point();
    Point(float px, float py, float pz);
    
};

