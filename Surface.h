#pragma once
#include "graphics.h"
#pragma comment(lib,"graphics.lib")

// ����� ������������
class Surface {
public:
    char* name;
    COLORREF colour;

    Surface(char* nam, COLORREF col);
};

