#include "../include/utils.h"

c_str read_file(c_str file_path) {
    static char file_str[BUFFER_SIZE_1024];

    FILE* stream = fopen(file_path, "r");
    if (!stream) {
        fprintf(stderr, "File error.\n");
        return NULL;
    }

    fseek(stream, 0, SEEK_END);
    size_t stream_len = ftell(stream);
    rewind(stream);

    fread(file_str, 1, stream_len, stream);
    file_str[stream_len] = '\0';
    fclose(stream);
    return file_str;
}