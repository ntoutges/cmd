#include "../cmd_str.h"
#include <stdio.h>
#include <assert.h>

int main() {
    char buf[100];

    // Check all 16-bit ints
    for (int i = -32768; i < 32768; i++) {
        assert(atoi(cmd_str_itoa(i, buf, sizeof(buf))) == i);
    }

    // Check extremes
    assert(atoi(cmd_str_itoa(2147483647, buf, sizeof(buf))) == 2147483647);
    assert(atoi(cmd_str_itoa(-2147483648, buf, sizeof(buf))) == -2147483648);

    printf("All itoa test cases passed successfully!\n");

    return 0;
}