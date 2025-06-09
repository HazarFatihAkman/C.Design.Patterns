#ifndef C_DESIGN_PATTERNS_FACTORY_METHOD_ROAD_LOGISTIC_H
#define C_DESIGN_PATTERNS_FACTORY_METHOD_ROAD_LOGISTIC_H

#include "vehicle.h"

#define ROAD_MAX_RANGE 1500
#define ROAD_MAX_LOAD  10000

extern const struct vehicle_const road_const;
typedef vehicles_t road_logistic_t;

road_logistic_t* road_logistic;

#endif // C_DESIGN_PATTERNS_FACTORY_METHOD_ROAD_LOGISTIC_H