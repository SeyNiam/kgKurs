
#include <iostream>
#include <math.h>
#include "graphics.h"
#pragma comment(lib,"graphics.lib")

#include "Point.h"
#include "Surface.h"
#include "Piramid.h"
#include "Colours.h"

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


// ����� �����
char name_A[2] = "A";
char name_B[2] = "B";
char name_C[2] = "C";
char name_D[2] = "D";

char name_E[2] = "E";
char name_F[2] = "F";
char name_G[2] = "G";
char name_H[2] = "H";
char name_I[2] = "I";


// ����������� �� 9 ����� ����� ��� ���� �����
Piramid::Piramid(Point One, Point Two, Point Three, Point Four, Point Five, Point Six, Point Seven, Point Eight, Point Nine) {
    A.x = One.x; A.y = One.y; A.z = One.z; A.name = name_A;
    B.x = Two.x; B.y = Two.y; B.z = Two.z; B.name = name_B;
    C.x = Three.x; C.y = Three.y; C.z = Three.z; C.name = name_C;
    D.x = Four.x; D.y = Four.y; D.z = Four.z; D.name = name_D;

    E.x = Five.x; E.y = Five.y; E.z = Five.z; E.name = name_E;
    F.x = Six.x; F.y = Six.y; F.z = Six.z; F.name = name_F;
    G.x = Seven.x; G.y = Seven.y; G.z = Seven.z; G.name = name_G;
    H.x = Eight.x; H.y = Eight.y; H.z = Eight.z; H.name = name_H;
    I.x = Nine.x; I.y = Nine.y; I.z = Nine.z; I.name = name_I;
    drawPiramid();
}


// ���������
void Piramid::drawPiramid() {
    // ���
    setcolor(WHITE);
    line(700, 350, 730, 350); char xCoord[2] = "x"; outtextxy(735, 350, xCoord);
    line(700, 350, 700, 320); char yCoord[2] = "y"; outtextxy(700, 300, yCoord);
    line(700, 350, 685, 365); char zCoord[2] = "z"; outtextxy(680, 370, zCoord);

    // ����������
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

    E.namePoint(E.name);
    F.namePoint(F.name);
    G.namePoint(G.name);
    H.namePoint(H.name);
    I.namePoint(I.name);

    // ����������
    // ������ ���������
    line_DDA(A.x, A.y, A.z, B.x, B.y, B.z, col); // ����� 1
    line_DDA(B.x, B.y, B.z, C.x, C.y, C.z, col); // ����� 2
    line_DDA(C.x, C.y, C.z, A.x, A.y, A.z, col); // ����� 3

    // ������� �����
    line_DDA(D.x, D.y, D.z, A.x, A.y, A.z, col); // ����� 4
    line_DDA(D.x, D.y, D.z, B.x, B.y, B.z, col); // ����� 5
    line_DDA(D.x, D.y, D.z, C.x, C.y, C.z, col); // ����� 6


    // �������������
    // ������ ���������
    line_DDA(E.x, E.y, E.z, F.x, F.y, F.z, col); // ����� 1
    line_DDA(F.x, F.y, F.z, G.x, G.y, G.z, col); // ����� 2
    line_DDA(G.x, G.y, G.z, H.x, H.y, H.z, col); // ����� 3
    line_DDA(H.x, H.y, H.z, E.x, E.y, E.z, col); // ����� 4

    // ������� �����
    line_DDA(I.x, I.y, I.z, E.x, E.y, E.z, col); // ����� 5
    line_DDA(I.x, I.y, I.z, F.x, F.y, F.z, col); // ����� 6
    line_DDA(I.x, I.y, I.z, G.x, G.y, G.z, col); // ����� 7
    line_DDA(I.x, I.y, I.z, H.x, H.y, H.z, col); // ����� 8



    // �������� ������ ������
   // colouring();


    zBuff(A, B, C, D, E, F, G, H, I);

}

// ����������
void Piramid::moveX(float amt) {
    A.x += amt;
    B.x += amt;
    C.x += amt;
    D.x += amt;

    E.x += amt;
    F.x += amt;
    G.x += amt;
    H.x += amt;
    I.x += amt;
}
void Piramid::moveY(float amt) {
    A.y += amt;
    B.y += amt;
    C.y += amt;
    D.y += amt;

    E.y += amt;
    F.y += amt;
    G.y += amt;
    H.y += amt;
    I.y += amt;
}
void Piramid::moveZ(float amt) {
    A.z += amt;
    B.z += amt;
    C.z += amt;
    D.z += amt;

    E.z += amt;
    F.z += amt;
    G.z += amt;
    H.z += amt;
    I.z += amt;
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
    Cen.x = (A.x + B.x + C.x + D.x + E.x + F.x + G.x + H.x + I.x) / 9;
    Cen.y = (A.y + B.y + C.y + D.y + E.y + F.y + G.y + H.y + I.y) / 9;
    Cen.z = (A.z + B.z + C.z + D.z + E.z + F.z + G.z + H.z + I.z) / 9;

    A = rotDotZ(u, ang, Cen, A);
    B = rotDotZ(u, ang, Cen, B);
    C = rotDotZ(u, ang, Cen, C);
    D = rotDotZ(u, ang, Cen, D);

    E = rotDotZ(u, ang, Cen, E);
    F = rotDotZ(u, ang, Cen, F);
    G = rotDotZ(u, ang, Cen, G);
    H = rotDotZ(u, ang, Cen, H);
    I = rotDotZ(u, ang, Cen, I);
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
    Cen.x = (A.x + B.x + C.x + D.x + E.x + F.x + G.x + H.x + I.x) / 9;
    Cen.y = (A.y + B.y + C.y + D.y + E.y + F.y + G.y + H.y + I.y) / 9;
    Cen.z = (A.z + B.z + C.z + D.z + E.z + F.z + G.z + H.z + I.z) / 9;

    A = rotDotY(u, ang, Cen, A);
    B = rotDotY(u, ang, Cen, B);
    C = rotDotY(u, ang, Cen, C);
    D = rotDotY(u, ang, Cen, D);

    E = rotDotY(u, ang, Cen, E);
    F = rotDotY(u, ang, Cen, F);
    G = rotDotY(u, ang, Cen, G);
    H = rotDotY(u, ang, Cen, H);
    I = rotDotY(u, ang, Cen, I);
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
    Cen.x = (A.x + B.x + C.x + D.x + E.x + F.x + G.x + H.x + I.x) / 9;
    Cen.y = (A.y + B.y + C.y + D.y + E.y + F.y + G.y + H.y + I.y) / 9;
    Cen.z = (A.z + B.z + C.z + D.z + E.z + F.z + G.z + H.z + I.z) / 9;

    A = rotDotX(u, ang, Cen, A);
    B = rotDotX(u, ang, Cen, B);
    C = rotDotX(u, ang, Cen, C);
    D = rotDotX(u, ang, Cen, D);

    E = rotDotX(u, ang, Cen, E);
    F = rotDotX(u, ang, Cen, F);
    G = rotDotX(u, ang, Cen, G);
    H = rotDotX(u, ang, Cen, H);
    I = rotDotX(u, ang, Cen, I);
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
    Cen.x = (A.x + B.x + C.x + D.x + E.x + F.x + G.x + H.x + I.x) / 9;
    Cen.y = (A.y + B.y + C.y + D.y + E.y + F.y + G.y + H.y + I.y) / 9;
    Cen.z = (A.z + B.z + C.z + D.z + E.z + F.z + G.z + H.z + I.z) / 9;

    if (((abs(A.x - Cen.x) >= 0.1 && abs(A.y - Cen.y) >= 0.1 && abs(A.z - Cen.z) >= 0.1) &&
        (abs(B.x - Cen.x) >= 0.1 && abs(B.y - Cen.y) >= 0.1 && abs(B.z - Cen.z) >= 0.1) &&
        (abs(C.x - Cen.x) >= 0.1 && abs(C.y - Cen.y) >= 0.1 && abs(C.z - Cen.z) >= 0.1) &&
        (abs(D.x - Cen.x) >= 0.1 && abs(D.y - Cen.y) >= 0.1 && abs(D.z - Cen.z) >= 0.1) &&
        (abs(E.x - Cen.x) >= 0.1 && abs(E.y - Cen.y) >= 0.1 && abs(E.z - Cen.z) >= 0.1) &&
        (abs(F.x - Cen.x) >= 0.1 && abs(F.y - Cen.y) >= 0.1 && abs(F.z - Cen.z) >= 0.1) &&
        (abs(G.x - Cen.x) >= 0.1 && abs(G.y - Cen.y) >= 0.1 && abs(G.z - Cen.z) >= 0.1) &&
        (abs(H.x - Cen.x) >= 0.1 && abs(H.y - Cen.y) >= 0.1 && abs(H.z - Cen.z) >= 0.1) &&
        (abs(I.x - Cen.x) >= 0.1 && abs(I.y - Cen.y) >= 0.1 && abs(I.z - Cen.z) >= 0.1)
        ) && e < 1 || e > 1) { // �������������� ������ � �����

        A = dotScale(e, Cen, A);
        B = dotScale(e, Cen, B);
        C = dotScale(e, Cen, C);
        D = dotScale(e, Cen, D);

        E = dotScale(e, Cen, E);
        F = dotScale(e, Cen, F);
        G = dotScale(e, Cen, G);
        H = dotScale(e, Cen, H);
        I = dotScale(e, Cen, I);
    }

}








/*
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
*/

// fixit ��� �� ����??
void Piramid::imgCol(int Px, int Py, int Pz, COLORREF colour) {
    // ���� ���������� z ��� ��������� � ��������� ������������
    // ����� ����������� ��������� �� ����� ����� ��� z, � ��� ����� 45, ��� ����� ������������
    Px -= 0.5 * Pz;
    Py += 0.5 * Pz;

    putpixel(Px, Py, colour);
}


/*
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
*/
// �������� ���� ������� ������������
/*
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
*/



// z-buffer
/*
void zBuff() {
    //�������� ������� ��������� ������ ������� (���������)
    //    for(each face F) //��� ������ ����� F
    //     for (each pixel(x,y) covering the face) //��� ������� ������� (x,y) ������������ �����
    //        {depth = depth of F at (x,y);//������� F � (x,y)
    //     if (depth < d[x][y]) //���� F ��������� �����
    //        {C = color of F at (x,y); //���� ����� F � �.(x,y)
    //     //set the pixel color at (x,y) to C
    //     //������������� ���� ������� � (x,y) ������ C
    //     d[x][y] = depth; //��������� ����� �������}}


    // ������� https://rudocs.exdat.com/docs/index-538930.html
    
    // ������������� Z - ������ � ������ �����������(������ �����):
    const int x = 1, y = 1;
    float depth[x][y] = { 1 }; //�������� �������
    int background = 0;
    int refresh[x][y] = { background }; //� ����� ��������� �������� ����


    // ����� ���������� http://www.opita.net/node/58
    
    //#define MAXDIST 1000.0 //������������ ������� �����
    //#define MAXYLINES 200 //������������ ���������� ����� � �����.
    //#define clBk 3; //���� �� ���������
    //
    //typedef struct Cell CELL; //��������� ������, �� ������� ����� �������� Z-�����.
    //struct Cell {
    //    double z;
    //    int color;
    //};
    //
    ////����� Z-������.
    //class ZBuffer {
    //public:
    //    CELL* buff[MAXYLINES];
    //    int sX, sY;	// ������ Z-������
    //
    //    ZBuffer(int ax, int ay) {
    //        sX = ax; sY = ay;
    //        for (int i = 0; i < sY; i++) {
    //            //��������� ������ ��� ������
    //            buff[i] = (struct Cell*)malloc(sX * sizeof(struct Cell));
    //        }
    //    }
    //
    //    ~ZBuffer() {
    //        for (int i = 0; i < sY; i++)
    //            free(buff[i]); //������������ ������
    //    }
    //
    //    void PutTriangle(Triangle& t) {
    //        int ymax, ymin, ysc, e1, e, i;
    //        int x[3], y[3];
    //        //������� x,y �� t � ������� ��� ����������� ������ � ����
    //        for (i = 0; i < 3; i++)
    //            x[i] = int(t.p[i].x), y[i] = int(t.p[i].y);
    //        //���������� ������������ � ����������� y
    //        ymax = ymin = y[0];
    //        if (ymax < y[1]) ymax = y[1]; else if (ymin > y[1]) ymin = y[1];
    //        if (ymax < y[2]) ymax = y[2]; else if (ymin > y[2]) ymin = y[2];
    //        ymin = (ymin < 0) ? 0 : ymin;
    //        ymax = (ymax < sY) ? ymax : sY;
    //        int ne;
    //        int x1, x2, xsc1, xsc2;
    //        double z1, z2, tc, z;
    //        //��������� ������� ���� ���������� ��� ������ �����
    //        //� ���������� ������� ������� �������
    //        //��� ���������������� ������������
    //        for (ysc = ymin; ysc < ymax; ysc++) {
    //            ne = 0;
    //            for (int e = 0; e < 3; e++) {
    //                e1 = e + 1;
    //                if (e1 == 3) e1 = 0;
    //                if (y[e] < y[e1]) {
    //                    if (y[e1] <= ysc || ysc < y[e]) continue;
    //                }
    //                else if (y[e] > y[e1]) {
    //                    if (y[e1] > ysc || ysc >= y[e]) continue;
    //                }
    //                else continue;
    //                tc = double(y[e] - ysc) / (y[e] - y[e1]);
    //                if (ne)
    //                    x2 = x[e] + int(tc * (x[e1] - x[e])),
    //                    z2 = t.p[e].z + tc * (t.p[e1].z - t.p[e].z);
    //                else
    //                    x1 = x[e] + int(tc * (x[e1] - x[e])),
    //                    z1 = t.p[e].z + tc * (t.p[e1].z - t.p[e].z),
    //                    ne = 1;
    //            }
    //            if (x2 < x1) e = x1, x1 = x2, x2 = e, tc = z1, z1 = z2, z2 = tc;
    //            xsc1 = (x1 < 0) ? 0 : x1;
    //            xsc2 = (x2 < sX) ? x2 : sX;
    //            for (int xsc = xsc1; xsc < xsc2; xsc++) {
    //                tc = double(x1 - xsc) / (x1 - x2);
    //                z = z1 + tc * (z2 - z1);
    //                //���� ���������� ������� ������� ������ ���,
    //                //��� ��������� � Z-������ - �������� ���������� �� �����.
    //                if (z < (*(buff[ysc] + xsc)).z)
    //                    (*(buff[ysc] + xsc)).color = t.color,
    //                    (*(buff[ysc] + xsc)).z = z;
    //            }
    //        }
    //    }
    //    
    //    //�������, ��������� �� ����� ���������� ������������ Z-������.
    //    void Show() {
    //        for (int j = 0; j < sY; j++)
    //            for (int i = 0; i < sX; i++)
    //                //������� ������� �� �����
    //                Form1->Canvas->Pixels[50 + i][j] = clBlue / (*(buff[j] + i)).color;
    //    }
    //
    //    //�������, '���������' Z-�����.
    //    void Clear() { 
    //        for (int j = 0; j < sY; j++)
    //            for (int i = 0; i < sX; i++)
    //                //�������������� ������ Z-������
    //                (*(buff[j] + i)).z = MAXDIST, (*(buff[j] + i)).color = clBk;
    //    }
    //};


}
*/


// todo ����������� ��� ���-�� ��� �� ���, ������ ��� ������ ����������

// �������� ��������������
void Piramid::triangle(Point t0, Point t1, Point t2, COLORREF colour, int** zbuffer/*, bool doCol*/) {
    // ���� ���������� z ��� ��������� � ��������� ������������
    // ����� ����������� ��������� �� ����� ����� ��� z, � ��� ����� 45, ��� ����� ������������
    t0.x -= 0.5 * t0.z; t0.y += 0.5 * t0.z;
    t1.x -= 0.5 * t1.z; t1.y += 0.5 * t1.z;
    t2.x -= 0.5 * t2.z; t2.y += 0.5 * t2.z; 

    // ���������� ����� �� ���������� �
    if (t0.y == t1.y && t0.y == t2.y) return; // ���� ��� ����� ������� �� �, �������
    if (t0.y > t1.y) std::swap(t0, t1);
    if (t0.y > t2.y) std::swap(t0, t2);
    if (t1.y > t2.y) std::swap(t1, t2);
    int total_height = t2.y - t0.y; // ������ �������������� ������������


    // todo fixit ���-�� � ����� ������� � ���� ���� ���������� ��� ��� ����������


    //for (int i = 0; i < (height * width) / 2; i++) {
    //    if (zbuffer[i] != minInt)
    //        cout << zbuffer[i] << " ";
    //}
    //cout << "\ninside\n\n\n";



    for (int i = 0; i < total_height; i++) { // �� ���� ������ ������������??????????? fixit 4real?
        bool second_half = i > t1.y - t0.y || t1.y == t0.y; // true ��� false � ����������� �� ���� 
                                                            // ������ �� i , ��� ���������� ����� 1 � 0 ������� ���
                                                            // ��� �������
        int segment_height = second_half ? t2.y - t1.y : t1.y - t0.y; // ���� i ������, ��� ���������� ����� 1 � 0 �������, ��
                                                            // ��� ����� ���������� ����� 2 � 1 �������, �����
                                                            // ����� 1 � 0 �������
        float alpha = (float)i / total_height;
        float beta = (float)(i - (second_half ? t1.y - t0.y : 0)) / segment_height; // be careful: with above conditions no division by zero here fixit 4real
        
        Point A = t0 + Point(t2 - t0) * alpha;
        Point B = second_half ? t1 + Point(t2 - t1) * beta : t0 + Point(t1 - t0) * beta;
        
        if (A.x > B.x) std::swap(A, B); // ���������� ����� �� ���������� �

        for (int j = A.x; j <= B.x; j++) { // ������ �� ������ � ����� � �� � �� �
            float phi = B.x == A.x ? 1.0 : (float)(j - A.x) / (float)(B.x - A.x); // 4real what
            Point P = Point(A) + Point(B - A) * phi;

            //int idx = P.x + P.y * width; // �������� ���-�� ��� �� ��� �������????????????

            int x = P.x;
            int y = P.y;

            if (x >= 0 && y >= 0)
            //if (zbuffer[idx] < P.z /* && doCol*/) {
            if (zbuffer[x][y] < P.z /* && doCol*/) {

                //cout << "zbuffer[idx] < P.z\t zbuffer[" << idx << "] " << zbuffer[idx] << "\t P.z" << P.z << "\t " << t0.name << t1.name << t2.name << " is closer" << endl;

                //zbuffer[idx] = P.z; // �� �����-�� ������� ��� ������������ � �����, �� ����� ��� ��� ���, ��� ����� �������
                zbuffer[x][y] = P.z; // �� �����-�� ������� ��� ������������ � �����, �� ����� ��� ��� ���, ��� ����� �������
                
                //imgCol(P.x, P.y, P.z, colour); // � ���������� ��� �� ���� ?? fixit
                putpixel(P.x, P.y, colour); // colour+j gives cool gradient to black

                // todo fixit ������-�� �� ����� ��� ����� � ������ � ������ �� ���������
                // ��� ���������� ������������� � ����� ������ �������������, ���� ��������� �����, �����, ����


                //P.x = j; P.y = t0.y + i; // a hack to fill holes (due to int cast precision problems)
                //imgCol(P.x, P.y, P.z, colour);
            }
            //else if (zbuffer[idx] > P.z){
            //    //cout << "zbuffer[idx] > P.z\t zbuffer[idx] " << zbuffer[idx] << "\t P.z" << P.z << "\t " << t0.name << t1.name << t2.name << " is NOT closer" << endl;
            //    //cout << "\n\tzbuffer[idx] " << zbuffer[idx];
            //}
                        
        }
    }
    
    // �������������
    /*
    for (int i = 0; i < (height * width)/2; i++) {
        if(zbuffer[i] != minInt)
            cout << zbuffer[i] << " ";
    }

    cout << "done" << endl;
    */

}




void Piramid::zBuff(Point A, Point B, Point C, Point D, Point E, Point F, Point G, Point H, Point I) {
    
    //zbuffer = new int[width * height]; // �������� z-�������

    //int* zbuffer = NULL;
    //zbuffer = new int[width * height]; // �������� z-�������
    
    const int width = 1400;
    const int height = 700;

    int** zbuffer;
    zbuffer = new int* [width];
    for (int i = 0; i < width; i++) {
        zbuffer[i] = new int[height];     // ������������� ����������
    }

    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++)
            zbuffer[i][j] = minInt; // �� ����� ������ ����� ��� �������������� �������� -- ���
    }

    triangle(A, B, C, DARK_GREEN, zbuffer); // ���������
    triangle(A, C, D, BLUE, zbuffer);
    triangle(B, C, D, GREEN, zbuffer);
    triangle(A, B, D, CYAN, zbuffer);

    triangle(E, F, G, YELLOW, zbuffer); // ���������
    triangle(G, H, E, YELLOW, zbuffer); // ���������
    triangle(E, F, I, DARK_RED, zbuffer);
    triangle(F, G, I, DARK_MAGENTA, zbuffer);
    triangle(G, H, I, RED, zbuffer);
    triangle(H, E, I, MAGENTA, zbuffer);

    // �����������
    for (int i = 0; i < width; i++) {
        delete[] zbuffer[i];
    }
    delete[] zbuffer;

    /*
    triangle(A, B, C, RED, zbuffer, false); // ���������
    triangle(A, C, D, RED, zbuffer, false);
    triangle(B, C, D, RED, zbuffer, false);
    triangle(A, B, D, RED, zbuffer, false);

    triangle(E, F, G, GREEN, zbuffer, false); // ���������
    triangle(F, G, H, GREEN, zbuffer, false); // ���������
    triangle(E, F, I, GREEN, zbuffer, false);
    triangle(F, G, I, GREEN, zbuffer, false);
    triangle(G, H, I, GREEN, zbuffer, false);
    triangle(H, E, I, GREEN, zbuffer, false);



    triangle(A, B, C, RED, zbuffer, true); // ���������
    triangle(A, C, D, RED, zbuffer, true);
    triangle(B, C, D, RED, zbuffer, true);
    triangle(A, B, D, RED, zbuffer, true);

    triangle(E, F, G, GREEN, zbuffer, true); // ���������
    triangle(F, G, H, GREEN, zbuffer, true); // ���������
    triangle(E, F, I, GREEN, zbuffer, true);
    triangle(F, G, I, GREEN, zbuffer, true);
    triangle(G, H, I, GREEN, zbuffer, true);
    triangle(H, E, I, GREEN, zbuffer, true);
    */
}
