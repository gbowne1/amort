#include "utils.h"
#include <iostream>
#include <ctime>
#include <sstream>
#include <iomanip>
#include <cstdlib>

void clearScreen() {
    std::system("clear"); // or "cls" for Windows
}

std::string getTimestamp() {
    std::time_t now = std::time(nullptr);
    std::tm* ptm = std::localtime(&now);
    std::ostringstream oss;
    oss << std::put_time(ptm, "%Y-%m-%d %H:%M:%S");
    return oss.str();
}

// Dummy SHA256 placeholder (replace with actual implementation)
std::string sha256(const std::string& input) {
    // TODO: Implement a real SHA256 hash (no external libraries allowed)
    // Placeholder:
    return "hashed_" + input;
}

