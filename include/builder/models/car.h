#ifndef C_DESIGN_PATTERNS_BUILDER_CAR_H
#define C_DESIGN_PATTERNS_BUILDER_CAR_H

#include "../../utils.h"
#include <locale.h>

typedef struct car {
    str brand;
    str model;
    int year;
    double price;
} car_t;

void to_print(const car_t car);

#endif // C_DESIGN_PATTERNS_BUILDER_CAR_H