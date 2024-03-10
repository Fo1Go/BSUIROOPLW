
#ifndef LR2_UTILS_H
#define LR2_UTILS_H

bool isCloseToInt(double value) {
    return value - (int)(value) < 0.001;
}

#endif