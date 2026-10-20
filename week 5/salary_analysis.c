#include <stdio.h>

#define NUM_EMPLOYEES 50   

int main(void)
{
    float salary;
    float total   = 0.0f;
    float highest = 0.0f;
    float lowest  = 0.0f;
    float average;
    int   i;

    printf("========================================\n");
    printf(" MUNICIPAL EMPLOYEE SALARY ANALYSIS\n");
    printf("========================================\n\n");

    for (i = 1; i <= NUM_EMPLOYEES; i++) {
        printf("Enter salary for employee %d: ", i);
        if (scanf("%f", &salary) != 1) {
            printf("Invalid input. Skipping this employee.\n");
            
            int c;
            while ((c = getchar()) != '\n' && c != EOF)
                ;
            continue;   
        }

        
        if (salary == 0.0f) {
            printf("Data capture terminated early by user.\n");
            break;
        }

       
        if (salary < 0.0f) {
            printf("Negative salary ignored.\n");
            continue;
        }

        total += salary;

        
        if (i == 1 || total == salary) {   
            highest = salary;
            lowest  = salary;
        } else {
            if (salary > highest)
                highest = salary;
            if (salary < lowest)
                lowest = salary;
        }
    }


    if (i > 1) {

        int count = (salary == 0.0f) ? (i - 1) : (i - 1);
        if (count == 0)
            count = 1; 
        average = total / (float)count;

        printf("\n--- Salary Report ---\n");
        printf("Employees processed : %d\n", count);
        printf("Total salary        : %.2f\n", total);
        printf("Average salary      : %.2f\n", average);
        printf("Highest salary      : %.2f\n", highest);
        printf("Lowest salary       : %.2f\n", lowest);
    } else {
        printf("\nNo valid salaries were entered.\n");
    }

    return 0;
}