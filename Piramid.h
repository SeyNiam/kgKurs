#pragma once
#include "Point.h"
#include "Surface.h"
#include "Colours.h"
#include "graphics.h"
#pragma comment(lib,"graphics.lib")


// класс фигуры
class Piramid {
public:
    Point A, B, C, D, E, F, G, H, I;

    int col = MAINCOL;

    // грани трёхгранной
    char name_ABC[4] = "ABC";
    char name_ADC[4] = "ADC";
    char name_ABD[4] = "ABD";
    char name_BCD[4] = "BCD";
    Surface ABC = Surface(name_ABC, RED);
    Surface ADC = Surface(name_ADC, GREEN);
    Surface ABD = Surface(name_ABD, CYAN);
    Surface BCD = Surface(name_BCD, YELLOW);

    // грани четырёхгранной
    char name_EFGH[5] = "EFGH";
    char name_EFI[4] = "EFI";
    char name_FGI[4] = "FGI";
    char name_GHI[4] = "GHI";
    char name_EHI[4] = "EHI";
    Surface EFGH = Surface(name_EFGH, RED);
    Surface EFI = Surface(name_EFI, GREEN);
    Surface FGI = Surface(name_FGI, CYAN);
    Surface GHI = Surface(name_GHI, YELLOW);
    Surface EHI = Surface(name_EHI, WHITE);

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

    /*
    Point dot;  // точка пересечения
    // проверка на пересечение линий
    bool cross(Point a1, Point a2, Point a3, Point a4);

    // видимость пересекающихся линий
    int seenL(Point One, Point Two, Point Three, Point Four);

    // видимость поверхностей, если линии не пересекаются
    void seenS(Point a1, Point a2, Point a3, Point a4);

    // заливка одной поверхности
    void fill(Point p1, Point p2, Point p3, COLORREF col);
*/
    // закраска всех видимых поверхностей
    //void colouring();



    //float MAXDIST = 1000.0; //Максимальная глубина сцены
    //float MAXYLINES = 200; //Максимальное количество линий в сцене.
    //float clBk = 3; //Цвет по умолчанию

    //typedef struct Cell CELL; //Структура ячейки, из которых будет состоять Z-буфер.
    

    const int width = 1400;
    const int height = 700;
    const int depth = 255;

    int minInt = -32767;

    int* zbuffer = NULL;

    // закраска пиксела fixit no need????
    void imgCol(int Px, int Py, int Pz, COLORREF colour);

    // закраска треугольника
    void triangle(Point t0, Point t1, Point t2, COLORREF colour, int* zbuffer/*, bool doCol*/);

    // z-buffer
    void zBuff(Point One, Point Two, Point Three, Point Four, Point Five, Point Six, Point Seven, Point Eight, Point Nine);


};

