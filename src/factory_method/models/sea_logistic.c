#include "../../../include/factory_method/models/sea_logistic.h"

static void init_sea_logistic() {
    if (sea_logistic == NULL) {
        sea_logistic = (sea_logistic_t*)malloc(sizeof(sea_logistic_t));
        if (sea_logistic == NULL) {
            fprintf(stderr, "Memory Allocation!\n");
            return;
        }

        sea_logistic->size = 0;
    }
}

static vehicle_t* create_ship(double_t load, double_t range, CITY city) {
    init_sea_logistic();
    if (sea_logistic == NULL) {
        fprintf(stderr, "Sea logistic cannot be null.\n");
        return NULL;
    }

    vehicle_t* vehicle = create(load, SEA_MAX_LOAD, range, SEA_MAX_RANGE, city, SHIP);
    push_new_vehicle(sea_logistic, vehicle, init_sea_logistic);

    return vehicle;
}

static void add_load_ship(vehicle_t* vehicle, double_t load) {
    add_load(vehicle, load, SHIP, sea_logistic, create_ship);
}

static vehicles_t* get_vehicles(void) {
    return sea_logistic;
}

const struct vehicle_const sea_const = { .create = &create_ship, .add_load = &add_load_ship, .is_on_road = &is_on_road, .get_vehicles = &get_vehicles };