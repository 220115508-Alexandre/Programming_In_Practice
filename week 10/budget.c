#include <stdio.h>
#include <string.h>
#include "budget.h"
#include "utilities.h"

static BudgetEntry budgets[MAX_BUDGETS];
static int budgetCount = 0;

void addBudget(void)
{
    if (budgetCount >= MAX_BUDGETS) {
        printf("Budget list full.\n");
        return;
    }
    readString("Department name: ", budgets[budgetCount].department, 40);
    budgets[budgetCount].revenue  = readFloat("Revenue: ");
    budgets[budgetCount].expenses = readFloat("Expenses: ");
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
    printf("------------------------------------------------------------\n");
    for (i = 0; i < budgetCount; i++) {
        printf("%-20s %12.2f %12.2f %12.2f\n",
               budgets[i].department,
               budgets[i].revenue,
               budgets[i].expenses,
               budgets[i].revenue - budgets[i].expenses);
    }
}

double calculateBudgetBalance(void)
{
    double rev = 0.0, exp = 0.0;
    int i;
    for (i = 0; i < budgetCount; i++) {
        rev += budgets[i].revenue;
        exp += budgets[i].expenses;
    }
    return rev - exp;
}

int saveBudgetsText(void)
{
    FILE *fp = fopen("data/budgets.txt", "w");
    int i;
    if (fp == NULL) {
        perror("data/budgets.txt");
        return 0;
    }
    for (i = 0; i < budgetCount; i++) {
        fprintf(fp, "%s|%.2f|%.2f\n",
                budgets[i].department,
                budgets[i].revenue,
                budgets[i].expenses);
    }
    fclose(fp);
    printf("Saved %d budget entry(ies) to data/budgets.txt\n", budgetCount);
    return budgetCount;
}

int loadBudgetsText(void)
{
    FILE *fp = fopen("data/budgets.txt", "r");
    char dept[40];
    double rev, exp;
    int count = 0;

    if (fp == NULL) {
        perror("data/budgets.txt");
        printf("(File may not exist yet – that is OK on first run.)\n");
        return 0;
    }

    budgetCount = 0;
    while (budgetCount < MAX_BUDGETS &&
           fscanf(fp, "%39[^|]|%lf|%lf\n", dept, &rev, &exp) == 3) {
        strncpy(budgets[budgetCount].department, dept, 39);
        budgets[budgetCount].department[39] = '\0';
        budgets[budgetCount].revenue  = rev;
        budgets[budgetCount].expenses = exp;
        budgetCount++;
        count++;
    }
    fclose(fp);
    printf("Loaded %d budget entry(ies) from data/budgets.txt\n", count);
    return count;
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
        printf("4. Save (text)\n");
        printf("5. Load (text)\n");
        printf("6. Back\n");
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
        case 4: saveBudgetsText(); break;
        case 5: loadBudgetsText(); break;
        case 6: break;
        default: printf("Invalid choice.\n");
        }
    } while (choice != 6);
}
