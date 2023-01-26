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
    Point(float px, float py, float pz, char* pname);

};

Point operator - (Point p1, Point p2);
Point operator + (Point p1, Point p2);
Point operator * (Point p1, Point p2);
Point operator * (Point p1, float a);

/*
Point operator - (Point p1, Point p2) {
    Point p3;
    p3.x = p1.x - p2.x;
    p3.y = p1.y - p2.y;
    p3.z = p1.z - p2.z;
    return p3;
}

Point operator + (Point p1, Point p2) {
    Point p3;
    p3.x = p1.x + p2.x;
    p3.y = p1.y + p2.y;
    p3.z = p1.z + p2.z;
    return p3;
}

Point operator * (Point p1, Point p2) {
    Point p3;
    p3.x = p1.x * p2.x;
    p3.y = p1.y * p2.y;
    p3.z = p1.z * p2.z;
    return p3;
}

Point operator * (Point p1, float a) {
    Point p3;
    p3.x = p1.x * a;
    p3.y = p1.y * a;
    p3.z = p1.z * a;
    return p3;
}
*/