#include <stdio.h>
#include "employees.h"
#include "suppliers.h"
#include "budget.h"
#include "utilities.h"
#include "reports.h"

void displayMainMenu(void)
{
    printf("\n============================================\n");
    printf(" MUNICIPAL FINANCIAL MANAGEMENT SYSTEM\n");
    printf("============================================\n");
    printf("1. Employee Management\n");
    printf("2. Supplier Management\n");
    printf("3. Budget Management\n");
    printf("4. Reports\n");
    printf("5. Save All (text)\n");
    printf("6. Load All (text)\n");
    printf("7. Exit\n");
    printf("Enter choice: ");
}

int main(void)
{
    int choice;

    printf("Municipal Financial Management System – Week 10\n");
    printf("Data directory: data/\n");

    do {
        displayMainMenu();
        choice = readInt("");

        switch (choice) {
        case 1: employeeMenu();  break;
        case 2: supplierMenu();  break;
        case 3: budgetMenu();    break;
        case 4: fullSummaryReport(); break;
        case 5:
            saveEmployeesText();
            saveSuppliersText();
            saveBudgetsText();
            break;
        case 6:
            loadEmployeesText();
            loadSuppliersText();
            loadBudgetsText();
            break;
        case 7:
            printf("Goodbye.\n");
            break;
        default:
            printf("Invalid choice.\n");
        }
    } while (choice != 7);

    return 0;
}
