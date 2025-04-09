#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

typedef struct {
    char date[15];
    char category[30];
    float amount;
    char note[100];
} Expense;

void addExpense() {
    FILE *fp = fopen("expenses.txt", "a");
    if (fp == NULL) {
        printf("Error opening file.\n");
        return;
    }

    Expense e;

    printf("Enter date (DD-MM-YYYY): ");
    scanf("%s", e.date);
    printf("Enter category (e.g., Food, Travel, Bills): ");
    scanf("%s", e.category);
    printf("Enter amount: ");
    scanf("%f", &e.amount);
    getchar(); // to clear buffer
    printf("Enter note (optional): ");
    fgets(e.note, sizeof(e.note), stdin);
    e.note[strcspn(e.note, "\n")] = 0; // remove newline

    fprintf(fp, "%s %s %.2f %s\n", e.date, e.category, e.amount, e.note);
    fclose(fp);

    printf("? Expense added successfully!\n");
}

void viewExpenses() {
    FILE *fp = fopen("expenses.txt", "r");
    if (fp == NULL) {
        printf("No expense records found.\n");
        return;
    }

    Expense e;
    printf("\n--- Expense Records ---\n");
    printf("%-12s %-15s %-10s %-20s\n", "Date", "Category", "Amount", "Note");
    printf("-------------------------------------------------------------\n");

    while (fscanf(fp, "%s %s %f %[^\n]", e.date, e.category, &e.amount, e.note) != EOF) {
        printf("%-12s %-15s %-10.2f %-20s\n", e.date, e.category, e.amount, e.note);
    }

    fclose(fp);
}

void summaryByCategory() {
    FILE *fp = fopen("expenses.txt", "r");
    if (fp == NULL) {
        printf("No expense records found.\n");
        return;
    }

    Expense e;
    float food = 0, travel = 0, bills = 0, other = 0;

    while (fscanf(fp, "%s %s %f %[^\n]", e.date, e.category, &e.amount, e.note) != EOF) {
        if (strcmp(e.category, "Food") == 0)
            food += e.amount;
        else if (strcmp(e.category, "Travel") == 0)
            travel += e.amount;
        else if (strcmp(e.category, "Bills") == 0)
            bills += e.amount;
        else
            other += e.amount;
    }

    fclose(fp);

    printf("\n--- Category-wise Summary ---\n");
    printf("Food     : %.2f\n", food);
    printf("Travel   : %.2f\n", travel);
    printf("Bills    : %.2f\n", bills);
    printf("Other    : %.2f\n", other);
    printf("Total    : %.2f\n", food + travel + bills + other);
}

void menu() {
    printf("\n=== EXPENSE TRACKER ===\n");
    printf("1. Add Expense\n");
    printf("2. View Expenses\n");
    printf("3. Summary by Category\n");
    printf("4. Exit\n");
    printf("Enter your choice: ");
}

int main() {
    int choice;
    do {
        menu();
        scanf("%d", &choice);
        switch (choice) {
            case 1: addExpense(); break;
            case 2: viewExpenses(); break;
            case 3: summaryByCategory(); break;
            case 4: printf("Exiting...\n"); break;
            default: printf("Invalid choice. Try again.\n");
        }
    } while (choice != 4);

    return 0;
}

