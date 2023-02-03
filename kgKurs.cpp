﻿// Вар 1 (почти как 6 и 16)
// 
// + Разнести всё по файлам как про
// + довести до ума класс пирамиды, чтобы был максимально униваерсальный
// + доделать повороты и пр. для ещё 5 точек
// + добавить пергрузок на - и * в точки, чтобы они - и * все координапы первой и второй
// + выяснить почему оно не понимает что спереди ?????????????????????????????????????????????77
// + расставить грани для закраски так, чтобы при первом запуске было максимально быстро и круто
// + Убрать todo fixit 4real и прочий мусор из пирамид
// + починить пересечения и закраску (z и затравка)
// + Пересекающиеся Треугольная пирамида и четырехугольная пирамида
// + Закраска по "Заливка области с затравкой" (текущая хз та ли, а часть с нахождением того, что надо красить точно переделать)
// + Алгоритм удаления невидимых линий и поверхностей "Алгоритм Z-буфера" (а, ну вот)
// 
// - отделить нахождение того, что надо красить от самой закраски
//      потому что оно иначе красит по порядку проверки и это затратно + зря + видно + иначе у меня почти художник получается, а не буфер
// - залатать дырки в закраске
// 
// - Сделать пол
// - Придумать откуда свет 
// - Алгоритм построения тени "Построение «на землю» (источник света на конечном расстоянии)" (т.е. проекция будет меняться в масштабе и наклоне при перемещении?)
// 
// - почистить везде мусор
// - написать везде коменты
// - Отчёт
//


#include <iostream>
#include "graphics.h"
#pragma comment(lib,"graphics.lib")

#include "Point.h"
#include "Piramid.h"
#include "Colours.h"

using namespace std;

// размеры окна
const int width = 1400;
const int height = 700;

int main() {
    initwindow(width, height); // создаём консольное окно 1400 на 700

    // Точки для пирамид
    char name_A[2] = "A";
    char name_B[2] = "B";
    char name_C[2] = "C";
    char name_D[2] = "D";
                                    // пока костыльно, пофиг, это вообще не важно так-то. ну 5 лишних переменных и чо
    Point A(10, 100, 0, name_A);    // todo fixit В классе пирамиды имена точек передаются и берутся не из точек, а из констант :(
    Point B(120, 100, 0, name_B);    // дело не в именах самих точек, им они присваиваются всё равно, но выводятся не из них
    Point C(40, 100, 40, name_C);   // прочекать пирамиду и точку, мб проблема в точке? в спп в выводе названия на экран, где он
    Point D(50, 50, 20, name_D);    // ждёт  чар, а не то, что я кормлю????????????????????????

    char name_E[2] = "E";
    char name_F[2] = "F";
    char name_G[2] = "G";
    char name_H[2] = "H";
    char name_I[2] = "I";

    Point E(20, 150, 0, name_E);
    Point F(40, 150, -40, name_F);
    Point G(130, 150, 20, name_G);
    Point H(70, 150, 50, name_H);
    Point I(80, 40, 10, name_I);

    Piramid TriFour(A, B, C, D, E, F, G, H, I); // создание пирамид

    // управление
    int i = 1; // условие выхода
    while (i) {
        switch (getch()) {
        case 'w':
        case 'W':
        case 'ц':
        case 'Ц':
            cout << 'w' << endl;
            TriFour.moveY(-10); // вверх
            break;
        case 'a':
        case 'A':
        case 'ф':
        case 'Ф':
            cout << 'a' << endl;
            TriFour.moveX(-10); // влево
            break;
        case 's':
        case 'S':
        case 'ы':
        case 'Ы':
            cout << 's' << endl;
            TriFour.moveY(10); // вниз
            break;
        case 'd':
        case 'D':
        case 'в':
        case 'В':
            cout << 'd' << endl;
            TriFour.moveX(10); // вправо
            break;
        case 'x':
        case 'X':
        case 'ч':
        case 'Ч':
            cout << 'x' << endl;
            TriFour.moveZ(-10); // назад
            break;
        case 'z':
        case 'Z':
        case 'я':
        case 'Я':
            cout << 'z' << endl;
            TriFour.moveZ(10); // вперёд
            TriFour.scale(1.1);
            break;
            // вокруг z
        case 'q':
        case 'Q':
        case 'й':
        case 'Й':
            cout << 'q' << endl;
            TriFour.rotateZ(1); // против часовой
            break;
        case 'e':
        case 'E':
        case 'у':
        case 'У':
            cout << 'e' << endl;
            TriFour.rotateZ(-1); // по часовой
            break;
            // вокруг y
        case 'r':
        case 'R':
        case 'к':
        case 'К':
            cout << 'r' << endl;
            TriFour.rotateY(1); // против часовой
            break;
        case 't':
        case 'T':
        case 'е':
        case 'Е':
            cout << 't' << endl;
            TriFour.rotateY(-1); // по часовой
            break;
            // вокруг x
        case 'f':
        case 'F':
        case 'а':
        case 'А':
            cout << 'f' << endl;
            TriFour.rotateX(1); // против часовой
            break;
        case 'g':
        case 'G':
        case 'п':
        case 'П':
            cout << 'g' << endl;
            TriFour.rotateX(-1); // по часовой
            break;

        case '=':
        case '+':
            cout << '+' << endl;
            TriFour.scale(1.5); // увеличение
            break;
        case '-':
        case '_':
            cout << '-' << endl;
            TriFour.scale(0.5); // уменьшение
            break;
        default:
            cout << "default -> exit" << endl;
            i = 0;
            break;
        }
        cleardevice(); // отичстка экрана
        TriFour.drawPiramid(); // перерисовка фигур
    }

    getch(); // чтение одного символа с клавиатуры
    closegraph(); // освобождает всю память, выделенную под графическую систему, затем восстанавливает экран в режим, который был до вызова initwindow

    return 0;
}
