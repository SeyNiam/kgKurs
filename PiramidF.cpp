
#include <iostream>
#include <math.h>
#include "graphics.h"
#pragma comment(lib,"graphics.lib")

#include "Point.h"
#include "Surface.h"
#include "PiramidF.h"
#include "Colours.h"

using namespace std;


// отрисовка линии попиксельно
void line_DDAF(float x1, float y1, float z1, float x2, float y2, float z2, COLORREF cColor) {
    // ”чЄт координаты z при отрисовке в двумерном пространстве
    x1 -= 0.5 * z1;
    y1 += 0.5 * z1;
    x2 -= 0.5 * z2;
    y2 += 0.5 * z2;

    // ÷елочисленные значени€ координат начала и конца отрезка, округлЄнные до ближайшего целого
    int iX1 = roundf(x1);
    int iY1 = roundf(y1);
    int iX2 = roundf(x2);
    int iY2 = roundf(y2);

    // ƒлина и высота линии
    int deltaX = abs(iX1 - iX2);
    int deltaY = abs(iY1 - iY2);

    // —читаем минимальное количество итераций, необходимое дл€ отрисовки отрезка
    // ¬ыбира€ максимум из длины и высоты линии, обеспечиваем св€зность линии
    int length = max(deltaX, deltaY);

    // особый случай, на экране закрашиваетс€ ровно один пиксель
    if (length == 0) {
        putpixel(iX1, iY1, cColor);
        return;
    }
    // ¬ычисл€ем приращени€ на каждом шаге по ос€м абсцисс и ординат
    double dX = (x2 - x1) / length;
    double dY = (y2 - y1) / length;

    // Ќачальные значени€
    double x = x1;
    double y = y1;

    // ќсновной цикл
    length++;
    while (length--) {
        x += dX;
        y += dY;
        putpixel(roundf(x), roundf(y), cColor);
    }
}



// конструктор от 5 точек
char name_E[2] = "E";
char name_F[2] = "F";
char name_G[2] = "G";
char name_H[2] = "H";
char name_I[2] = "I";

PiramidF::PiramidF(Point One, Point Two, Point Three, Point Four, Point Five) {
    E.x = One.x; E.y = One.y; E.z = One.z; E.name = name_E;
    F.x = Two.x; F.y = Two.y; F.z = Two.z; F.name = name_F;
    G.x = Three.x; G.y = Three.y; G.z = Three.z; G.name = name_G;
    H.x = Four.x; H.y = Four.y; H.z = Four.z; H.name = name_H;
    I.x = Five.x; I.y = Five.y; I.z = Five.z; I.name = name_I;
    drawPiramidF();
}


// отрисовка
void PiramidF::drawPiramidF() {

    // вывод имЄн точек
    setcolor(TEXTCOL);
    E.namePoint(E.name);
    F.namePoint(F.name);
    G.namePoint(G.name);
    H.namePoint(H.name);
    I.namePoint(I.name);

    // нижнее основание
    line_DDAF(E.x, E.y, E.z, F.x, F.y, F.z, col); // лини€ 1
    line_DDAF(F.x, F.y, F.z, G.x, G.y, G.z, col); // лини€ 2
    line_DDAF(G.x, G.y, G.z, H.x, H.y, H.z, col); // лини€ 3
    line_DDAF(H.x, H.y, H.z, E.x, E.y, E.z, col); // лини€ 4

    // боковые грани
    line_DDAF(I.x, I.y, I.z, E.x, E.y, E.z, col); // лини€ 5
    line_DDAF(I.x, I.y, I.z, F.x, F.y, F.z, col); // лини€ 6
    line_DDAF(I.x, I.y, I.z, G.x, G.y, G.z, col); // лини€ 7
    line_DDAF(I.x, I.y, I.z, H.x, H.y, H.z, col); // лини€ 8

    // закраска граней фигуры
   // colouring();

}

// пермещение
void PiramidF::moveX(float amt) {
    E.x += amt;
    F.x += amt;
    G.x += amt;
    H.x += amt;
    I.x += amt;
}
void PiramidF::moveY(float amt) {
    E.y += amt;
    F.y += amt;
    G.y += amt;
    H.y += amt;
    I.y += amt;
}
void PiramidF::moveZ(float amt) {
    E.z += amt;
    F.z += amt;
    G.z += amt;
    H.z += amt;
    I.z += amt;
}


