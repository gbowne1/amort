#include <gtest/gtest.h>
#include "loan.h"

TEST(LoanTest, MonthlyPaymentCalculation) {
    Loan loan(10000.0, 0.05, 12); // $10,000, 5% annual interest, 12 months
    double monthlyPayment = loan.calculateMonthlyPayment();

    // Approx expected payment ≈ $856.07
    EXPECT_NEAR(monthlyPayment, 856.07, 0.5);
}

TEST(LoanTest, ScheduleSizeMatchesPayments) {
    Loan loan(5000.0, 0.04, 24); // 24 months
    auto schedule = loan.generateAmortizationSchedule();
    EXPECT_EQ(schedule.size(), 24);
}

TEST(LoanTest, ScheduleBalanceDecreases) {
    Loan loan(2000.0, 0.06, 6); // short-term loan
    auto schedule = loan.generateAmortizationSchedule();

    double prevBalance = 999999.0;
    for (const auto& payment : schedule) {
        EXPECT_LT(payment.balance, prevBalance);
        prevBalance = payment.balance;
    }
}
