#include <gtest/gtest.h>
#include "user.h"
#include "utils.h"

TEST(UserTest, CreationAndAccessors) {
    User user("testuser", "hashed_password123");
    EXPECT_EQ(user.getUsername(), "testuser");
    EXPECT_EQ(user.getHashedPassword(), "hashed_password123");
}

TEST(UserTest, VerifyPasswordSuccess) {
    std::string plain = "mypassword";
    std::string hashed = sha256(plain); // sha256() returns "hashed_" + input
    User user("tester", hashed);
    EXPECT_TRUE(user.verifyPassword(plain));
}

TEST(UserTest, VerifyPasswordFailure) {
    std::string correct = "mypassword";
    std::string incorrect = "wrongpass";
    User user("tester", sha256(correct));
    EXPECT_FALSE(user.verifyPassword(incorrect));
}
