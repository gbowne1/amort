#include <iostream>
#include <iomanip>
#include <thread>
#include <chrono>
#include "menu.h"
#include "utils.h"

int main() {
    displayWelcomeScreen(); // clears after 3 seconds
    std::this_thread::sleep_for(std::chrono::seconds(3));
    clearScreen();

    loginMenu(); // signin/signup/register

    showMainMenu(); // Interactive main menu
    return 0;
}
