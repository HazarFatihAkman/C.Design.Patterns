#include "../../include/builder/car_builder.h"

static bool validation(car_builder_t* builder) {
    if (builder->temp_brand == NULL || builder->temp_brand[0] == '\0') {
        perror("Brand cannot be null.");
        return false;
    }

    if (builder->temp_model == NULL || builder->temp_model[0] == '\0') {
        perror("Model cannot be null.");
        return false;
    }

    if (builder->temp_year <= 0) {
        perror("Year cannot be less than or equal 0.");
        return false;
    }

    if (builder->temp_price <= 0) {
        perror("Price cannot be less than or equal 0.");
        return false;
    }
    return true;
}

static car_builder_t* brand(car_builder_t* builder, str brand) {
    if (brand == NULL || brand[0] == '\0') {
        perror("Brand cannot be null.");
        return builder;
    }
    free(builder->temp_brand);

    builder->temp_brand = strdup(brand);
    return builder;
}

static car_builder_t* model(car_builder_t* builder, str model) {
    if (model == NULL || model[0] == '\0') {
        perror("Model cannot be null.");
        return builder;
    }
    free(builder->temp_model);
    builder->temp_model = strdup(model);
    return builder;
}

static car_builder_t* year(car_builder_t* builder, int year) {
    if (year <= 0) {
        perror("Year cannot be less than or equal 0.");
        return builder;
    }
    builder->temp_year = year;
    return builder;
}

static car_builder_t* price(car_builder_t* builder, double price) {
    if (price <= 0) {
        perror("Price cannot be less than or equal 0.");
        return builder;
    }
    builder->temp_price = price;
    return builder;
}

static car_t* build(car_builder_t* builder) {
    car_t* car = (car_t*)malloc(sizeof(car_t));
    if (car == NULL) {
        perror("Car Memory Allocation!\n");
        return NULL;
    }

    if (validation(builder)) {
        car->brand = strdup(builder->temp_brand);
        car->model = strdup(builder->temp_model);
        car->year  = builder->temp_year;
        car->price = builder->temp_price;
        return car;
    }

    free(car->brand);
    free(car->model);
    free(car);
    return NULL;
}

car_builder_t* car_builder_create() {
    car_builder_t* builder = calloc(1, sizeof(car_builder_t));
    builder->brand = brand;
    builder->model = model;
    builder->price = price;
    builder->year  = year;
    builder->build = build;
    return builder;
}

void car_builder_destroy(car_builder_t* builder) {
    if (builder->temp_brand[0] != '\0' || builder->temp_brand != NULL) {
        free(builder->temp_brand);
    }

    if (builder->temp_model[0] != '\0' || builder->temp_model != NULL) {
        free(builder->temp_model);
    }

    free(builder);
}