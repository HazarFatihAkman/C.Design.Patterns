#ifndef C_DESIGN_PATTERNS_SINGLETON_CONFIG_MANAGER_H
#define C_DESIGN_PATTERNS_SINGLETON_CONFIG_MANAGER_H

#include <pthread.h>
#include <jansson.h>

#include "../utils.h"
#include "version_config.h"
#include "database_config.h"

#define CONFIG_PATH "static/config.json"

typedef struct config_manager {
    version_config_t version;
    database_config_t database;
} config_manager_t;

extern const struct config_manager_const {
    config_manager_t* (*get_instance)(pthread_mutex_t* lock);
} config_manager_const;

static pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;

#endif // C_DESIGN_PATTERNS_SINGLETON_CONFIG_MANAGER_H