#ifndef C_DESIGN_PATTERNS_BUILDER_CAR_BUILDER_H
#define C_DESIGN_PATTERNS_BUILDER_CAR_BUILDER_H

#include "models/car.h"
#include <stdbool.h>

typedef struct car_builder car_builder_t;

typedef struct car_builder {
    str temp_brand;
    str temp_model;
    double temp_price;
    int temp_year;
    
    struct car_builder* (*brand) (car_builder_t* builder, str brand);
    struct car_builder* (*model) (car_builder_t* builder, str model);
    struct car_builder* (*price) (car_builder_t* builder, double price);
    struct car_builder* (*year)  (car_builder_t* builder, int year);
    car_t*              (*build) (car_builder_t* builder);
} car_builder_t;

car_builder_t* car_builder_create(void);
void           car_builder_destroy(car_builder_t* builder);

#endif // C_DESIGN_PATTERNS_BUILDER_CAR_BUILDER_H