
#include <stdio.h>
#include "employees.h"
#include "budget.h"
#include "utilities.h"
#include "reports.h"

void displayMainMenu(void)
{
    printf("\n============================================\n");
    printf(" MUNICIPAL FINANCIAL MANAGEMENT SYSTEM\n");
    printf("============================================\n");
    printf("1. Employee Management\n");
    printf("2. Budget Management\n");
    printf("3. Reports\n");
    printf("4. Exit\n");
    printf("Enter choice: ");
}

int main(void)
{
    int choice;

    printf("Municipal Financial Management System – Week 9 (Multi-file)\n");

    do {
        displayMainMenu();
        choice = readInt("");

        switch (choice) {
        case 1:
            employeeMenu();
            break;
        case 2:
            budgetMenu();
            break;
        case 3:
            fullSummaryReport();
            break;
        case 4:
            printf("Goodbye.\n");
            break;
        default:
            printf("Invalid choice.\n");
        }
    } while (choice != 4);

    return 0;
}
