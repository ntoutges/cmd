/**
 * @file main.c
 * @author Nicholas T. (ntoutges@gmail.com)
 * @brief   Test the `cmd` library and ensure that all features are working as intended
 * @version 1.0
 * @date 2026-05-21
 * 
 * @copyright Copyright (c) 2026
 */

#include <stdio.h>
#include <assert.h>
#include "../cmd.h"

// Helper to send arbitrary command
void send_command(cmd_t* instance, const char* command) {
    for (uint8_t i = 0; command[i]; i++) {
        cmd_recv(instance, command[i]);
    }
    cmd_recv(instance, '\n'); // "Send" command
}

uint8_t checksum = 0; // Proof that regCB was called
cmd_t myCmd;

// Callback to register
// Increment `checksum` by `base` + ogeti(0)
void regCB(void* base) {
    checksum += *((uint8_t*) base);
}

#define EPSILON 0.0001

int main() {
    
    // Initialize buffers
    // cmd_entry_t entries[10];
    // uint8_t buf[100];

    // ======== TEST STATICALLY ALLOCATED CMD INSTANCE ========
    // myCmd = cmd(entries, sizeof(entries) / sizeof(*entries), buf, sizeof(buf) / sizeof(*buf), '!');

    // ======== TEST DYNAMICALLY ALLOCATED CMD INSTANCE ========
    myCmd = cmd_f(10, 100, '!');

    // ========== TEST BASIC GETTERS ========
    send_command(&myCmd, "!test get 1.2 0 --a 10 --b 20 --c 30 -xyz");

    // Check ordered values
    assert(strcmp(cmd_ogets(&myCmd, 0, ""), "test") == 0);
    assert(strcmp(cmd_ogets(&myCmd, 1, ""), "get") == 0);
    assert(strcmp(cmd_ogets(&myCmd, 2, ""), "1.2") == 0);
    assert(strcmp(cmd_ogets(&myCmd, 3, ""), "0") == 0);

    // Check ordered value parsing
    assert(cmd_ogeti(&myCmd, 2, 0) == 1);
    assert(abs(cmd_ogetf(&myCmd, 2, 0) - 1.2) < EPSILON);
    assert(cmd_ogetb(&myCmd, 2, false) == true);
    assert(cmd_ogetb(&myCmd, 3, false) == false);

    // Check unordered values
    assert(strcmp(cmd_ugets(&myCmd, "a", ""), "10") == 0);
    assert(strcmp(cmd_ugets(&myCmd, "b", ""), "20") == 0);
    assert(strcmp(cmd_ugets(&myCmd, "c", ""), "30") == 0);

    // Check unordered parsing
    assert(cmd_ugeti(&myCmd, "a", 0) == 10);
    assert(cmd_ugeti(&myCmd, "b", 0) == 20);
    assert(cmd_ugeti(&myCmd, "c", 0) == 30);
    assert(cmd_ugetb(&myCmd, "a", false) == true);
    assert(cmd_ugetb(&myCmd, "b", false) == true);
    assert(cmd_ugetb(&myCmd, "c", false) == true);

    // Check special flag parsing
    assert(cmd_ugetb(&myCmd, "w", false) == false); // Not present: false
    assert(cmd_ugetb(&myCmd, "x", false) == true); // Present in -xyz block
    assert(cmd_ugetb(&myCmd, "y", false) == true); // Present in -xyz block
    assert(cmd_ugetb(&myCmd, "z", false) == true); // Present in -xyz block

    // ======== TEST COMMAND-SPECIFIC CALLBACKS ========

    // Add in callback
    uint8_t base = 1;
    uint8_t inc_id = cmd_attach(&myCmd, "inc", regCB, &base);

    send_command(&myCmd, "!inc");
    assert(checksum == 1);

    send_command(&myCmd, "!inc");
    assert(checksum == 2);

    send_command(&myCmd, "!nop");
    assert(checksum == 2); // Didn't increment

    send_command(&myCmd, "!inc");
    assert(checksum == 3); // Didn't increment

    // ======== ENSURE CALLBACKS CAN BE DETACHED ========
    cmd_detach(&myCmd, inc_id);
    checksum = 0; // Reset checksum

    send_command(&myCmd, "!inc");
    assert(checksum == 0); // Should NOP now

    return 0;
}
