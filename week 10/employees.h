#ifndef EMPLOYEES_H
#define EMPLOYEES_H

#define MAX_EMPLOYEES 100

typedef struct {
    int    id;
    char   name[50];
    double salary;
} Employee;

void addEmployee(void);
void listEmployees(void);
int  searchEmployee(int id);
double calculatePayrollTotal(void);
void employeeMenu(void);

// Persistence 
int  saveEmployeesText(void);
int  loadEmployeesText(void);
int  saveEmployeesBinary(void);
int  loadEmployeesBinary(void);

#endif
