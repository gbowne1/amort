#pragma once

#include <string>

class User {
public:
    User(const std::string& username, const std::string& hashedPassword);

    const std::string& getUsername() const;
    const std::string& getHashedPassword() const;

    bool verifyPassword(const std::string& plainPassword) const;

private:
    std::string username;
    std::string hashedPassword;
};
