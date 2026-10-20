#include <stdio.h>
#include "reports.h"
#include "employees.h"
#include "budget.h"

void employeeReport(void)
{
    printf("\n===== EMPLOYEE REPORT =====\n");
    listEmployees();
    printf("Payroll total: %.2f\n", calculatePayrollTotal());
}

void budgetReport(void)
{
    printf("\n===== BUDGET REPORT =====\n");
    listBudgets();
    printf("Overall balance: %.2f\n", calculateBudgetBalance());
}

void fullSummaryReport(void)
{
    printf("\n***** MFMS FULL SUMMARY *****\n");
    employeeReport();
    budgetReport();
}
