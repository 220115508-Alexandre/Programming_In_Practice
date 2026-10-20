#include <stdio.h>

int main(void)
{
    float basic, housing, transport, overtimeHours, overtimeRate;
    float overtimePay, gross, tax, net;
    float taxRate;
    int   employeeId;
    char  employeeName[50];

    printf("========================================\n");
    printf(" MUNICIPAL EMPLOYEE SALARY CALCULATOR\n");
    printf("========================================\n\n");

   
    printf("Enter Employee ID: ");
    scanf("%d", &employeeId);

    printf("Enter Employee Name: ");
    scanf("%49s", employeeName);

    printf("Enter Basic Salary: ");
    scanf("%f", &basic);

    printf("Enter Housing Allowance: ");
    scanf("%f", &housing);

    printf("Enter Transport Allowance: ");
    scanf("%f", &transport);

    printf("Enter Overtime Hours: ");
    scanf("%f", &overtimeHours);

    printf("Enter Overtime Rate per Hour: ");
    scanf("%f", &overtimeRate);

   
    overtimePay = overtimeHours * overtimeRate;         
    gross       = basic + housing + transport + overtimePay; 


    if (gross < 10000.0f)
        taxRate = 0.05f;
    else if (gross < 20000.0f)
        taxRate = 0.10f;
    else if (gross < 35000.0f)
        taxRate = 0.15f;
    else
        taxRate = 0.20f;

    tax = gross * taxRate;          
    net = gross - tax;              

    
    printf("\n---------- SALARY SLIP ----------\n");
    printf("Employee ID   : %d\n", employeeId);
    printf("Employee Name : %s\n", employeeName);
    printf("---------------------------------\n");

    printf("Basic Salary       : %10.2f\n", basic);
    printf("Housing Allowance  : %10.2f\n", housing);
    printf("Transport Allowance: %10.2f\n", transport);
    printf("Overtime Pay       : %10.2f\n", overtimePay);

    printf("Gross Salary       : %10.2f\n", gross);
    printf("Tax Rate           : %9.0f%%\n", taxRate * 100.0f);
    printf("Tax Deducted       : %10.2f\n", tax);

    printf("Net Salary         : %10.2f\n", net);
    printf("---------------------------------\n");
}