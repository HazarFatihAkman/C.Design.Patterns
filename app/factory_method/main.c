#include "../../include/factory_method/logistic_factory.h"

int main(void) {
    logistic_t sea_logistic = logistic_factory.create_logistic(SEA);
    sea_logistic.create(10000, 2000, ANTALYA);
    sea_logistic.create(20000, 1000, IZMIR);
    sea_logistic.create(58000, 5000, ISTANBUL);
    sea_logistic.create(28610, 5000, BURSA);

    vehicles_t* ships = sea_logistic.get_vehicles();
    printf("\n-----\nSEA LOGISTIC - SHIPS\n");
    for (int i = 0; i < ships->size; i++) {
        print_info(ships->vehicles[i]);
    }

    logistic_t road_logistic = logistic_factory.create_logistic(ROAD);
    road_logistic.create(1870, 1500, ANTALYA);
    road_logistic.create(2000, 1000, IZMIR);
    road_logistic.create(5000, 1000, ISTANBUL);
    road_logistic.create(8750, 500, BURSA);

    vehicles_t* trucks = road_logistic.get_vehicles();
    printf("\n-----\nROAD LOGISTIC - TRUCKS\n");
    for (int i = 0; i < trucks->size; i++) {
        print_info(trucks->vehicles[i]);
    }

    return 0;
}