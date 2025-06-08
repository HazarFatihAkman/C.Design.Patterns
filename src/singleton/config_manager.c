#include "../../include/singleton/config_manager.h"

config_manager_t* config_manager;
static void set_config(void);

static config_manager_t* get_instance(pthread_mutex_t *lock) {
    if (config_manager == NULL) {
        pthread_mutex_lock(lock);
        config_manager = (config_manager_t*) calloc(1, sizeof(config_manager_t));
        if (config_manager == NULL) {
            fprintf(stderr, "Memory Allocation!\n");
            return NULL;
        }
        set_config();
        pthread_mutex_unlock(lock);
    }

    return config_manager;    
}

static void set_config(void) {
    static c_str file_str;
    file_str = read_file(CONFIG_PATH);

    json_error_t err;
    json_t* root = json_loads(file_str, 0, &err);
    if (!root || !json_is_object(root)) {
        fprintf(stderr, "root : INVALID JSON\n");
        free(config_manager);
        return;
    }

    config_manager->version.prefix = VERSION_PREFIX;
    config_manager->version.value = json_string_value(json_object_get(root, config_manager->version.prefix));
    if (!config_manager->version.value) {
        fprintf(stderr, "Missing value for version.\n");
        free(config_manager);
        json_decref(root);
        return;
    }

    config_manager->database.prefix = DATABASE_PREFIX;
    config_manager->database.value = json_string_value(json_object_get(root, config_manager->database.prefix));
    if (!config_manager->database.value) {
        fprintf(stderr, "Missing value for database.\n");
        free(config_manager);
        json_decref(root);
        return;
    }

    fprintf(stderr, "[INFO] : Config is set.\n");
}

const struct config_manager_const config_manager_const = { .get_instance = &get_instance };