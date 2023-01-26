#pragma once
#include "Point.h"
#include "Surface.h"
#include "Colours.h"
#include "graphics.h"
#pragma comment(lib,"graphics.lib")


// ����� ������
class Piramid {
public:
    Point A, B, C, D, E, F, G, H, I;

    int col = MAINCOL;

    // ����� ����������
    char name_ABC[4] = "ABC";
    char name_ADC[4] = "ADC";
    char name_ABD[4] = "ABD";
    char name_BCD[4] = "BCD";
    Surface ABC = Surface(name_ABC, RED);
    Surface ADC = Surface(name_ADC, GREEN);
    Surface ABD = Surface(name_ABD, CYAN);
    Surface BCD = Surface(name_BCD, YELLOW);

    // ����� �������������
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

    // ����������� �� 9 ����� ��� ���� ����� �����
    Piramid(Point One, Point Two, Point Three, Point Four, Point Five, Point Six, Point Seven, Point Eight, Point Nine);

    // ���������
    void drawPiramid();

    // ����������
    void moveX(float amt);
    void moveY(float amt);
    void moveZ(float amt);

    // ������� ����� ����� ������ z
    Point rotDotZ(int u, float ang, Point Cen, Point L);
    // ������� ������ ������ z
    void rotateZ(int u);

    // ������� ����� ����� ������ y
    Point rotDotY(int u, float ang, Point Cen, Point L);
    // ������� ������ ������ y
    void rotateY(int u);

    // ������� ����� ����� ������ x
    Point rotDotX(int u, float ang, Point Cen, Point L);
    // ������� ������ ������ x
    void rotateX(int u);

    // ��������������� ����� �����
    Point dotScale(float e, Point Cen, Point L);
    // ��������������� ���� ������
    void scale(float e);

    /*
    Point dot;  // ����� �����������
    // �������� �� ����������� �����
    bool cross(Point a1, Point a2, Point a3, Point a4);

    // ��������� �������������� �����
    int seenL(Point One, Point Two, Point Three, Point Four);

    // ��������� ������������, ���� ����� �� ������������
    void seenS(Point a1, Point a2, Point a3, Point a4);

    // ������� ����� �����������
    void fill(Point p1, Point p2, Point p3, COLORREF col);
*/
    // �������� ���� ������� ������������
    //void colouring();



    //float MAXDIST = 1000.0; //������������ ������� �����
    //float MAXYLINES = 200; //������������ ���������� ����� � �����.
    //float clBk = 3; //���� �� ���������

    //typedef struct Cell CELL; //��������� ������, �� ������� ����� �������� Z-�����.
    

    const int width = 1400;
    const int height = 700;
    const int depth = 255;

    int minInt = -32767;

    int* zbuffer = NULL;

    // �������� ������� fixit no need????
    void imgCol(int Px, int Py, int Pz, COLORREF colour);

    // �������� ������������
    void triangle(Point t0, Point t1, Point t2, COLORREF colour, int* zbuffer/*, bool doCol*/);

    // z-buffer
    void zBuff(Point One, Point Two, Point Three, Point Four, Point Five, Point Six, Point Seven, Point Eight, Point Nine);


};

