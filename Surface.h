#pragma once
#include "graphics.h"
#pragma comment(lib,"graphics.lib")

// класс поверхностей
class Surface {
public:
    char* name;
    COLORREF colour;

    Surface(char* nam, COLORREF col);
};

