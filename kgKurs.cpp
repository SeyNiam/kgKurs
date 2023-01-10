//
// Вар 1 (почти как 6 и 16)
// 
// + Разнести классы по файлам как про
// - Дочерний класс для 4хугольной пирамиды??
// - Сделать пол
// - Придумать откуда свет
// - Пересекающиеся Треугольная пирамида и четырехугольная пирамида
// - Закраска по "Заливка области с затравкой" (текущая жопная, лучше снести. По крайней мере часть с нахождением того, что надо красить точно  переделать)
// - Алгоритм удаления невидимых линий и поверхностей "Алгоритм Z-буфера" (а, ну вот)
// - Алгоритм построения тени "Построение «на землю» (источник света на конечном расстоянии)" (т.е. проекция будет меняться в масштабе и наклоне при перемещении)
// - Отчёт
//


#include <iostream>
#include <math.h>
#include "graphics.h"
#pragma comment(lib,"graphics.lib")

#include "Point.h"
#include "Surface.h"
#include "Piramid.h"

// fixit дублируется в классе пирамиды и в спп и в х
#define P 3.14
#define TEXTCOL 13 // маджента
#define MAINCOL 13 
#define WHITE 15
#define BLACK 0

#define GREEN 2
#define CYAN 11
#define RED	4
#define YELLOW	14


using namespace std;



int main() {
    initwindow(1400, 700); // создаём консольное окно 1400 на 700

    // Точки для треугольной пирамиды
    Point A(10, 100, 0);
    Point B(80, 100, 0);
    Point C(40, 100, 40);
    Point D(50, 50, 20);

    Piramid Tri(A, B, C, D); // создание треугольной пирамиды
    //Piramid Four; // создание четырёхугольной пирамиды

    // управление
    int i = 1; // условие выхода
    while (i) {
        switch (getch()) {
        case 'w':
        case 'W':
        case 'ц':
        case 'Ц':
            cout << 'w' << endl;
            Tri.moveY(-10); // вверх
            break;
        case 'a':
        case 'A':
        case 'ф':
        case 'Ф':
            cout << 'a' << endl;
            Tri.moveX(-10); // влево
            break;
        case 's':
        case 'S':
        case 'ы':
        case 'Ы':
            cout << 's' << endl;
            Tri.moveY(10); // вниз
            break;
        case 'd':
        case 'D':
        case 'в':
        case 'В':
            cout << 'd' << endl;
            Tri.moveX(10); // вправо
            break;
        case 'x':
        case 'X':
        case 'ч':
        case 'Ч':
            cout << 'x' << endl;
            Tri.moveZ(-10); // назад
            Tri.scale(0.9);
            break;
        case 'z':
        case 'Z':
        case 'я':
        case 'Я':
            cout << 'z' << endl;
            Tri.moveZ(10); // вперёд
            Tri.scale(1.1);
            break;

            // вокруг z
        case 'q':
        case 'Q':
        case 'й':
        case 'Й':
            cout << 'q' << endl;
            Tri.rotateZ(1); // против часовой
            break;
        case 'e':
        case 'E':
        case 'у':
        case 'У':
            cout << 'e' << endl;
            Tri.rotateZ(-1); // по часовой
            break;
            // вокруг y
        case 'r':
        case 'R':
        case 'к':
        case 'К':
            cout << 'r' << endl;
            Tri.rotateY(1); // против часовой
            break;
        case 't':
        case 'T':
        case 'е':
        case 'Е':
            cout << 't' << endl;
            Tri.rotateY(-1); // по часовой
            break;
            // вокруг x
        case 'f':
        case 'F':
        case 'а':
        case 'А':
            cout << 'f' << endl;
            Tri.rotateX(1); // против часовой
            break;
        case 'g':
        case 'G':
        case 'п':
        case 'П':
            cout << 'g' << endl;
            Tri.rotateX(-1); // по часовой
            break;

        case '=':
        case '+':
            cout << '+' << endl;
            Tri.scale(1.5); // увеличение
            break;
        case '-':
        case '_':
            cout << '-' << endl;
            Tri.scale(0.5); // уменьшение
            break;
        default:
            cout << "default -> exit" << endl;
            i = 0;
            break;
        }
        cleardevice(); // отичстка экрана
        Tri.drawPiramid(); // перерисовка фигуры
    }

    getch(); // чтение одного символа с клавиатуры
    closegraph(); // освобождает всю память, выделенную под графическую систему, затем восстанавливает экран в режим, который был до вызова initwindow

    return 0;
}
