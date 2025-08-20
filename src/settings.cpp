#include "settings.h"
#include <iostream>

void Settings::load() {
    // Placeholder: Load settings from file (optional)
    // For now, uses defaults
}

void Settings::save() const {
    // Placeholder: Save settings to file
    std::cout << "Settings saved.\n";
}

void Settings::display() const {
    std::cout << "Current Settings:\n";
    std::cout << "Color Output: " << (colorOutput ? "Yes" : "No") << "\n";
    std::cout << "Show Progress Bars: " << (showProgressBar ? "Yes" : "No") << "\n";
    std::cout << "Preferred Currency: " << preferredCurrency << "\n";
}

void Settings::edit() {
    std::string input;
    std::cout << "Toggle Color Output (y/n): ";
    std::getline(std::cin, input);
    colorOutput = (input == "y" || input == "Y");

    std::cout << "Toggle Progress Bars (y/n): ";
    std::getline(std::cin, input);
    showProgressBar = (input == "y" || input == "Y");

    std::cout << "Preferred Currency (e.g. USD, EUR): ";
    std::getline(std::cin, preferredCurrency);
}
