#include <stdlib.h>
#include <errno.h>
#include <limits.h>



int digit(char *addres_num, int num) {
    char *end;
    char ch = '.';
    double value = 0;

    if (num < 0) {
        return 1;
    }

    errno = 0;

    value = strtod(addres_num, &end);

    if (errno == ERANGE) {
        return 2;
    }

    if (end == addres_num || *end != '\0') {
        return 1;
    }

    if (*addres_num == ch || *(addres_num + num) == ch) {
        return 1;
    }

    if ((value < INT_MIN) || (value > INT_MAX)) {
        return 2;
    }
 

    return 0;
}


