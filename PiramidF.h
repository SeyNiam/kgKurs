#pragma once
#include "Point.h"
#include "Surface.h"
#include "Colours.h"
#include "graphics.h"
#pragma comment(lib,"graphics.lib")

class PiramidF {
public:
    Point E, F, G, H, I;
    int col = MAINCOL;

    /**/
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
    

    // конструктор от 5 точек
    PiramidF(Point One, Point Two, Point Three, Point Four, Point Five);

    // отрисовка
    void drawPiramidF();

    // пермещение
    void moveX(float amt);
    void moveY(float amt);
    void moveZ(float amt);
};

