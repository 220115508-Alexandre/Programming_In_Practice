#ifndef BUDGET_H
#define BUDGET_H

#define MAX_BUDGETS 50

typedef struct {
    char   department[40];
    double revenue;
    double expenses;
} BudgetEntry;

void addBudget(void);
void listBudgets(void);
double calculateBudgetBalance(void);
void budgetMenu(void);

int  saveBudgetsText(void);
int  loadBudgetsText(void);

#endif
