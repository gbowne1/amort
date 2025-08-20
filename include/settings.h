#pragma once

#include <string>

struct Settings {
    bool colorOutput = true;
    bool showProgressBar = true;
    std::string preferredCurrency = "USD";

    void load();
    void save() const;
    void display() const;
    void edit();
};
