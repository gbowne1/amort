#include <gtest/gtest.h>
#include "utils.h"

TEST(UtilsTest, Sha256HashMocked) {
    std::string input = "secure";
    std::string expected = "hashed_secure";
    EXPECT_EQ(sha256(input), expected);
}

TEST(UtilsTest, TimestampFormat) {
    std::string timestamp = getTimestamp();

    // Expect format: YYYY-MM-DD HH:MM:SS
    EXPECT_EQ(timestamp.length(), 19);
    EXPECT_EQ(timestamp[4], '-');
    EXPECT_EQ(timestamp[7], '-');
    EXPECT_EQ(timestamp[10], ' ');
    EXPECT_EQ(timestamp[13], ':');
    EXPECT_EQ(timestamp[16], ':');
}
