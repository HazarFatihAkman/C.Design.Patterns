#include "../../include/singleton/config_manager.h"

static config_manager_t* config_manager;

static void print_version(void) {
    fprintf(stderr, "%s : %s\n", config_manager->version.prefix, config_manager->version.value);
}

static void print_database_conn_str(void) {
    fprintf(stderr, "%s : %s\n", config_manager->database.prefix, config_manager->database.value);
}

static void print_config(void) {
    print_version();
    print_database_conn_str();
}

static void* thread_1(void* arg) {
    pthread_mutex_lock(&lock);
    fprintf(stderr, "Thread 1\n----\n");

    config_manager = (config_manager_t*)arg;
    print_config();

    fprintf(stderr, "----\n");

    pthread_mutex_unlock(&lock);
    return NULL;
}

static void* thread_2(void* arg) {
    pthread_mutex_lock(&lock);
    fprintf(stderr, "Thread 2\n----\n");

    config_manager = (config_manager_t*)arg;
    print_config();

    fprintf(stderr, "----\n");

    pthread_mutex_unlock(&lock);
    return NULL;
}

int main(void) {
    pthread_t th1, th2;
    pthread_create(&th1, NULL, thread_1, config_manager_const.get_instance(&lock));
    pthread_create(&th2, NULL, thread_2, config_manager_const.get_instance(&lock));

    pthread_join(th1, NULL);
    pthread_join(th2, NULL);

    pthread_mutex_destroy(&lock);
    return 0;
}