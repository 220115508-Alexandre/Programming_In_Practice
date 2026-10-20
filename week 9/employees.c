#include <stdio.h>
#include <string.h>
#include "employees.h"
#include "utilities.h"

// Simple parallel arrays for demonstration
static int    empIds[MAX_EMPLOYEES];
static char   empNames[MAX_EMPLOYEES][50];
static double empSalaries[MAX_EMPLOYEES];
static int    empCount = 0;

void addEmployee(void)
{
    if (empCount >= MAX_EMPLOYEES) {
        printf("Employee list is full.\n");
        return;
    }
    empIds[empCount] = readInt("Enter employee ID: ");
    printf("Enter employee name: ");
    fgets(empNames[empCount], 50, stdin);
    empNames[empCount][strcspn(empNames[empCount], "\n")] = '\0';
    empSalaries[empCount] = readFloat("Enter salary: ");
    empCount++;
    printf("Employee added.\n");
}

void listEmployees(void)
{
    int i;
    if (empCount == 0) {
        printf("No employees recorded.\n");
        return;
    }
    printf("\n%-6s %-20s %12s\n", "ID", "Name", "Salary");
    printf("----------------------------------------\n");
    for (i = 0; i < empCount; i++) {
        printf("%-6d %-20s %12.2f\n",
               empIds[i], empNames[i], empSalaries[i]);
    }
}

int searchEmployee(int id)
{
    int i;
    for (i = 0; i < empCount; i++) {
        if (empIds[i] == id)
            return i;
    }
    return -1;
}

double calculatePayrollTotal(void)
{
    double total = 0.0;
    int i;
    for (i = 0; i < empCount; i++)
        total += empSalaries[i];
    return total;
}

void employeeMenu(void)
{
    int choice, id, pos;
    do {
        printf("\n--- Employee Management ---\n");
        printf("1. Add Employee\n");
        printf("2. List Employees\n");
        printf("3. Search Employee\n");
        printf("4. Payroll Total\n");
        printf("5. Back\n");
        choice = readInt("Choice: ");

        switch (choice) {
        case 1: addEmployee(); break;
        case 2: listEmployees(); break;
        case 3:
            id = readInt("Enter ID to search: ");
            pos = searchEmployee(id);
            if (pos >= 0)
                printf("Found: %s, salary %.2f\n",
                       empNames[pos], empSalaries[pos]);
            else
                printf("Employee not found.\n");
            break;
        case 4:
            printf("Total payroll: %.2f\n", calculatePayrollTotal());
            break;
        case 5: break;
        default: printf("Invalid choice.\n");
        }
    } while (choice != 5);
}
