#pragma once
#include <vector>
#include <string>

struct Payment {
    int paymentNumber;
    double principal;
    double interest;
    double balance;
};

class Loan {
public:
    Loan(double amount, double annualRate, int termMonths);
    double calculateMonthlyPayment() const;
    std::vector<Payment> generateAmortizationSchedule() const;
    void printSchedule() const;

private:
    double loanAmount;
    double annualInterestRate;
    int numPayments;
};
