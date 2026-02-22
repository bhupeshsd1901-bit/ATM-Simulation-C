#include <stdio.h>
#include <stdlib.h>

float balance = 1000.0;   // Initial balance
int pin = 1901;           // Default PIN

void checkBalance() {
    printf("\nYour current balance is: ₹%.2f\n", balance);
}

void depositMoney() {
    float amount;
    printf("\nEnter amount to deposit: ₹");
    scanf("%f", &amount);

    if (amount > 0) {
        balance += amount;
        printf("₹%.2f deposited successfully.\n", amount);
    } else {
        printf("Invalid deposit amount!\n");
    }
}

void withdrawMoney() {
    float amount;
    printf("\nEnter amount to withdraw: ₹");
    scanf("%f", &amount);

    if (amount <= 0) {
        printf("Invalid withdrawal amount!\n");
    } 
    else if (amount > balance) {
        printf("Insufficient balance!\n");
    } 
    else {
        balance -= amount;
        printf("₹%.2f withdrawn successfully.\n", amount);
    }
}

int authenticate() {
    int enteredPin;
    printf("Enter your 4-digit PIN: ");
    scanf("%d", &enteredPin);

    if (enteredPin == pin) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    int choice;

    printf("===== Welcome to Simple ATM System =====\n");

    if (!authenticate()) {
        printf("Incorrect PIN! Access Denied.\n");
        return 0;
    }

    do {
        printf("\n===== ATM MENU =====\n");
        printf("1. Check Balance\n");
        printf("2. Deposit Money\n");
        printf("3. Withdraw Money\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                checkBalance();
                break;
            case 2:
                depositMoney();
                break;
            case 3:
                withdrawMoney();
                break;
            case 4:
                printf("Thank you for using our ATM!\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }

    } while (choice != 4);

    return 0;
}