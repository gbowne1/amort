#include "user.h"
#include "utils.h"

User::User(const std::string& username, const std::string& hashedPassword)
    : username(username), hashedPassword(hashedPassword) {}

const std::string& User::getUsername() const {
    return username;
}

const std::string& User::getHashedPassword() const {
    return hashedPassword;
}

bool User::verifyPassword(const std::string& plainPassword) const {
    return hashedPassword == sha256(plainPassword);
}
