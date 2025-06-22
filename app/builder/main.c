#include "../../include/builder/car_builder.h"

/*
* @details
* car_builder_create() is for work safetly and not having shared memory issues.
*
*/
int main(void) {
    setlocale(LC_ALL, "tr_TR.UTF-8");
    car_builder_t* car_builder = car_builder_create();

    // You can use the same builder after you've done with previous car.
    car_t* toyota = car_builder
        ->brand(car_builder, "Toyota")
        ->model(car_builder, "Corolla")
        ->year(car_builder, 2025)
        ->price(car_builder, 1890000)
        ->build(car_builder);

    to_print(*toyota);

    free(toyota->brand);
    free(toyota->model);
    free(toyota);

    car_t* honda = car_builder
        ->brand(car_builder, "Honda")
        ->model(car_builder, "Civic")
        ->year(car_builder, 2025)
        ->price(car_builder, 2260000)
        ->build(car_builder);
    
    to_print(*honda);

    free(honda->brand);
    free(honda->model);
    free(honda);

    car_builder
        ->brand(car_builder, "Toyota")
        ->model(car_builder, "Corolla")
        ->year(car_builder, 2025)
        ->price(car_builder, 1890000);
    car_builder_destroy(car_builder);
    return 0;
}