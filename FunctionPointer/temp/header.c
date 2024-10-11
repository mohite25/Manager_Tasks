#include "header.h"

// Function to handle the tab character
void handleTab() {
    putchar('\\');
    putchar('t');
}

// Function to handle the backspace character
void handleBackspace() {
    putchar('\\');
    putchar('b');
}

// Function to handle the backslash character
void handleBackslash() {
    putchar('\\');
    putchar('\\');
}

// Function to handle other characters (default behavior)
void handleDefault(int ic) {
    putchar(ic);
}

