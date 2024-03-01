#include <iostream>
#include <vector>
#include <string>
#include "Line.h"
#include "Point.h"

using std::string, std::vector, std::cin, std::cout, std::endl, std::getline, std::to_string;

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

int main() {
    // Example usage
    Point p1(1, 2), p2(4, 5),
            p3(2, 1), p4(5, 4),
            p5(2, 4), p6(1, 7);

    Line line1(p1, p2);
    Line line2(p3, p4);
    Line line3(p5, p6);

    Line line4 = line3 - line2;
    Line line5 = line2 * line4;


    std::cout << "Line 1: " << line1.toString() << std::endl;
    std::cout << "Line 2: " << line2.toString() << std::endl;
    std::cout << "Line 3: " << line3.toString() << std::endl;

    std::cout << "Line 4: " << line4.toString() << std::endl;
    std::cout << "Line 5: " << line5.toString() << std::endl;


    std::cout << "Line1 intersect X-axis: " << line1.intersectionWithXAxis().toString() << std::endl;
    std::cout << "Line1 Intersect Y-axis: " << line1.intersectionWithYAxis().toString() << std::endl;

    std::cout << "Intersection of Line 1 and Line 2: " << line1.intersectionWithLine(line2)
            .toString() << std::endl;
    std::cout << "Intersection of Line 1 and Line 3: " << line1.intersectionWithLine(line3)
            .toString() << std::endl;

    return 0;
}