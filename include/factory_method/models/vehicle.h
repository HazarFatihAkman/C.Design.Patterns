#ifndef C_DESIGN_PATTERNS_FACTORY_METHOD_VEHICLE_H
#define C_DESIGN_PATTERNS_FACTORY_METHOD_VEHICLE_H

#include "../../utils.h"
#include <uuid/uuid.h>
#include <math.h>
#include <stdint.h>
#include <string.h>
#include <stdbool.h>

#define print_info(vehicle) fprintf(stderr, "| Name : %s\n| Type : %s\n| Region & City : %s, %s\n| Current Load : %.2f TON / %.2f TON\n| Range : %.2f km / %.2f km\n----\n", vehicle->name, vehicle_type_str(vehicle->type), region_str(vehicle->region), city_str(vehicle->city), (vehicle->current_load / 1000), (vehicle->load_capacity / 1000), vehicle->range, vehicle->max_range);

typedef enum {
    TRUCK,
    SHIP
} VEHICLE_TYPE;

typedef enum {
    NORTH,
    SOUTH
} REGION_TYPE;

typedef enum {
    ANTALYA, //SOUTH
    IZMIR,   //SOUTH
    BURSA,   //NORTH
    ISTANBUL //NORTH
} CITY;

typedef struct vehicle {
    uuid_t id;
    c_str name;
    VEHICLE_TYPE type;
    double_t max_range;
    double_t load_capacity;
    CITY city;
    REGION_TYPE region;

    double_t current_load;
    double_t range;
    bool is_on_road;
} vehicle_t;

typedef struct vehicles {
    size_t size;
    vehicle_t** vehicles;
} vehicles_t;

extern const struct vehicle_const {
    vehicle_t* (*create)(double_t load, double_t range, CITY city);
    void (*add_load)(vehicle_t* vehicle, double_t load);
    void (*is_on_road)(vehicle_t* vehicle);
    vehicles_t* (*get_vehicles)(void);
} vehicle_const;

c_str vehicle_type_str(const VEHICLE_TYPE type);
c_str region_str(const REGION_TYPE region);
c_str city_str(const CITY city);

REGION_TYPE get_region_by_city(const CITY city);

vehicle_t* create(double_t load, double_t load_capacity, double_t range, double_t max_range, CITY city, VEHICLE_TYPE type);
void add_load(vehicle_t* vehicle, double_t load, VEHICLE_TYPE type, vehicles_t* logistic, vehicle_t* (*create)(double_t load, double_t range, CITY city));
void is_on_road(vehicle_t* vehicle);
void push_new_vehicle(vehicles_t* logistic ,vehicle_t* vehicle, void(*init_logistic)(void));

#endif //C_DESIGN_PATTERNS_FACTORY_METHOD_VEHICLE_H