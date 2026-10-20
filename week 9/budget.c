#include <stdio.h>
#include <string.h>
#include "budget.h"
#include "utilities.h"

static char   deptNames[MAX_BUDGETS][40];
static double deptRevenues[MAX_BUDGETS];
static double deptExpenses[MAX_BUDGETS];
static int    budgetCount = 0;

void addBudget(void)
{
    if (budgetCount >= MAX_BUDGETS) {
        printf("Budget list full.\n");
        return;
    }
    printf("Department name: ");
    fgets(deptNames[budgetCount], 40, stdin);
    deptNames[budgetCount][strcspn(deptNames[budgetCount], "\n")] = '\0';
    deptRevenues[budgetCount]  = readFloat("Revenue: ");
    deptExpenses[budgetCount]  = readFloat("Expenses: ");
    budgetCount++;
    printf("Budget entry added.\n");
}

void listBudgets(void)
{
    int i;
    if (budgetCount == 0) {
        printf("No budgets recorded.\n");
        return;
    }
    printf("\n%-20s %12s %12s %12s\n",
           "Department", "Revenue", "Expenses", "Balance");
    
    for (i = 0; i < budgetCount; i++) {
        printf("%-20s %12.2f %12.2f %12.2f\n",
               deptNames[i],
               deptRevenues[i],
               deptExpenses[i],
               deptRevenues[i] - deptExpenses[i]);
    }
}

double calculateBudgetBalance(void)
{
    double rev = 0.0, exp = 0.0;
    int i;
    for (i = 0; i < budgetCount; i++) {
        rev += deptRevenues[i];
        exp += deptExpenses[i];
    }
    return rev - exp;
}

void budgetMenu(void)
{
    int choice;
    double bal;
    do {
        printf("\n--- Budget Management ---\n");
        printf("1. Add Budget Entry\n");
        printf("2. List Budgets\n");
        printf("3. Overall Balance\n");
        printf("4. Back\n");
        choice = readInt("Choice: ");

        switch (choice) {
        case 1: addBudget(); break;
        case 2: listBudgets(); break;
        case 3:
            bal = calculateBudgetBalance();
            printf("Overall balance: %.2f  ", bal);
            if (bal > 0)      printf("(SURPLUS)\n");
            else if (bal < 0) printf("(DEFICIT)\n");
            else              printf("(BALANCED)\n");
            break;
        case 4: break;
        default: printf("Invalid choice.\n");
        }
    } while (choice != 4);
}
