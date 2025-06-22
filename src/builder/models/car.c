#include "../../../include/builder/models/car.h"

void to_print(const car_t car) {
    fprintf(stderr, "----------\n| %s %s %d \n| Price : %'0.2f TL\n|\n", car.brand, car.model, car.year, car.price);
}