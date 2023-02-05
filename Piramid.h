#pragma once
#include "Point.h"
#include "Colours.h"
#include "graphics.h"
#pragma comment(lib,"graphics.lib")


// класс фигуры
class Piramid {
public:
    Point A, B, C, D, E, F, G, H, I;

    int col = MAINCOL;

    // конструктор от 9 точек для двух фигур сразу
    Piramid(Point One, Point Two, Point Three, Point Four, Point Five, Point Six, Point Seven, Point Eight, Point Nine);

    // отрисовка
    void drawPiramid();

    // пермещение
    void moveX(float amt);
    void moveY(float amt);
    void moveZ(float amt);

    // поворот одной точки вокруг z
    Point rotDotZ(int u, float ang, Point Cen, Point L);
    // поворот фигуры вокруг z
    void rotateZ(int u);

    // поворот одной точки вокруг y
    Point rotDotY(int u, float ang, Point Cen, Point L);
    // поворот фигуры вокруг y
    void rotateY(int u);

    // поворот одной точки вокруг x
    Point rotDotX(int u, float ang, Point Cen, Point L);
    // поворот фигуры вокруг x
    void rotateX(int u);

    // масштабирование одной точки
    Point dotScale(float e, Point Cen, Point L);
    // масштабирование всей фигуры
    void scale(float e);
     
    // размеры окна и минимальное значения дальности пикселя
    const int width = 1400;
    const int height = 700;
    int minInt = -32767;

    // закраска треугольника
    void triangle(Point t0, Point t1, Point t2, COLORREF colour, int** zbuffer);

    // z-buffer
    void zBuff(Point One, Point Two, Point Three, Point Four, Point Five, Point Six, Point Seven, Point Eight, Point Nine);

    // построение проекции точки на условный пол для тени
    Point shadowPoint(Point P);

    // построение тени для треугольника
    void shadowTri(Point A, Point B, Point C);

    // построение теней для всех фигур
    void shadowAll(Point A, Point B, Point C, Point D, Point E, Point F, Point G, Point H, Point I);

    // закраска тени треугольниками
    void shadowTriColour(Point t0, Point t1, Point t2, COLORREF colour);
};

