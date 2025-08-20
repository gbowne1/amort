#include "login.h"
#include "utils.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <filesystem>

namespace fs = std::filesystem;

const std::string USERS_FILE = "data/users.csv";

void loginMenu() {
    int choice = 0;
    while (choice != 3) {
        std::cout << "\033[1;36mLogin Menu:\033[0m\n";
        std::cout << "[1] Sign In\n[2] Register\n[3] Exit\n> ";
        std::cin >> choice;
        std::cin.ignore();

        std::shared_ptr<User> currentUser;

        switch (choice) {
            case 1:
                currentUser = login();
                if (currentUser) {
                    std::cout << "Welcome back, " << currentUser->getUsername() << "!\n";
                    return;
                }
                break;
            case 2:
                currentUser = registerUser();
                if (currentUser) {
                    std::cout << "User " << currentUser->getUsername() << " registered successfully.\n";
                    return;
                }
                break;
            case 3:
                std::cout << "Exiting login menu.\n";
                break;
            default:
                std::cout << "Invalid option. Try again.\n";
        }
    }
}

std::shared_ptr<User> login() {
    std::string username, password;

    std::cout << "Username: ";
    std::getline(std::cin, username);

    std::cout << "Password: ";
    std::getline(std::cin, password);

    auto user = loadUserFromFile(username);
    if (!user) {
        std::cerr << "\033[1;31mUser not found.\033[0m\n";
        return nullptr;
    }

    if (user->verifyPassword(password)) {
        return user;
    } else {
        std::cerr << "\033[1;31mIncorrect password.\033[0m\n";
        return nullptr;
    }
}

std::shared_ptr<User> registerUser() {
    std::string username, password;

    std::cout << "Choose a username: ";
    std::getline(std::cin, username);

    if (fs::exists(USERS_FILE)) {
        auto existing = loadUserFromFile(username);
        if (existing) {
            std::cerr << "\033[1;31mUsername already exists.\033[0m\n";
            return nullptr;
        }
    }

    std::cout << "Choose a password: ";
    std::getline(std::cin, password);

    std::string hashed = sha256(password);
    User newUser(username, hashed);

    if (saveUserToFile(newUser)) {
        return std::make_shared<User>(newUser);
    }

    return nullptr;
}

bool saveUserToFile(const User& user) {
    std::ofstream file(USERS_FILE, std::ios::app);
    if (!file.is_open()) {
        std::cerr << "\033[1;31mFailed to open user file.\033[0m\n";
        return false;
    }

    file << user.getUsername() << "," << user.getHashedPassword() << "\n";
    file.close();
    return true;
}

std::shared_ptr<User> loadUserFromFile(const std::string& username) {
    std::ifstream file(USERS_FILE);
    if (!file.is_open()) {
        return nullptr;
    }

    std::string line;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string user, hash;

        if (std::getline(iss, user, ',') && std::getline(iss, hash)) {
            if (user == username) {
                return std::make_shared<User>(user, hash);
            }
        }
    }

    return nullptr;
}
