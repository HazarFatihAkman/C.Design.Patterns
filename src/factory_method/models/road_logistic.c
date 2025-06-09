#include "../../../include/factory_method/models/road_logistic.h"

static void init_road_logistic() {
    if (road_logistic == NULL) {
        road_logistic = (road_logistic_t*)malloc(sizeof(road_logistic_t));
        if (road_logistic == NULL) {
            fprintf(stderr, "Memory Allocation!\n");
            return;
        }

        road_logistic->size = 0;
    }
}

static vehicle_t* create_truck(double_t load, double_t range, CITY city) {
    init_road_logistic();
    if (road_logistic == NULL) {
        fprintf(stderr, "Road logistic cannot be null.\n");
        return NULL;
    }

    vehicle_t* vehicle = create(load, ROAD_MAX_LOAD, range, ROAD_MAX_RANGE, city, TRUCK);
    push_new_vehicle(road_logistic, vehicle, init_road_logistic);

    return vehicle;
}

static void add_load_truck(vehicle_t* vehicle, double_t load) {
    add_load(vehicle, load, TRUCK, road_logistic, create_truck);
}

static vehicles_t* get_vehicles(void) {
    return road_logistic;
}

const struct vehicle_const road_const = { .create = &create_truck, .add_load = &add_load_truck, .is_on_road = &is_on_road, .get_vehicles = &get_vehicles };