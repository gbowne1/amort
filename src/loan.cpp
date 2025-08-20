#include "loan.h"
#include <iostream>
#include <cmath>
#include <iomanip>

Loan::Loan(double amount, double annualRate, int termMonths)
    : loanAmount(amount), annualInterestRate(annualRate), numPayments(termMonths) {}

double Loan::calculateMonthlyPayment() const {
    double monthlyRate = annualInterestRate / 12;
    return (loanAmount * monthlyRate) / (1 - std::pow(1 + monthlyRate, -numPayments));
}

std::vector<Payment> Loan::generateAmortizationSchedule() const {
    std::vector<Payment> schedule;
    double monthlyPayment = calculateMonthlyPayment();
    double balance = loanAmount;
    double monthlyRate = annualInterestRate / 12;

    for (int i = 1; i <= numPayments; ++i) {
        double interest = balance * monthlyRate;
        double principal = monthlyPayment - interest;
        balance -= principal;

        schedule.push_back({i, principal, interest, balance});
    }
    return schedule;
}

void Loan::printSchedule() const {
    auto schedule = generateAmortizationSchedule();
    std::cout << "Payment\tPrincipal\tInterest\tRemaining\n";
    for (const auto& p : schedule) {
        std::cout << p.paymentNumber << "\t$"
                  << std::setw(10) << p.principal << "\t$"
                  << std::setw(8) << p.interest << "\t$"
                  << std::setw(10) << p.balance << "\n";
    }
}
