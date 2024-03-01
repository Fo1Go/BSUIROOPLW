//
// Created by prost on 15.02.2024.
//
#include <iostream>
#include <string>

#ifndef LR2_POINT_H
#define LR2_POINT_H

class Point {
private:
    double x;
    double y;
public:
    Point(double xVal = 0, double yVal = 0) {
        this->x = xVal;
        this->y = yVal;
    }

    void setX(double xVal) {
        this->x = xVal;
    }

    void setY(double yVal) {
        this->y = yVal;
    }

    double getX() {
        return this->x;
    }

    double getY() {
        return this->y;
    }

    std::string toString() {
        return "(" + std::to_string(this->x) + ", " + std::to_string(this->y) + ")";
    }

    Point operator+(Point point) const {
        return {this->x + point.getX(), this->y + point.getY()};
    }

    Point operator-(Point point) const {
        return {this->x - point.getX(), this->y - point.getY()};
    }

    Point operator*(Point point) const {
        return {this->x * point.getX(), this->y * point.getY()};
    }

    Point operator/(Point point) const {
        return {this->x / point.getX(), this->y / point.getY()};
    }
};

#endif //LR2_POINT_H
