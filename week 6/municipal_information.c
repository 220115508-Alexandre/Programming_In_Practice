#include <stdio.h>
#include <string.h>

#define MAX_SALARIES   50
#define MAX_BUDGETS    10
#define MAX_REGS       20
#define REG_LEN        20


void bubbleSort(float arr[], int n)
{
    int i, j;
    float temp;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp      = arr[j];
                arr[j]    = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main(void)
{
    float salaries[MAX_SALARIES];
    float budgets[MAX_BUDGETS];
    char  registrations[MAX_REGS][REG_LEN];

    int   numSalaries = 0;
    int   numBudgets  = 0;
    int   numRegs     = 0;
    int   choice;
    int   i;
    float searchVal, total, average, highest, lowest;
    char  searchReg[REG_LEN];
    int   found;

    printf("============================================\n");
    printf(" MUNICIPAL INFORMATION MANAGEMENT SYSTEM\n");
    printf("============================================\n");

    do {
        printf("\n1. Capture Employee Salaries\n");
        printf("2. Display / Analyse Salaries\n");
        printf("3. Capture Department Budgets\n");
        printf("4. Analyse & Sort Budgets\n");
        printf("5. Capture Vehicle Registrations\n");
        printf("6. Display / Search Registrations\n");
        printf("7. Full Salary Report (Integrated Challenge)\n");
        printf("8. Exit\n");
        printf("Enter choice: ");
        if (scanf("%d", &choice) != 1) {
            int c;
            while ((c = getchar()) != '\n' && c != EOF)
                ;
            choice = -1;
        }

        switch (choice) {

        // Employee salaries
        case 1:
            printf("How many salaries to capture (1-%d)? ", MAX_SALARIES);
            scanf("%d", &numSalaries);
            if (numSalaries < 1) numSalaries = 1;
            if (numSalaries > MAX_SALARIES) numSalaries = MAX_SALARIES;

            for (i = 0; i < numSalaries; i++) {
                printf("Salary for employee %d: ", i + 1);
                scanf("%f", &salaries[i]);
            }
            printf("%d salaries stored.\n", numSalaries);
            break;

        case 2:
            if (numSalaries == 0) {
                printf("No salaries captured yet.\n");
                break;
            }
            total = 0.0f;
            highest = salaries[0];
            lowest  = salaries[0];
            printf("\n--- Employee Salaries ---\n");
            for (i = 0; i < numSalaries; i++) {
                printf("%2d: %.2f\n", i + 1, salaries[i]);
                total += salaries[i];
                if (salaries[i] > highest) highest = salaries[i];
                if (salaries[i] < lowest)  lowest  = salaries[i];
            }
            average = total / (float)numSalaries;
            printf("Total   : %.2f\n", total);
            printf("Average : %.2f\n", average);
            printf("Highest : %.2f\n", highest);
            printf("Lowest  : %.2f\n", lowest);

            printf("Enter salary to search for: ");
            scanf("%f", &searchVal);
            found = 0;
            for (i = 0; i < numSalaries; i++) {
                if (salaries[i] == searchVal) {
                    printf("Found at position %d\n", i);
                    found = 1;
                    break;
                }
            }
            if (!found)
                printf("Salary not found.\n");
            break;

        // B. Department budgets 
        case 3:
            printf("How many department budgets (1-%d)? ", MAX_BUDGETS);
            scanf("%d", &numBudgets);
            if (numBudgets < 1) numBudgets = 1;
            if (numBudgets > MAX_BUDGETS) numBudgets = MAX_BUDGETS;

            for (i = 0; i < numBudgets; i++) {
                printf("Budget for department %d: ", i + 1);
                scanf("%f", &budgets[i]);
            }
            printf("%d budgets stored.\n", numBudgets);
            break;

        case 4:
            if (numBudgets == 0) {
                printf("No budgets captured yet.\n");
                break;
            }
            total = 0.0f;
            printf("\n--- Department Budgets (unsorted) ---\n");
            for (i = 0; i < numBudgets; i++) {
                printf("%2d: %.2f\n", i + 1, budgets[i]);
                total += budgets[i];
            }
            average = total / (float)numBudgets;
            printf("Total budget   : %.2f\n", total);
            printf("Average budget : %.2f\n", average);

            bubbleSort(budgets, numBudgets);
            printf("\n--- Budgets sorted (lowest to highest) ---\n");
            for (i = 0; i < numBudgets; i++)
                printf("%2d: %.2f\n", i + 1, budgets[i]);
            break;

        // Vehicle registrations 
        case 5:
            printf("How many registration numbers (1-%d)? ", MAX_REGS);
            scanf("%d", &numRegs);
            if (numRegs < 1) numRegs = 1;
            if (numRegs > MAX_REGS) numRegs = MAX_REGS;

            for (i = 0; i < numRegs; i++) {
                printf("Registration %d: ", i + 1);
                scanf("%19s", registrations[i]);
            }
            printf("%d registrations stored.\n", numRegs);
            break;

        case 6:
            if (numRegs == 0) {
                printf("No registrations captured yet.\n");
                break;
            }
            printf("\n--- Vehicle Registrations ---\n");
            for (i = 0; i < numRegs; i++)
                printf("%2d: %s\n", i + 1, registrations[i]);

            printf("Enter registration to search: ");
            scanf("%19s", searchReg);
            found = 0;
            for (i = 0; i < numRegs; i++) {
                if (strcmp(registrations[i], searchReg) == 0) {
                    printf("Found at position %d\n", i);
                    found = 1;
                    break;
                }
            }
            if (!found)
                printf("Registration not found.\n");
            break;


        //  Integrated challenge 
        case 7:
            if (numSalaries == 0) {
                printf("Capture salaries first (option 1).\n");
                break;
            }
            printf("\n=== FULL EMPLOYEE SALARY REPORT ===\n");
            total = 0.0f;
            highest = salaries[0];
            lowest  = salaries[0];
            for (i = 0; i < numSalaries; i++) {
                printf("%2d: %.2f\n", i + 1, salaries[i]);
                total += salaries[i];
                if (salaries[i] > highest) highest = salaries[i];
                if (salaries[i] < lowest)  lowest  = salaries[i];
            }
            printf("Total expenditure : %.2f\n", total);
            printf("Average salary    : %.2f\n", total / (float)numSalaries);
            printf("Highest salary    : %.2f\n", highest);
            printf("Lowest salary     : %.2f\n", lowest);

            
            {
                float sorted[MAX_SALARIES];
                for (i = 0; i < numSalaries; i++)
                    sorted[i] = salaries[i];
                bubbleSort(sorted, numSalaries);
                printf("\nSorted (lowest to highest):\n");
                for (i = 0; i < numSalaries; i++)
                    printf("%2d: %.2f\n", i + 1, sorted[i]);
            }
            break;

        case 8:
            printf("Goodbye.\n");
            break;

        default:
            printf("Invalid choice.\n");
        }
    } while (choice != 8);

    return 0;
}