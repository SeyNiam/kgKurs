
#include <iostream>
#include <math.h>
#include "graphics.h"
#pragma comment(lib,"graphics.lib")

#include "Point.h"
#include "Surface.h"
#include "Piramid.h"

#define P 3.14
#define TEXTCOL 13 // ��������
#define MAINCOL 13 
#define WHITE 15
#define BLACK 0

#define GREEN 2
#define CYAN 11
#define RED	4
#define YELLOW	14

using namespace std;


// ��������� ����� �����������
void line_DDA(float x1, float y1, float z1, float x2, float y2, float z2, COLORREF cColor) {
    // ���� ���������� z ��� ��������� � ��������� ������������
    x1 -= 0.5 * z1;
    y1 += 0.5 * z1;
    x2 -= 0.5 * z2;
    y2 += 0.5 * z2;

    // ������������� �������� ��������� ������ � ����� �������, ���������� �� ���������� ������
    int iX1 = roundf(x1);
    int iY1 = roundf(y1);
    int iX2 = roundf(x2);
    int iY2 = roundf(y2);

    // ����� � ������ �����
    int deltaX = abs(iX1 - iX2);
    int deltaY = abs(iY1 - iY2);

    // ������� ����������� ���������� ��������, ����������� ��� ��������� �������
    // ������� �������� �� ����� � ������ �����, ������������ ��������� �����
    int length = max(deltaX, deltaY);

    // ������ ������, �� ������ ������������� ����� ���� �������
    if (length == 0) {
        putpixel(iX1, iY1, cColor);
        return;
    }
    // ��������� ���������� �� ������ ���� �� ���� ������� � �������
    double dX = (x2 - x1) / length;
    double dY = (y2 - y1) / length;

    // ��������� ��������
    double x = x1;
    double y = y1;

    // �������� ����
    length++;
    while (length--) {
        x += dX;
        y += dY;
        putpixel(roundf(x), roundf(y), cColor);
    }
}



// ����������� �� 4 �����
Piramid::Piramid(Point One, Point Two, Point Three, Point Four) {
    A.x = One.x; A.y = One.y; A.z = One.z; A.name = name_A;
    B.x = Two.x; B.y = Two.y; B.z = Two.z; B.name = name_B;
    C.x = Three.x; C.y = Three.y; C.z = Three.z; C.name = name_C;
    D.x = Four.x; D.y = Four.y; D.z = Four.z; D.name = name_D;
    drawPiramid();
}

// ���������
void Piramid::drawPiramid() {
    // ���
    setcolor(WHITE);
    line(700, 350, 730, 350);
    line(700, 350, 700, 320);
    line(700, 350, 685, 365);

    char w[20] = "W - Up";
    char a[20] = "A - Left";
    char s[20] = "S - Down";
    char d[20] = "D - Right";
    char z[20] = "Z - Forward";
    char x[20] = "X - Backward";
    char qrf[30] = "Q, R, F - Counter clockwise";
    char etg[20] = "E, T, G - Clockwise";
    char plus[20] = "+ - Scale up";
    char minus[20] = "- - Scale down";
    char other[20] = "Any other - Exit";

    // ����� ����������
    outtextxy(1140, 20, w);
    outtextxy(1140, 40, a);
    outtextxy(1140, 60, s);
    outtextxy(1140, 80, d);
    outtextxy(1140, 100, z);
    outtextxy(1140, 120, x);
    outtextxy(1140, 140, qrf);
    outtextxy(1140, 160, etg);
    outtextxy(1140, 180, plus);
    outtextxy(1140, 200, minus);
    outtextxy(1140, 220, other);

    // ����� ��� �����
    setcolor(TEXTCOL);
    A.namePoint(A.name);
    B.namePoint(B.name);
    C.namePoint(C.name);
    D.namePoint(D.name);

    // ������ ���������
    line_DDA(A.x, A.y, A.z, B.x, B.y, B.z, col); // ����� 1
    line_DDA(B.x, B.y, B.z, C.x, C.y, C.z, col); // ����� 2
    line_DDA(C.x, C.y, C.z, A.x, A.y, A.z, col); // ����� 3

    // ������� �����
    line_DDA(D.x, D.y, D.z, A.x, A.y, A.z, col); // ����� 4
    line_DDA(D.x, D.y, D.z, B.x, B.y, B.z, col); // ����� 5
    line_DDA(D.x, D.y, D.z, C.x, C.y, C.z, col); // ����� 6

    // �������� ������ ������
    colouring();

}

// ����������
void Piramid::moveX(float amt) {
    A.x += amt;
    B.x += amt;
    C.x += amt;
    D.x += amt;
}
void Piramid::moveY(float amt) {
    A.y += amt;
    B.y += amt;
    C.y += amt;
    D.y += amt;
}
void Piramid::moveZ(float amt) {
    A.z += amt;
    B.z += amt;
    C.z += amt;
    D.z += amt;
}

// ������� ����� ����� ������ z
Point Piramid::rotDotZ(int u, float ang, Point Cen, Point L) {
    L.x = L.x - Cen.x; // ���������� �� � �� ������ �� �
    L.y = L.y - Cen.y; // �� �

    float tmpX = L.x * cos(ang) + L.y * sin(ang);
    float tmpY = -L.x * sin(ang) + L.y * cos(ang);
    L.x = tmpX + Cen.x;
    L.y = tmpY + Cen.y;

    return L;
}
// ������� ������ ������ z
void Piramid::rotateZ(int u) { // u = -1 �� �������, u = 1 ������
    float ang = u * 0.05; // ���� ��������

    Point Cen; // ����� ������ 
    Cen.x = (A.x + B.x + C.x + D.x) / 4;
    Cen.y = (A.y + B.y + C.y + D.y) / 4;
    Cen.z = (A.z + B.z + C.z + D.z) / 4;

    A = rotDotZ(u, ang, Cen, A);
    B = rotDotZ(u, ang, Cen, B);
    C = rotDotZ(u, ang, Cen, C);
    D = rotDotZ(u, ang, Cen, D);
}

// ������� ����� ����� ������ y
Point Piramid::rotDotY(int u, float ang, Point Cen, Point L) {
    L.x = L.x - Cen.x; // ���������� �� � �� ������ �� y
    L.z = L.z - Cen.z; // �� z

    float tmpX = L.x * cos(ang) + L.z * sin(ang);
    float tmpZ = -L.x * sin(ang) + L.z * cos(ang);
    L.x = tmpX + Cen.x;
    L.z = tmpZ + Cen.z;

    return L;
}
// ������� ������ ������ y
void Piramid::rotateY(int u) { // u = -1 �� �������, u = 1 ������
    float ang = u * 0.05; // ���� ��������

    Point Cen; // ����� ������ 
    Cen.x = (A.x + B.x + C.x + D.x) / 4;
    Cen.y = (A.y + B.y + C.y + D.y) / 4;
    Cen.z = (A.z + B.z + C.z + D.z) / 4;

    A = rotDotY(u, ang, Cen, A);
    B = rotDotY(u, ang, Cen, B);
    C = rotDotY(u, ang, Cen, C);
    D = rotDotY(u, ang, Cen, D);
}

// ������� ����� ����� ������ x
Point Piramid::rotDotX(int u, float ang, Point Cen, Point L) {
    L.y = L.y - Cen.y; // ���������� �� � �� ������ �� y
    L.z = L.z - Cen.z; // �� z

    float tmpY = L.y * cos(ang) + L.z * sin(ang);
    float tmpZ = -L.y * sin(ang) + L.z * cos(ang);
    L.y = tmpY + Cen.y;
    L.z = tmpZ + Cen.z;

    return L;
}
// ������� ������ ������ x
void Piramid::rotateX(int u) { // u = -1 �� �������, u = 1 ������
    float ang = u * 0.05; // ���� ��������

    Point Cen; // ����� ������
    Cen.x = (A.x + B.x + C.x + D.x) / 4;
    Cen.y = (A.y + B.y + C.y + D.y) / 4;
    Cen.z = (A.z + B.z + C.z + D.z) / 4;

    A = rotDotX(u, ang, Cen, A);
    B = rotDotX(u, ang, Cen, B);
    C = rotDotX(u, ang, Cen, C);
    D = rotDotX(u, ang, Cen, D);
}

// ��������������� ����� �����
Point Piramid::dotScale(float e, Point Cen, Point L) {
    // L.x
    float xe = (Cen.x + L.x) / 2;
    float lx = Cen.x - L.x;
    lx = lx * e;
    L.x = xe - lx / 2;
    // L.y
    float ye = (Cen.y + L.y) / 2;
    float ly = Cen.y - L.y;
    ly = ly * e;
    L.y = ye - ly / 2;
    // L.z
    float ze = (Cen.z + L.z) / 2;
    float lz = Cen.z - L.z;
    lz = lz * e;
    L.z = ze - lz / 2;

    return L;
}
// ��������������� ���� ������
void Piramid::scale(float e) {
    Point Cen; // ����� ������ 
    Cen.x = (A.x + B.x + C.x + D.x) / 4;
    Cen.y = (A.y + B.y + C.y + D.y) / 4;
    Cen.z = (A.z + B.z + C.z + D.z) / 4;

    if (((abs(A.x - Cen.x) >= 1 && abs(A.y - Cen.y) >= 1 && abs(A.z - Cen.z) >= 1) &&
        (abs(B.x - Cen.x) >= 1 && abs(B.y - Cen.y) >= 1 && abs(B.z - Cen.z) >= 1) &&
        (abs(C.x - Cen.x) >= 1 && abs(C.y - Cen.y) >= 1 && abs(C.z - Cen.z) >= 1) &&
        (abs(D.x - Cen.x) >= 1 && abs(D.y - Cen.y) >= 1 && abs(D.z - Cen.z) >= 1)
        ) || e > 1) { // �������������� ������ � �����

        A = dotScale(e, Cen, A);
        B = dotScale(e, Cen, B);
        C = dotScale(e, Cen, C);
        D = dotScale(e, Cen, D);
    }

}


// �������� �� ����������� �����
bool Piramid::cross(Point a1, Point a2, Point a3, Point a4) {
    Point p1 = a1, p2 = a2, p3 = a3, p4 = a4;

    // ���� ���������� z ��� ��������� � ��������� ������������
    // ����� ����������� ��������� �� ����� ����� ��� z, � ��� ����� 45, ��� ����� ������������
    p1.x -= 0.5 * p1.z;        p1.y += 0.5 * p1.z;
    p2.x -= 0.5 * p2.z;        p2.y += 0.5 * p2.z;
    p3.x -= 0.5 * p3.z;        p3.y += 0.5 * p3.z;
    p4.x -= 0.5 * p4.z;        p4.y += 0.5 * p4.z;

    // ����������� ����� ���, ����� ��������� ����� ���������� ����� �������� ������������ ��� x
    if (p2.x < p1.x) {
        Point tmp = p1;
        p1 = p2;
        p2 = tmp;
    }
    if (p4.x < p3.x) {
        Point tmp = p3;
        p3 = p4;
        p4 = tmp;
    }

    // ���� ����� ������� ������� ��������� ����� ������ �������, �� ������� ����� �� ������������
    if (p2.x < p3.x) { return false; }

    // ���� ��� ������� ������������
    if ((p1.x - p2.x == 0) && (p3.x - p4.x == 0)) {
        // ���� ��� ����� �� ����� X
        if (p1.x == p3.x) {
            // �������� ������������ �� ���, �.�. ���� �� � ��� ����� Y
            // ������ ��������� �� ������, ����� ��� �� ������������
            if (!((max(p1.y, p2.y) < min(p3.y, p4.y)) ||
                (min(p1.y, p2.y) > max(p3.y, p4.y)))) {
                dot.x = p1.x;
                dot.y = (p1.y + p2.y) / 2;
                return true;
            }
        }
        return false;
    }

    // ���� ������ ������� ������������
    if (p1.x - p2.x == 0) {
        // Xa, Ya - ����� ����������� ���� ������
        double Xa = p1.x;
        double A2 = (p3.y - p4.y) / (p3.x - p4.x); // A � ������� ���� ����� ������ � ���� x
        double b2 = p3.y - A2 * p3.x; // b � �������� ������������ ���
        double Ya = A2 * Xa + b2;

        // ��������, ��� ����� ����������� ��������
        if (p3.x <= Xa && p4.x >= Xa && min(p1.y, p2.y) <= Ya && max(p1.y, p2.y) >= Ya) {
            dot.x = Xa;
            dot.y = Ya;
            return true;
        }

        return false;
    }

    // ���� ������ ������� ������������
    if (p3.x - p4.x == 0) {
        // Xa, Ya - ����� ����������� ���� ������
        double Xa = p3.x;
        double A1 = (p1.y - p2.y) / (p1.x - p2.x);
        double b1 = p1.y - A1 * p1.x;
        double Ya = A1 * Xa + b1;

        if (p1.x <= Xa && p2.x >= Xa && min(p3.y, p4.y) <= Ya && max(p3.y, p4.y) >= Ya) {
            dot.x = Xa;
            dot.y = Ya;
            return true;
        }

        return false;
    }

    // ��� ������� ��������������
    double A1 = (p1.y - p2.y) / (p1.x - p2.x);
    double A2 = (p3.y - p4.y) / (p3.x - p4.x);
    double b1 = p1.y - A1 * p1.x;
    double b2 = p3.y - A2 * p3.x;

    if (A1 == A2) { return false; } // ������� �����������

    // Xa - �������� ����� ����������� ���� ������
    double Xa = (b2 - b1) / (A1 - A2);
    double Ya = A1 * Xa + b1; // Ya - ��������

    // ��������, ��� ����� ���������� ��������� � �������� �������
    if ((Xa < max(p1.x, p3.x)) || (Xa > min(p2.x, p4.x))) {
        return false; // ����� Xa ��������� ��� ����������� �������� �������� �� ��� X
    }
    else {
        dot.x = Xa;
        dot.y = Ya;
        return true;
    }

}

// ��������� �������������� �����
int Piramid::seenL(Point One, Point Two, Point Three, Point Four) {

    if (cross(One, Two, Three, Four)) {

        cout << "Lines " << One.name << Two.name << " and " << Three.name << Four.name << " cross at " << dot.x << ";" << dot.y << ".\n";

        // ��������� ���������� z ��� ����� � ������������ ����� ����������� �� ������ �� �����
        int x1 = One.x - 0.5 * One.z, x2 = Two.x - 0.5 * Two.z; // ���� ���������� z ��� ��������� � ��������� ������������
        int z1 = One.z, z2 = Two.z;
        int x = dot.x;

        if ((x2 - x1) != 0) {

            int zOT = (((x - x1) * (z2 - z1)) / (x2 - x1)) + z1;
            x1 = Three.x - 0.5 * Three.z, x2 = Four.x - 0.5 * Four.z; // ���� ���������� z ��� ��������� � ��������� ������������
            z1 = Three.z, z2 = Four.z;

            if ((x2 - x1) != 0) {
                int zTF = (((x - x1) * (z2 - z1)) / (x2 - x1)) + z1;

                if (zOT == zTF)
                    cout << "\n\n\tsame point\n\n";
                // ���� ������ ����� ����� � �����������, ��� ������
                else if (zOT > zTF) {
                    cout << "line " << Three.name << Four.name << " is not seen.\n";
                    // ���� ��������� �������� ��� ����� ��������� �����
                    if (strstr(ABC.name, Three.name) && strstr(ABC.name, Four.name))
                        ABC.isVisible = false; // �� � ��� ���� �� �����
                    else ABC.isVisible = true; // ����� �����
                    if (strstr(ADC.name, Three.name) && strstr(ADC.name, Four.name))
                        ADC.isVisible = false;
                    else ADC.isVisible = true;
                    if (strstr(ABD.name, Three.name) && strstr(ABD.name, Four.name))
                        ABD.isVisible = false;
                    else ABD.isVisible = true;
                    if (strstr(BCD.name, Three.name) && strstr(BCD.name, Four.name))
                        BCD.isVisible = false;
                    else BCD.isVisible = true;
                }
                // ���� ������ ����� ����� � �����������, ��� ������
                else if (zOT < zTF) {
                    cout << "line " << One.name << Two.name << " is not seen.\n";
                    if (strstr(ABC.name, One.name) && strstr(ABC.name, Two.name))
                        ABC.isVisible = false;
                    else ABC.isVisible = true;
                    if (strstr(ADC.name, One.name) && strstr(ADC.name, Two.name))
                        ADC.isVisible = false;
                    else ADC.isVisible = true;
                    if (strstr(ABD.name, One.name) && strstr(ABD.name, Two.name))
                        ABD.isVisible = false;
                    else ABD.isVisible = true;
                    if (strstr(BCD.name, One.name) && strstr(BCD.name, Two.name))
                        BCD.isVisible = false;
                    else BCD.isVisible = true;
                }

            }
        }


        return 1;
    }
    else return 0; // ���� ����� �� ������������

}

// ��������� ������������, ���� ����� �� ������������
void Piramid::seenS(Point a1, Point a2, Point a3, Point a4) {
    Point p1 = a1, p2 = a2, p3 = a3, p4 = a4;

    // ���� ���������� z ��� ��������� � ��������� ������������
    // ����� ����������� ��������� �� ����� ����� ��� z, � ��� ����� 45, ��� ����� ������������
    p1.x -= 0.5 * p1.z, p1.y += 0.5 * p1.z;
    p2.x -= 0.5 * p2.z, p2.y += 0.5 * p2.z;
    p3.x -= 0.5 * p3.z, p3.y += 0.5 * p3.z;
    p4.x -= 0.5 * p4.z, p4.y += 0.5 * p4.z;

    // ��� ������������ -- ���� �� ����� � ������ �� xoy
    // ����� � ������ �����, � ��� � ������� z
    Point centerOfAll; // ����� ������ ������
    centerOfAll.x = (p1.x + p2.x + p3.x + p4.x) / 4;
    centerOfAll.y = (p1.y + p2.y + p3.y + p4.y) / 4;

    int p1Prox, p2Prox, p3Prox, p4Prox; // ���������� �� ������ ������� �� ������ ������ �� ��������� xoy
    p1Prox = abs(p1.x - centerOfAll.x) + abs(p1.y - centerOfAll.y);
    p2Prox = abs(p2.x - centerOfAll.x) + abs(p2.y - centerOfAll.y);
    p3Prox = abs(p3.x - centerOfAll.x) + abs(p3.y - centerOfAll.y);
    p4Prox = abs(p4.x - centerOfAll.x) + abs(p4.y - centerOfAll.y);

    int res = min(min(p1Prox, p2Prox), min(p3Prox, p4Prox)); // ���������� �� ������ ������ �� ��������� �����

    Point closestPt; // �����, ��������� � ������ ������
    float surfCen; // ���������� z ������ ������
    if (res == p1Prox) { // ���� p1Prox ��������� ����������
        closestPt = p1; // �� ����� p1 - ��������� �����
        surfCen = (p2.z + p3.z + p4.z) / 3; // ������������������� z ������ ���������, �� ���������� ��� �����
    }
    if (res == p2Prox) {
        closestPt = p2;
        surfCen = (p1.z + p3.z + p4.z) / 3;
    }
    if (res == p3Prox) {
        closestPt = p3;
        surfCen = (p1.z + p2.z + p4.z) / 3;
    }
    if (res == p4Prox) {
        closestPt = p4;
        surfCen = (p1.z + p2.z + p3.z) / 3;
    }

    // ���� ��������� � ������ ����� ��������� ����� � �������, ��� �����
    if (closestPt.z >= surfCen) {
        cout << "\n\n\t THE Point " << closestPt.name << " is VISIBLE.\n\n";

        // �� ��������� ��� ����������� �����
        ABC.isVisible = true;
        ADC.isVisible = true;
        ABD.isVisible = true;
        BCD.isVisible = true;

        // ���� ����������� �� �������� ������� �����
        if (!strstr(ABC.name, closestPt.name))
            ABC.isVisible = false; // �� ��� ����������� �� �����
        else ABC.isVisible = true; // ����� �����
        if (!strstr(ADC.name, closestPt.name))
            ADC.isVisible = false;
        else ADC.isVisible = true;
        if (!strstr(ABD.name, closestPt.name))
            ABD.isVisible = false;
        else ABD.isVisible = true;
        if (!strstr(BCD.name, closestPt.name))
            BCD.isVisible = false;
        else BCD.isVisible = true;
    }
    else { // ��������� � ������ ����� ��������� ������ �� �������, ��� �����
        cout << "\n\n\t THE Point " << closestPt.name << " is NOT VISIBLE AT ALL.\n\n";

        // �� ��������� �� ���� ����������� �� �����
        ABC.isVisible = false;
        ADC.isVisible = false;
        ABD.isVisible = false;
        BCD.isVisible = false;

        // ���� ��������� �� �������� ��������� �����
        if (!strstr(ABC.name, closestPt.name))
            ABC.isVisible = true; // �� ��� �����
        if (!strstr(ADC.name, closestPt.name))
            ADC.isVisible = true;
        if (!strstr(ABD.name, closestPt.name))
            ABD.isVisible = true;
        if (!strstr(BCD.name, closestPt.name))
            BCD.isVisible = true;

    }

}

// ������� ����� �����������
void Piramid::fill(Point p1, Point p2, Point p3, COLORREF col) {
    // ���� ���������� z ��� ��������� � ��������� ������������
    // ����� ����������� ��������� �� ����� ����� ��� z, � ��� ����� 45, ��� ����� ������������
    p1.x -= 0.5 * p1.z, p1.y += 0.5 * p1.z;
    p2.x -= 0.5 * p2.z, p2.y += 0.5 * p2.z;
    p3.x -= 0.5 * p3.z, p3.y += 0.5 * p3.z;

    double x1 = p1.x, y1 = p1.y;
    double x2 = p2.x, y2 = p2.y;
    double x3 = p3.x, y3 = p3.y;
    setcolor(col);

    // ���������� ���������, ������� � ������ �����
    if (y2 < y1) {
        swap(y1, y2);
        swap(x1, x2);
    }
    if (y3 < y1) {
        swap(y1, y3);
        swap(x1, x3);
    }
    if (y2 > y3) {
        swap(y2, y3);
        swap(x2, x3);
    }

    float y_const[4]; // x0, y0, x1, y1

    // y1 - ��������� �����, y2 - ������� �����, y3 - ������ �����
    for (int y = y1; y <= y2; y++) {
        y_const[1] = y_const[3] = y; // y0 y1
        y_const[0] = x1 + (x2 - x1) * ((y - y1) / (y2 - y1)); // x0
        y_const[2] = x1 + (x3 - x1) * ((y - y1) / (y3 - y1)); // x1
        line(y_const[0], y_const[1], y_const[2], y_const[3]);
    }
    for (int y = y2; y <= y3; y++) {
        y_const[1] = y_const[3] = y;
        y_const[0] = x2 + (x3 - x2) * ((y - y2) / (y3 - y2));
        y_const[2] = x1 + (x3 - x1) * ((y - y1) / (y3 - y1));
        line(y_const[0], y_const[1], y_const[2], y_const[3]);
    }
}

// �������� ���� ������� ������������
void Piramid::colouring() {
    int abcd = seenL(A, B, C, D);
    int acbd = seenL(A, C, B, D);
    int adbc = seenL(A, D, B, C);

    // ���� ������� ����� �� ������������
    if (abcd != 1 && acbd != 1 && adbc != 1) {
        // ����������� ��������� ��������� ������������ �� ������������� �� ����� 
        seenS(A, B, C, D);
    }

    if (ABC.isVisible) {
        cout << "\n\tABC is visible\n";
        fill(A, B, C, ABC.colour);
    }
    if (ADC.isVisible) {
        cout << "\n\tADC is visible\n";
        fill(A, D, C, ADC.colour);
    }
    if (ABD.isVisible) {
        cout << "\n\tABD is visible\n";
        fill(A, B, D, ABD.colour);
    }
    if (BCD.isVisible) {
        cout << "\n\tBCD is visible\n";
        fill(B, C, D, BCD.colour);
    }

}