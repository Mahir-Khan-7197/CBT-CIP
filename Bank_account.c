#include <stdio.h>
#include <string.h>

#define MAX_ACCOUNTS 100

struct BankAccount {
    int accountNumber;
    char holderName[50];
    float balance;
    char accountType[20];
};

void createAccount(struct BankAccount accounts[], int *count) {
    if (*count >= MAX_ACCOUNTS) {
        printf("Cannot create more accounts.\n");
        return;
    }

    printf("\nEnter Account Number: ");
    scanf("%d", &accounts[*count].accountNumber);

    printf("Enter Account Holder Name: ");
    scanf("%s", accounts[*count].holderName);

    printf("Enter Account Type (Savings/Current): ");
    scanf("%s", accounts[*count].accountType);

    printf("Enter Initial Balance: ");
    scanf("%f", &accounts[*count].balance);

    (*count)++;
    printf("Account created successfully.\n");
}

void deposit(struct BankAccount accounts[], int count) {
    int accNo;
    float amount;
    int i;

    printf("\nEnter Account Number: ");
    scanf("%d", &accNo);

    for (i = 0; i < count; i++) {
        if (accounts[i].accountNumber == accNo) {
            printf("Enter Amount to Deposit: ");
            scanf("%f", &amount);
            accounts[i].balance += amount;
            printf("Deposit successful. New Balance: %.2f\n", accounts[i].balance);
            return;
        }
    }

    printf("Account not found.\n");
}

void withdraw(struct BankAccount accounts[], int count) {
    int accNo;
    float amount;
    int i;

    printf("\nEnter Account Number: ");
    scanf("%d", &accNo);

    for (i = 0; i < count; i++) {
        if (accounts[i].accountNumber == accNo) {
            printf("Enter Amount to Withdraw: ");
            scanf("%f", &amount);

            if (amount > accounts[i].balance) {
                printf("Insufficient balance.\n");
            } else {
                accounts[i].balance -= amount;
                printf("Withdrawal successful. New Balance: %.2f\n", accounts[i].balance);
            }
            return;
        }
    }

    printf("Account not found.\n");
}

void checkBalance(struct BankAccount accounts[], int count) {
    int accNo;
    int i;

    printf("\nEnter Account Number: ");
    scanf("%d", &accNo);

    for (i = 0; i < count; i++) {
        if (accounts[i].accountNumber == accNo) {
            printf("Account Holder: %s\n", accounts[i].holderName);
            printf("Balance: %.2f\n", accounts[i].balance);
            return;
        }
    }

    printf("Account not found.\n");
}

void calculateInterest(struct BankAccount accounts[], int count) {
    int accNo;
    float interestRate, interest;
    int i;

    printf("\nEnter Account Number: ");
    scanf("%d", &accNo);

    for (i = 0; i < count; i++) {
        if (accounts[i].accountNumber == accNo) {
            if (strcmp(accounts[i].accountType, "Savings") == 0) {
                interestRate = 0.04f;
            } else if (strcmp(accounts[i].accountType, "Current") == 0) {
                interestRate = 0.03f;
            } else {
                printf("Unknown account type.\n");
                return;
            }

            interest = accounts[i].balance * interestRate;
            printf("Interest for account %d: %.2f\n", accNo, interest);
            return;
        }
    }

    printf("Account not found.\n");
}

int main() {
    struct BankAccount accounts[MAX_ACCOUNTS];
    int count = 0;
    int choice;

    do {
        printf("\n=== Bank Account Management System ===\n");
        printf("1. Create Account\n");
        printf("2. Deposit\n");
        printf("3. Withdraw\n");
        printf("4. Check Balance\n");
        printf("5. Calculate Interest\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                createAccount(accounts, &count);
                break;
            case 2:
                deposit(accounts, count);
                break;
            case 3:
                withdraw(accounts, count);
                break;
            case 4:
                checkBalance(accounts, count);
                break;
            case 5:
                calculateInterest(accounts, count);
                break;
            case 6:
                printf("Exiting program. Thank you!\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }
    } while (choice != 6);

    return 0;
}

