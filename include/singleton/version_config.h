#ifndef C_DESIGN_PATTERNS_SINGLETON_VERSION_CONFIG_H
#define C_DESIGN_PATTERNS_SINGLETON_VERSION_CONFIG_H

#include "../utils.h"

#define VERSION_PREFIX "version"

typedef struct version_config {
    c_str prefix;
    c_str value;
} version_config_t;

#endif // C_DESIGN_PATTERNS_SINGLETON_VERSION_CONFIG_H