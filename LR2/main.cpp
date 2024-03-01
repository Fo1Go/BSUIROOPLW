#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include "Line.h"
#include "Point.h"

using std::string, std::vector, std::cin, std::cout, std::endl, std::getline, std::to_string, std::isinf;

/*
    Создать классы, спецификации которых приведены ниже.
    Определить конструкторы и методы setТип(), getТип(), toString().
    Определить дополнительно методы в классе, создающем массив объектов.
    Реализовать методы сложения, вычитания, умножения и деления объектов
    (для тех классов, объекты которых могут поддерживать арифметические действия).
    Задать критерий выбора данных и вывести эти данные на консоль. В каждом классе,
    обладающем информацией, должно быть объявлено несколько конструкторов.

    21. Определить класс Прямая на плоскости, параметры которой задаются с помощью Рациональной Дроби.
    Определить точки пересечения прямой с осями координат.
    Определить координаты пересечения двух прямых.
    Создать массив/список/множество объектов и определить группы параллельных прямых.
*/

Point getPoint() {
    double x, y;
    cout << "Enter X point: " << endl;
    cin >> x;
    cout << "Enter Y point: " << endl;
    cin >> y;
    return Point(x, y);
}

int main() {
    // Example usage
    std::vector<Line> lines;
    Point p1(1, 2), p2(4, 5),
            p3(2, 1), p4(5, 4),
            p5(2, 4), p6(1, 7);

    Line line1(p1, p2);
    Line line2(p3, p4);
    Line line3(p5, p6);

    Line line4 = line3 - line2;
    Line line5 = line2 * line4;
    lines.push_back(line1);
    lines.push_back(line2);
    lines.push_back(line3);
    lines.push_back(line4);
    lines.push_back(line5);

    bool is_running = true;
    string userInput;
    int chooseCommand = -1;
    while (is_running) {
        cout << "what you wanna do: \n"
             << "1. Enter new line\n"
             << "2. Watch all lines\n"
             << "3. Find the intersection with axis\n"
             << "4. Find intersection between 2 lines\n"
             << "0. Exit\n";
        cin >> chooseCommand;
        if (chooseCommand == 0) {
            is_running = false;
        } else if (chooseCommand == 1) {
            Point p1 = getPoint();
            Point p2 = getPoint();
            lines.emplace_back(Line(p1, p2));
        } else if (chooseCommand == 2) {
            for (int index = 0; index < lines.size(); index++)
                cout << "Line " << index << ": " << lines[index].toString() << endl;
        } else if (chooseCommand == 3) {
            int p1;
            cout << "Choose number of line: " << endl;
            cin >> p1;
            if (p1 < lines.size() and p1 >= 0) {
                cout << "With axis X: " << lines[p1].intersectionWithXAxis().toString() << endl;
                cout << "With axis Y: " << lines[p1].intersectionWithYAxis().toString() << endl;
            } else {
                cout << "Not valid number" << endl;
            }
        } else if (chooseCommand == 4) {
            Point pointOfIntersection;
            int numberLine1, numberLine2;
            cout << "Choose number of first line: " << endl;
            cin >> numberLine1;
            cout << "Choose number of second line: " << endl;
            cin >> numberLine2;
            if ((numberLine1 < lines.size() and numberLine1 >= 0) and
                (numberLine2 < lines.size() and numberLine2 >= 0)) {
                pointOfIntersection = lines[numberLine1].intersectionWithLine(lines[numberLine2]);
            }
            if (isinf(pointOfIntersection.getX()) and isinf(pointOfIntersection.getY())) {
                cout << "No point of intersection. They are parallel" << endl;
            } else {
                cout << "Point of intersection: " << pointOfIntersection.toString() << endl;
            }
        } else {
            cout << "Unknown command!" << endl;
        }
//        system("cls");
//        system("pause");
    }
    return 0;
}