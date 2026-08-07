#include <stdio.h>
#include <stdlib.h>

/*
 * gcc 2_case.c -Wswitch-enum
 * -Wswitch-enum
 * Warn whenever a switch statement has an index of enumerated type and lacks a case for one or more of the named codes of that enumeration.
 *
 * Notice the typedef in the enum. Checkout the Chapter2-Objects-Functions-Types/5_enum.c for other options.
 */

typedef enum { Savings, Checking, MoneyMarket } AccountType;

void assignInterestRate(AccountType account) {
    double interest_rate;

    switch (account) {
        case Savings:
            interest_rate = 3.0;
            break;
        case Checking:
            interest_rate = 1.0;
            break;
        case MoneyMarket:
            interest_rate = 4.5;
            break;
        default:
            abort();
    }
    printf("Interest rate: %g\n", interest_rate);
}

int main() {
    float marks = 98.5f;

    switch ((int)marks/10) {
        case 10:
        case 9:
            puts("Your grade: A");
            break;
        case 8:
            puts("Your grade: B");
            break;
        case 7:
            puts("Your grade: C");
            break;
        default:
            puts("Your grade: Failed");
    }

    puts("--------------------------");

    AccountType account = Savings;
    // AccountType account = MoneyMarket;
    assignInterestRate(account);
}
