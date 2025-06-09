#ifndef C_DESIGN_PATTERNS_UTILS_H
#define C_DESIGN_PATTERNS_UTILS_H

#include <stdio.h>
#include <stdlib.h>

typedef char* str;
typedef const char* c_str;

#define BUFFER_SIZE_1024 1024
#define true 1
#define false 0

c_str read_file(c_str file_path);

#endif // C_DESIGN_PATTERNS_UTILS_H