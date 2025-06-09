#ifndef C_DESIGN_PATTERNS_FACTORY_METHOD_LOGISTIC_FACTORY_H
#define C_DESIGN_PATTERNS_FACTORY_METHOD_LOGISTIC_FACTORY_H

#include "models/road_logistic.h"
#include "models/sea_logistic.h"

typedef enum {
    SEA,
    ROAD
} LOGISTIC_TYPE;

typedef const struct vehicle_const logistic_t;

extern const struct logistic_factory {
    logistic_t (*create_logistic)(LOGISTIC_TYPE type);
} logistic_factory;

#endif // C_DESIGN_PATTERNS_FACTORY_METHOD_CAR_FACTORY_H