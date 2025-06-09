#include "../../../include/factory_method/models/vehicle.h"

c_str vehicle_type_str(const VEHICLE_TYPE type) {
    switch (type) {
        case TRUCK: return "Truck";
        case SHIP:  return "Ship";
        default:    return "Unknown";
    }
}

c_str region_str(const REGION_TYPE region) {
    switch (region) {
        case NORTH: return "North";
        case SOUTH: return "South";
        default:    return "Unknown";
    }
}

c_str city_str(const CITY city) {
    switch (city) {
        case ANTALYA:    return "Antalya";
        case IZMIR:      return "Izmir";
        case BURSA:      return "Bursa";
        case ISTANBUL:   return "Istanbul";
        default:         return "Uknown";
    }
}

REGION_TYPE get_region_by_city(const CITY city) {
    switch (city) {
        case ANTALYA:  return SOUTH;
        case IZMIR:    return SOUTH;
        case BURSA:    return NORTH;
        case ISTANBUL: return NORTH;
        default:       break;
    }
}

static vehicles_t* find_by_city(vehicles_t* logistic, CITY city) {
    vehicles_t* list = (vehicles_t*)malloc(sizeof(vehicles_t));
    if (list == NULL) {
        fprintf(stderr, "Memory Allocation!\n");
        return NULL;
    }

    for (int i = 0; i < logistic->size; i++) {
        if (logistic->vehicles[i]->city == city) {
            if (list->size == 0) {
                list->vehicles = (vehicle_t**)calloc(1, sizeof(vehicle_t));
            }
            else {
                list->vehicles = (vehicle_t**)realloc(list->vehicles, (list->size + 1) * sizeof(vehicle_t));
            }

            list->vehicles[list->size] = logistic->vehicles[i];
            ++list->size;
        }
    }

    return list;
}

vehicle_t* create(double_t load, double_t load_capacity, double_t range, double_t max_range, CITY city, VEHICLE_TYPE type) {
    if (load <= 0 || range <= 0) {
        fprintf(stderr, "Any variable cannot be 0 or negative.\n");
        return NULL;
    }

    if (load > load_capacity) {
        fprintf(stderr, "Exceeds the load capacity of the %s.\n", vehicle_type_str(type));
        return NULL;
    }

    if (range > max_range) {
        fprintf(stderr, "Exceeds the max range of the %s.\n", vehicle_type_str(type));
        return NULL;
    }

    vehicle_t* vehicle = (vehicle_t*)calloc(1, sizeof(vehicle_t));
    if (vehicle == NULL) {
        fprintf(stderr, "Memory Allocation!\n");
        return NULL;
    }

    static char name[BUFFER_SIZE_1024];
    snprintf(name, BUFFER_SIZE_1024, "%s %d", vehicle_type_str(type), rand());

    uuid_generate_random(vehicle->id);
    vehicle->name = strdup(name);
    vehicle->type = type;
    vehicle->max_range = max_range;
    vehicle->load_capacity = load_capacity;
    vehicle->current_load = load;
    vehicle->range = range;
    vehicle->city = city;
    vehicle->region = get_region_by_city(city);
    vehicle->is_on_road = false;
    return vehicle;
}

static double_t cacl_remained_load(double_t load, double_t current_load, double_t load_capacity) {
    return load - load_capacity + current_load;
}

void add_load(vehicle_t* vehicle, double_t load, VEHICLE_TYPE type, vehicles_t* logistic, vehicle_t* (*create)(double_t load, double_t range, CITY city)) {
    if (vehicle->type != type) {
        fprintf(stderr, "Vehicle Type is not match.\n");
        return;
    }

    if (vehicle->current_load + load > vehicle->load_capacity) {
        fprintf(stderr, "Vehicle load capacity is exceeded. The remaining load is tranferring to another truck.\n----\n");

        double_t remained_load = cacl_remained_load(load, vehicle->current_load, vehicle->load_capacity);

        vehicle->current_load = vehicle->load_capacity;
        vehicles_t* list = find_by_city(logistic, vehicle->city);

        if (list->size > 1) {
            for (int i = 0; i < list->size; i++) {
                static vehicle_t* current_vehicle;
                current_vehicle = list->vehicles[i];
                if (vehicle->id != current_vehicle->id && current_vehicle->current_load < current_vehicle->load_capacity) {
                    remained_load = cacl_remained_load(remained_load, current_vehicle->current_load, current_vehicle->load_capacity);
                    current_vehicle->current_load = current_vehicle->load_capacity;
                }
            }
        }

        if (remained_load > 0) {
            static int counter;
            counter = (int)((remained_load / vehicle->load_capacity));
            for (int i = 0; i <= counter; i++) {
                if (remained_load > vehicle->load_capacity) {
                    create(vehicle->load_capacity, vehicle->range, vehicle->city);
                }
                else {
                    create(remained_load, vehicle->range, vehicle->city);    
                }
                remained_load = cacl_remained_load(remained_load, 0, vehicle->load_capacity);
            }
        }
    }
    else {
        vehicle->current_load += load;
    }
}

void push_new_vehicle(vehicles_t* logistic ,vehicle_t* vehicle, void(*init_logistic)(void)) {
    init_logistic();
    if (logistic->vehicles == NULL) {
        logistic->vehicles = (vehicle_t**)calloc(1, sizeof(vehicle_t));
        if (logistic->vehicles == NULL) {
            fprintf(stderr, "Memory Allocation!\n");
            return;
        }
    }
    else {
        logistic->vehicles = (vehicle_t**)realloc(logistic->vehicles, (logistic->size + 1) * sizeof(vehicle_t));
        if (logistic->vehicles == NULL) {
            fprintf(stderr, "Memory Allocation!\n");
            return;
        }
    }

    logistic->vehicles[logistic->size] = vehicle;
    ++logistic->size;
}

void is_on_road(vehicle_t* vehicle) {
    vehicle->is_on_road = true;
}