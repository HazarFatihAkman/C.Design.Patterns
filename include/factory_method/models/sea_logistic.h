#ifndef C_DESIGN_PATTERNS_FACTORY_METHOD_SEA_LOGISTIC_H
#define C_DESIGN_PATTERNS_FACTORY_METHOD_SEA_LOGISTIC_H

#include "vehicle.h"

#define SEA_MAX_RANGE 10000
#define SEA_MAX_LOAD  1000000

extern const struct vehicle_const sea_const;
typedef vehicles_t sea_logistic_t;

sea_logistic_t* sea_logistic;

#endif // C_DESIGN_PATTERNS_FACTORY_METHOD_SEA_LOGISTIC_H