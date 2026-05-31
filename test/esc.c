#include <stdio.h>
#include <assert.h>
#include "../cmd.h"

int main() {
    cmd_t sh = cmd_f('!', 10, 64, NULL);

    // ======== Ensure escape characters properly registered _and_ ignored ========
    assert(cmd_recvs(&sh, "!escape \"Some \\\"escaped\\\" string\" here\n"));

    assert(strcmp(cmd_ogets(&sh, 0, ""), "escape") == 0);
    assert(strcmp(cmd_ogets(&sh, 1, ""), "Some \"escaped\" string") == 0);
    assert(strcmp(cmd_ogets(&sh, 2, ""), "here") == 0);

    // ======== Test basic basic escape sequences ========
    assert(cmd_recvs(&sh, "!escaped \\\\ \\\"\n"));

    assert(strcmp(cmd_ogets(&sh, 0, ""), "escaped") == 0);
    assert(strcmp(cmd_ogets(&sh, 1, ""), "\\") == 0);
    assert(strcmp(cmd_ogets(&sh, 2, ""), "\"") == 0);

    printf("All esc test cases passed successfully!\n");

    return 0;
}