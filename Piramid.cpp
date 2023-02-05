
#include <iostream>
#include <math.h>
#include "graphics.h"
#pragma comment(lib,"graphics.lib")

#include "Point.h"
#include "Piramid.h"
#include "Colours.h"

using namespace std;


// отрисовка линии попиксельно
void line_DDA(float x1, float y1, float z1, float x2, float y2, float z2, COLORREF cColor) {
    // Учёт координаты z при отрисовке в двумерном пространстве
    x1 -= 0.5 * z1;
    y1 += 0.5 * z1;
    x2 -= 0.5 * z2;
    y2 += 0.5 * z2;

    // Целочисленные значения координат начала и конца отрезка, округлённые до ближайшего целого
    int iX1 = roundf(x1);
    int iY1 = roundf(y1);
    int iX2 = roundf(x2);
    int iY2 = roundf(y2);

    // Длина и высота линии
    int deltaX = abs(iX1 - iX2);
    int deltaY = abs(iY1 - iY2);

    // Считаем минимальное количество итераций, необходимое для отрисовки отрезка
    // Выбирая максимум из длины и высоты линии, обеспечиваем связность линии
    int length = max(deltaX, deltaY);

    // особый случай, на экране закрашивается ровно один пиксель
    if (length == 0) {
        putpixel(iX1, iY1, cColor);
        return;
    }
    // Вычисляем приращения на каждом шаге по осям абсцисс и ординат
    double dX = (x2 - x1) / length;
    double dY = (y2 - y1) / length;

    // Начальные значения
    double x = x1;
    double y = y1;

    // Основной цикл
    length++;
    while (length--) {
        x += dX;
        y += dY;
        putpixel(roundf(x), roundf(y), cColor);
    }
}


// имена точек
char name_A[2] = "A";
char name_B[2] = "B";
char name_C[2] = "C";
char name_D[2] = "D";

char name_E[2] = "E";
char name_F[2] = "F";
char name_G[2] = "G";
char name_H[2] = "H";
char name_I[2] = "I";


// конструктор от 9 точек сразу для двух фигур
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


// отрисовка
void Piramid::drawPiramid() {
    // оси
    setcolor(WHITE);
    line(700, 350, 730, 350); char xCoord[2] = "x"; outtextxy(735, 350, xCoord);
    line(700, 350, 700, 320); char yCoord[2] = "y"; outtextxy(700, 300, yCoord);
    line(700, 350, 685, 365); char zCoord[2] = "z"; outtextxy(680, 370, zCoord);

    // инструкции
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

    // вывод инструкций
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

    // вывод имён точек
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

    // трёхгранная
    // нижнее основание
    line_DDA(A.x, A.y, A.z, B.x, B.y, B.z, col); // линия 1
    line_DDA(B.x, B.y, B.z, C.x, C.y, C.z, col); // линия 2
    line_DDA(C.x, C.y, C.z, A.x, A.y, A.z, col); // линия 3

    // боковые грани
    line_DDA(D.x, D.y, D.z, A.x, A.y, A.z, col); // линия 4
    line_DDA(D.x, D.y, D.z, B.x, B.y, B.z, col); // линия 5
    line_DDA(D.x, D.y, D.z, C.x, C.y, C.z, col); // линия 6


    // четырёхгранная
    // нижнее основание
    line_DDA(E.x, E.y, E.z, F.x, F.y, F.z, col); // линия 1
    line_DDA(F.x, F.y, F.z, G.x, G.y, G.z, col); // линия 2
    line_DDA(G.x, G.y, G.z, H.x, H.y, H.z, col); // линия 3
    line_DDA(H.x, H.y, H.z, E.x, E.y, E.z, col); // линия 4

    // боковые грани
    line_DDA(I.x, I.y, I.z, E.x, E.y, E.z, col); // линия 5
    line_DDA(I.x, I.y, I.z, F.x, F.y, F.z, col); // линия 6
    line_DDA(I.x, I.y, I.z, G.x, G.y, G.z, col); // линия 7
    line_DDA(I.x, I.y, I.z, H.x, H.y, H.z, col); // линия 8


    // построение теней
    setcolor(WHITE);
    shadowAll(A, B, C, D, E, F, G, H, I);

    // закраска граней фигуры
    zBuff(A, B, C, D, E, F, G, H, I);
}

// пермещение
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

// поворот одной точки вокруг z
Point Piramid::rotDotZ(int u, float ang, Point Cen, Point L) {
    L.x = L.x - Cen.x; // расстояние от а до центра по х
    L.y = L.y - Cen.y; // по у

    float tmpX = L.x * cos(ang) + L.y * sin(ang);
    float tmpY = -L.x * sin(ang) + L.y * cos(ang);
    L.x = tmpX + Cen.x;
    L.y = tmpY + Cen.y;

    return L;
}
// поворот фигуры вокруг z
void Piramid::rotateZ(int u) { // u = -1 по часовой, u = 1 против
    float ang = u * 0.05; // угол поворота

    Point Cen; // точка центра 
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

// поворот одной точки вокруг y
Point Piramid::rotDotY(int u, float ang, Point Cen, Point L) {
    L.x = L.x - Cen.x; // расстояние от а до центра по y
    L.z = L.z - Cen.z; // по z

    float tmpX = L.x * cos(ang) + L.z * sin(ang);
    float tmpZ = -L.x * sin(ang) + L.z * cos(ang);
    L.x = tmpX + Cen.x;
    L.z = tmpZ + Cen.z;

    return L;
}
// поворот фигуры вокруг y
void Piramid::rotateY(int u) { // u = -1 по часовой, u = 1 против
    float ang = u * 0.05; // угол поворота

    Point Cen; // точка центра 
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

// поворот одной точки вокруг x
Point Piramid::rotDotX(int u, float ang, Point Cen, Point L) {
    L.y = L.y - Cen.y; // расстояние от а до центра по y
    L.z = L.z - Cen.z; // по z

    float tmpY = L.y * cos(ang) + L.z * sin(ang);
    float tmpZ = -L.y * sin(ang) + L.z * cos(ang);
    L.y = tmpY + Cen.y;
    L.z = tmpZ + Cen.z;

    return L;
}
// поворот фигуры вокруг x
void Piramid::rotateX(int u) { // u = -1 по часовой, u = 1 против
    float ang = u * 0.05; // угол поворота

    Point Cen; // точка центра
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

// масштабирование одной точки
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
// масштабирование всей фигуры
void Piramid::scale(float e) {
    Point Cen; // точка центра 
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
        ) && e < 1 || e > 1) { // предотвращение сжатия в точку

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


// закраска треугольниками после проверки на видимость z-буффером
void Piramid::triangle(Point t0, Point t1, Point t2, COLORREF colour, int** zbuffer) {
    // учёт координаты z при отрисовке в двумерном пространстве
    // точка пересечения смотрится не прямо вдоль оси z, а под углом 45, как видит пользователь
    t0.x -= 0.5 * t0.z; t0.y += 0.5 * t0.z;
    t1.x -= 0.5 * t1.z; t1.y += 0.5 * t1.z;
    t2.x -= 0.5 * t2.z; t2.y += 0.5 * t2.z; 

    // сортировка точек по координате у
    if (t0.y == t1.y && t0.y == t2.y) return; // если все точки совпали по у, возврат
    if (t0.y > t1.y) std::swap(t0, t1);
    if (t0.y > t2.y) std::swap(t0, t2);
    if (t1.y > t2.y) std::swap(t1, t2);
    int total_height = t2.y - t0.y; // высота закрашиваемого треугольника

    for (int i = 0; i < total_height; i++) { // по всей высоте треугольника
        bool second_half = i > t1.y - t0.y || t1.y == t0.y; // true или false в зависимости от того 
                                                            // больше ли i , чем расстояние между 1 и 0 точками или
                                                            // они совпали
        int segment_height = second_half ? t2.y - t1.y : t1.y - t0.y; // если i больше, чем расстояние между 1 и 0 точками, то
                                                            // оно равно расстоянию между 2 и 1 точками, иначе
                                                            // между 1 и 0 точками
        float alpha = (float)i / total_height;
        float beta = (float)(i - (second_half ? t1.y - t0.y : 0)) / segment_height;
        
        Point A = t0 + Point(t2 - t0) * alpha;
        Point B = second_half ? t1 + Point(t2 - t1) * beta : t0 + Point(t1 - t0) * beta;
        
        if (A.x > B.x) std::swap(A, B); // сортировка точек по координате х

        for (int j = A.x; j <= B.x; j++) { // проход по строке с коорд х от а до б
            float phi = B.x == A.x ? 1.0 : (float)(j - A.x) / (float)(B.x - A.x);
            Point P = Point(A) + Point(B - A) * phi;
            int x = P.x;
            int y = P.y;
            if (x >= 0 && y >= 0) {
                if (zbuffer[x][y] < P.z) {
                    zbuffer[x][y] = P.z; // глубина ближайшего к экрану пикселя записывается в буфер
                    putpixel(P.x, P.y, colour); // colour+j даст крутой градиент к чёрному
                }
            }                     
        }
    }
}

// использование алгоритма z-буффера для отсечения невидимых поверхностей и закраски видимых
void Piramid::zBuff(Point A, Point B, Point C, Point D, Point E, Point F, Point G, Point H, Point I) {
    // создание z-буффера
    int** zbuffer;
    zbuffer = new int* [width];
    for (int i = 0; i < width; i++) {
        zbuffer[i] = new int[height]; // инициализация указателей
    }

    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++)
            zbuffer[i][j] = minInt; // по всему экрану задаём ему минимальнейшее значение -- фон
    }

    // треугольная пирамида
    triangle(A, C, D, BLUE, zbuffer);
    triangle(B, C, D, GREEN, zbuffer);
    triangle(A, B, D, CYAN, zbuffer);
    triangle(A, B, C, DARK_GREEN, zbuffer); // основание

    // четырёхугольная пирамида
    triangle(G, H, I, RED, zbuffer);
    triangle(H, E, I, MAGENTA, zbuffer);
    triangle(E, F, I, DARK_RED, zbuffer);
    triangle(F, G, I, DARK_MAGENTA, zbuffer);
    triangle(E, F, G, YELLOW, zbuffer); // основание
    triangle(G, H, E, YELLOW, zbuffer); // основание

    // уничтожение
    for (int i = 0; i < width; i++) {
        delete[] zbuffer[i];
    }
    delete[] zbuffer;
}


// построение проекции точки на условный пол для тени
Point Piramid::shadowPoint(Point P) {
    Point L(700, 20, 0); // точка источника света

    int floor = 350; // условный пол
    Point S(0, 0, 0); // точка полученной проекции

    int k = (floor - P.y) / (L.y - P.y);
    S.x = (L.x - P.x) * k + P.x;
    S.y = floor;
    S.z = (L.z - P.z) * k + P.z;

    // учёт координаты z при отрисовке в двумерном пространстве
    // точка пересечения смотрится не прямо вдоль оси z, а под углом 45, как видит пользователь
    S.x -= 0.5 * S.z; S.y += 0.5 * S.z;

    return S;
}

// построение тени для треугольника
void Piramid::shadowTri(Point A, Point B, Point C) {
    Point p1, p2, p3;
    int floor = 350; // условный пол
    // условие для отображения тени только ниже фигуры
    if (A.y <= floor && B.y <= floor && C.y <= floor) { 
        p1 = shadowPoint(A);
        p2 = shadowPoint(B);
        p3 = shadowPoint(C);
        shadowTriColour(p1, p2, p3, GRAY);
    }
}

// построение теней для всех фигур
void Piramid::shadowAll(Point A, Point B, Point C, Point D, Point E, Point F, Point G, Point H, Point I) {
    Point L(700, 20, 0); // точка источника света
    int lightWidth = 4;
    for (int i = L.x- lightWidth; i <= L.x+ lightWidth; i++) {
        for (int j = L.y - lightWidth; j <= L.y + lightWidth; j++) {
            putpixel(i, j, WHITE);
        }
    }

    shadowTri(A, B, C);
    shadowTri(A, B, D);
    shadowTri(C, B, D);
    shadowTri(A, C, D);

    shadowTri(E, F, G);
    shadowTri(E, H, G);
    shadowTri(E, F, I);
    shadowTri(F, G, I);
    shadowTri(G, H, I);
    shadowTri(H, E, I);
}

// закраска тени треугольниками
void Piramid::shadowTriColour(Point t0, Point t1, Point t2, COLORREF colour) {
    // сортировка точек по координате у
    if (t0.y == t1.y && t0.y == t2.y) return; // если все точки совпали по у, возврат
    if (t0.y > t1.y) std::swap(t0, t1);
    if (t0.y > t2.y) std::swap(t0, t2);
    if (t1.y > t2.y) std::swap(t1, t2);
    int total_height = t2.y - t0.y; // высота закрашиваемого треугольника

    for (int i = 0; i < total_height; i++) { // по всей высоте треугольника
        bool second_half = i > t1.y - t0.y || t1.y == t0.y; // true или false в зависимости от того 
                                                            // больше ли i , чем расстояние между 1 и 0 точками или
                                                            // они совпали
        int segment_height = second_half ? t2.y - t1.y : t1.y - t0.y; // если i больше, чем расстояние между 1 и 0 точками, то
                                                            // оно равно расстоянию между 2 и 1 точками, иначе
                                                            // между 1 и 0 точками
        float alpha = (float)i / total_height;
        float beta = (float)(i - (second_half ? t1.y - t0.y : 0)) / segment_height;

        Point A = t0 + Point(t2 - t0) * alpha;
        Point B = second_half ? t1 + Point(t2 - t1) * beta : t0 + Point(t1 - t0) * beta;

        if (A.x > B.x) std::swap(A, B); // сортировка точек по координате х

        for (int j = A.x; j <= B.x; j++) { // проход по строке с коорд х от а до б
            float phi = B.x == A.x ? 1.0 : (float)(j - A.x) / (float)(B.x - A.x);
            Point P = Point(A) + Point(B - A) * phi;
            int x = P.x;
            int y = P.y;
            if (x >= 0 && y >= 0) {
                putpixel(P.x, P.y, colour);
            }
        }
    }
}
