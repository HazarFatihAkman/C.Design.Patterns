#include "../../include/factory_method/logistic_factory.h"

static logistic_t create_logistic(LOGISTIC_TYPE type) {
    switch (type) {
        case SEA: return sea_const;
        case ROAD: return road_const;
        default: break;
    }
}

const struct logistic_factory logistic_factory = { .create_logistic = &create_logistic };
