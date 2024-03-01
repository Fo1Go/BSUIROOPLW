//
// Created by prost on 15.02.2024.
//

#include "Point.h"

#ifndef LR2_LINE_H
#define LR2_LINE_H

class Line {
private:
    Point p1;
    Point p2;
public:
    Line(const Point &p1Val, const Point &p2Val) {
        this->p1 = p1Val;
        this->p2 = p2Val;
    }

    void setP1(Point &p1Val) { this->p1 = p1Val; }

    void setP2(Point &p2Val) { this->p2 = p2Val; }

    Point getP1() { return this->p1; }

    Point getP2() { return this->p2; }

    std::string toString() {
        return "Line: " + p1.toString() + " - " + p2.toString();
    }

    Point intersectionWithXAxis() {
        double xIntersect = (this->p1.getY() * this->p2.getX() -
                             this->p2.getY() * this->p1.getX()) / (this->p1.getY() - this->p2.getY());
        return {xIntersect, 0};
    }

    Point intersectionWithYAxis() {
        double yIntersect = (this->p1.getX() * this->p2.getY() -
                             this->p2.getX() * this->p1.getY()) / (this->p1.getX() - this->p2.getX());
        return {0, yIntersect};
    }

    Line intersectionWithLine(Line &l) {
        double a1, a2, b1, b2, c1, c2;
        double x1, y1, x2, y2, x3, y3, x4, y4;
        x1 = this->p1.getX();
        x2 = this->p2.getX();
        y1 = this->p1.getY();
        y2 = this->p2.getY();
        y3 = l.p1.getY();
        y4 = l.p2.getY();
        x3 = l.p1.getX();
        x4 = l.p2.getX();

        a1 = y1 - y2;
        b1 = x2 - x1;
        c1 = x1 * y2 - x2 * y1;
        a2 = y3 - y4;
        b2 = x4 - x3;
        c2 = x3 * y4 - x4 * y3;

        double det = a1 * b2 - a2 * b1;
        double xIntersect = (b1 * c2 - b2 * c1) / det;
        double yIntersect = (a2 * c1 - a1 * c2) / det;

        return {xIntersect, yIntersect};
    }

    Line operator+(Line &line) const {
        return {this->p1 + line.getP1(), this->p2 + line.getP2()};
    }


    Line operator-(Line &line) const {
        return {this->p1 - line.getP1(), this->p2 - line.getP2()};
    }

    Line operator*(Line &line) const {
        return {this->p1 * line.getP1(), this->p2 * line.getP2()};
    }

    Line operator/(Line &line) const {
        return {this->p1 / line.getP1(), this->p2 / line.getP2()};
    }
};


#endif //LR2_LINE_H
