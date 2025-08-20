#pragma once

#include <string>
#include <memory>
#include "user.h"

std::shared_ptr<User> login();
std::shared_ptr<User> registerUser();
void loginMenu();
bool saveUserToFile(const User& user);
std::shared_ptr<User> loadUserFromFile(const std::string& username);
