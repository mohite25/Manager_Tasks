#include "header.h"

int main() {
    int ic;
    void (*escapeHandler[256])(); // Array of function pointers

    // Initialize all pointers to handleDefault function
    for (int i = 0; i < 256; i++) {
        escapeHandler[i] = (void (*)())handleDefault;
    }

    // Assign specific function pointers for escape sequences
    escapeHandler['\t'] = handleTab;
    escapeHandler['\b'] = handleBackspace;
    escapeHandler['\\'] = handleBackslash;

    printf("This program will replace escape sequences with their symbol\n");

    // Read characters until End-of-file (EOF) is detected
    while ((ic = getchar()) != EOF) {
        escapeHandler[ic](ic); // Call appropriate function using function pointer
    }

    return 0;
}

