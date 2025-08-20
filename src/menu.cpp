#include <iostream>
#include <string>
#include "menu.h"
#include "utils.h"

void displayWelcomeScreen() {
    std::cout << "\033[1;34m" // Blue text
              << "Amortizer v0.0.1\n"
              << "(c) 2025 Your Name. MIT License.\n"
              << "\033[0m"; // Reset color
}

void loginMenu() {
    std::cout << "[1] Sign In\n[2] Register\n";
    // Handle input
}

void showMainMenu() {
    std::cout << "Main Menu:\n"
              << "[1] New Loan\n[2] Settings\n[3] Exit\n";
    // Handle navigation
}
