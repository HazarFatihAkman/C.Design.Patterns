#ifndef C_DESIGN_PATTERNS_SINGLETON_DATABASE_CONFIG_H
#define C_DESIGN_PATTERNS_SINGLETON_DATABASE_CONFIG_H

#include "../utils.h"

#define DATABASE_PREFIX "database"

typedef struct database_config {
    c_str prefix;    
    c_str value;
} database_config_t;

#endif // C_DESIGN_PATTERNS_SINGLETON_DATABASE_CONFIG_H