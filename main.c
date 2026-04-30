#include <stdio.h>
#include "cmd.h"

cmd_t myCmd;

uint8_t bufBuf[40];
cmd_entry_t entryBuf[10];

int main() {
    myCmd = cmd(entryBuf, 10, bufBuf, sizeof(bufBuf), '!');

    // char* command = "!hello world a\n";
    // for (int i = 0; i < strlen(command); i++) {
    //     cmd_recv(&myCmd, command[i]);
    // }

    // printf("0: %s\n", cmd_ogets(&myCmd, 0, "/"));
    // printf("1: %s\n", cmd_ogets(&myCmd, 1, "/"));
    // printf("2: %s\n", cmd_ogets(&myCmd, 2, "/"));

    // printf("\n----\n\n");

    // char* command2 = "!hello world --a b c d\n";
    // for (int i = 0; i < strlen(command2); i++) {
    //     cmd_recv(&myCmd, command2[i]);
    // }

    // printf("0: %s\n", cmd_ogets(&myCmd, 0, "/"));
    // printf("1: %s\n", cmd_ogets(&myCmd, 1, "/"));
    // printf("2: %s\n", cmd_ogets(&myCmd, 2, "/"));
    // printf("3: %s\n", cmd_ogets(&myCmd, 3, "/"));
    // printf("4: %s\n", cmd_ogets(&myCmd, 4, "/"));
    // printf("5: %s\n", cmd_ogets(&myCmd, 5, "/"));
    // printf("a: %s\n", cmd_ugets(&myCmd, "a", "/"));

    // printf("\n----\n\n");

    // char* command3 = "!hello world this is a command overrun that is way too long!\n";
    // for (int i = 0; i < strlen(command3); i++) {
    //     cmd_recv(&myCmd, command3[i]);
    // }

    // printf("0: %s\n", cmd_ogets(&myCmd, 0, "/"));
    // printf("1: %s\n", cmd_ogets(&myCmd, 1, "/"));
    // printf("2: %s\n", cmd_ogets(&myCmd, 2, "/"));
    // printf("3: %s\n", cmd_ogets(&myCmd, 3, "/"));
    // printf("4: %s\n", cmd_ogets(&myCmd, 4, "/"));

    // printf("\n----\n\n");

    char* command4 = "!dir magnet --safe 0 --test a\n";
    for (int i = 0; i < strlen(command4); i++) {
        cmd_recv(&myCmd, command4[i]);
    }

    // Print out bufBuf
    for (int i = 0; i < sizeof(bufBuf); i++) {
        char c = bufBuf[i];

        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9')) {
            printf("%c ", c);
        } else if (c == 0x00) {
            printf("/ ");
        } else {
            printf("%02X ", c);
        }
    }
    printf("\n");

    printf("0: %s\n", cmd_ogets(&myCmd, 0, "/"));
    printf("1: %s\n", cmd_ogets(&myCmd, 1, "/"));
    printf("safe: %d\n", cmd_ugetb(&myCmd, "safe", true));

    return 0;
}