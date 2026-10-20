#include <stdio.h>

int main(void) {
    double revenue, expenses, balance;
    int departments;
    double payroll, procurement, assets;

    printf("MUNICIPAL BUDGET CALCULATOR\n");
    printf("============================\n\n");

    printf("Enter Total Revenue: ");
    scanf("%lf", &revenue);

    printf("Enter Total Expenses: ");
    scanf("%lf", &expenses);

    printf("Enter Number of Departments: ");
    scanf("%d", &departments);

    printf("Enter Total Payroll: ");
    scanf("%lf", &payroll);

    printf("Enter Total Procurement Costs: ");
    scanf("%lf", &procurement);

    printf("Enter Total Assets: ");
    scanf("%lf", &assets);

    balance = revenue - expenses;

    if (balance > 0) {
    printf("Balance: %.2f\n", balance);
    }
    else if (balance < 0) {
    printf("Balance: %.2f\n", -balance);
    }
    else {
    printf("The budget is balanced.\n");
    }

    printf("\nMunicipal Financial Summary\n");
    printf("Departments: %d\n", departments);
    printf("Payroll: %.2f\n", payroll);
    printf("Procurement: %.2f\n", procurement);
    printf("Assets: %.2f\n", assets);

    return 0;
}