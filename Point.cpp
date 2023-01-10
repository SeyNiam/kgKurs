#include "Point.h"
#include "graphics.h"
#pragma comment(lib,"graphics.lib")

void Point::namePoint(char* name) {
    int tmpX = x - 0.5 * z;
    int tmpY = y + 0.5 * z;
    outtextxy(tmpX, tmpY, name);
}

Point::Point() {}
Point::Point(float px, float py, float pz) {
    x = px;
    y = py;
    z = pz;
}

