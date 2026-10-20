#include <stdio.h>
#include <string.h>
#include "employees.h"
#include "utilities.h"

static Employee employees[MAX_EMPLOYEES];
static int empCount = 0;

void addEmployee(void)
{
    if (empCount >= MAX_EMPLOYEES) {
        printf("Employee list is full.\n");
        return;
    }
    employees[empCount].id = readInt("Enter employee ID: ");
    readString("Enter employee name: ", employees[empCount].name, 50);
    employees[empCount].salary = readFloat("Enter salary: ");
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
               employees[i].id, employees[i].name, employees[i].salary);
    }
}

int searchEmployee(int id)
{
    int i;
    for (i = 0; i < empCount; i++) {
        if (employees[i].id == id)
            return i;
    }
    return -1;
}

double calculatePayrollTotal(void)
{
    double total = 0.0;
    int i;
    for (i = 0; i < empCount; i++)
        total += employees[i].salary;
    return total;
}

// Text file persistence 
int saveEmployeesText(void)
{
    FILE *fp = fopen("data/employees.txt", "w");
    int i;
    if (fp == NULL) {
        perror("data/employees.txt");
        return 0;
    }
    for (i = 0; i < empCount; i++) {
        fprintf(fp, "%d|%s|%.2f\n",
                employees[i].id, employees[i].name, employees[i].salary);
    }
    fclose(fp);
    printf("Saved %d employee(s) to data/employees.txt\n", empCount);
    return empCount;
}

int loadEmployeesText(void)
{
    FILE *fp = fopen("data/employees.txt", "r");
    int id;
    char name[50];
    double salary;
    int count = 0;

    if (fp == NULL) {
        perror("data/employees.txt");
        printf("(File may not exist yet – that is OK on first run.)\n");
        return 0;
    }

    empCount = 0;
    while (empCount < MAX_EMPLOYEES &&
           fscanf(fp, "%d|%49[^|]|%lf\n", &id, name, &salary) == 3) {
        employees[empCount].id = id;
        strncpy(employees[empCount].name, name, 49);
        employees[empCount].name[49] = '\0';
        employees[empCount].salary = salary;
        empCount++;
        count++;
    }
    fclose(fp);
    printf("Loaded %d employee(s) from data/employees.txt\n", count);
    return count;
}

//Binary file persistence
int saveEmployeesBinary(void)
{
    FILE *fp = fopen("data/employees.dat", "wb");
    size_t written;
    if (fp == NULL) {
        perror("data/employees.dat");
        return 0;
    }
    written = fwrite(employees, sizeof(Employee), (size_t)empCount, fp);
    fclose(fp);
    printf("Saved %zu employee record(s) to data/employees.dat (binary)\n", written);
    return (int)written;
}

int loadEmployeesBinary(void)
{
    FILE *fp = fopen("data/employees.dat", "rb");
    size_t n;
    if (fp == NULL) {
        perror("data/employees.dat");
        printf("(File may not exist yet – that is OK on first run.)\n");
        return 0;
    }
    n = fread(employees, sizeof(Employee), MAX_EMPLOYEES, fp);
    fclose(fp);
    empCount = (int)n;
    printf("Loaded %d employee record(s) from data/employees.dat (binary)\n", empCount);
    return empCount;
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
        printf("5. Save (text)\n");
        printf("6. Load (text)\n");
        printf("7. Save (binary)\n");
        printf("8. Load (binary)\n");
        printf("9. Back\n");
        choice = readInt("Choice: ");

        switch (choice) {
        case 1: addEmployee(); break;
        case 2: listEmployees(); break;
        case 3:
            id = readInt("Enter ID to search: ");
            pos = searchEmployee(id);
            if (pos >= 0)
                printf("Found: %s, salary %.2f\n",
                       employees[pos].name, employees[pos].salary);
            else
                printf("Employee not found.\n");
            break;
        case 4:
            printf("Total payroll: %.2f\n", calculatePayrollTotal());
            break;
        case 5: saveEmployeesText();   break;
        case 6: loadEmployeesText();   break;
        case 7: saveEmployeesBinary(); break;
        case 8: loadEmployeesBinary(); break;
        case 9: break;
        default: printf("Invalid choice.\n");
        }
    } while (choice != 9);
}
