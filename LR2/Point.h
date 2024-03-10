//
// Created by prost on 15.02.2024.
//
#ifndef LR2_POINT_H
#define LR2_POINT_H

#include <iostream>
#include <string>
#include "utils.h"

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
        std::string XString, YString;
        if (isCloseToInt(this->getX())) {
            XString = std::to_string((int)this->getX());
        } else {
            std::string X = std::to_string(this->getX());
            XString = X.substr(0, X.find(".") + 3);
        }

        if (isCloseToInt(this->getY())) {
            YString = std::to_string((int)this->getY());
        } else {
            std::string Y = std::to_string(this->getY());
            YString = Y.substr(0, Y.find(".") + 3);
        }

        return "(" + XString + ", " + YString + ")";
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
