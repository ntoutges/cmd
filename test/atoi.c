#include "../cmd_str.h"
#include <stdio.h>
#include <assert.h>

int main() {
    char buf[100];

    // Check basic ints
    for (int i = -1000; i < 1000; i++) {
        assert(cmd_str_atoi((cmd_str_itoa(i, buf, sizeof(buf)))) == i);
    }

    // Zeroes
    assert(cmd_str_atoi(NULL) == 0);
    assert(cmd_str_atoi("") == 0);

    // Extermes
    assert(cmd_str_atoi("2147483647") == 2147483647);
    assert(cmd_str_atoi("-2147483648") == -2147483648);

    printf("All atoi test cases passed successfully!\n");

    return 0;
}