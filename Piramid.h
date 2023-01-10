#pragma once
#include "Point.h"
#include "Surface.h"
#include "graphics.h"
#pragma comment(lib,"graphics.lib")

#define P 3.14
#define TEXTCOL 13 // маджента
#define MAINCOL 13 
#define WHITE 15
#define BLACK 0

#define GREEN 2
#define CYAN 11
#define RED	4
#define YELLOW	14

// класс фигуры
class Piramid {
public:
    Point A, B, C, D;
    char name_A[2] = "A";
    char name_B[2] = "B";
    char name_C[2] = "C";
    char name_D[2] = "D";
    int col = MAINCOL;

    char name_ABC[4] = "ABC";
    char name_ADC[4] = "ADC";
    char name_ABD[4] = "ABD";
    char name_BCD[4] = "BCD";
    Surface ABC = Surface(name_ABC, RED);
    Surface ADC = Surface(name_ADC, GREEN);
    Surface ABD = Surface(name_ABD, CYAN);
    Surface BCD = Surface(name_BCD, YELLOW);

    // конструктор от 4 точек
    Piramid(Point One, Point Two, Point Three, Point Four);

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


    Point dot;  // точка пересечения
    // проверка на пересечение линий
    bool cross(Point a1, Point a2, Point a3, Point a4);

    // видимость пересекающихся линий
    int seenL(Point One, Point Two, Point Three, Point Four);

    // видимость поверхностей, если линии не пересекаются
    void seenS(Point a1, Point a2, Point a3, Point a4);

    // заливка одной поверхности
    void fill(Point p1, Point p2, Point p3, COLORREF col);

    // закраска всех видимых поверхностей
    void colouring();


};

