#include <stdio.h>

int main(void)
{
    char  tenderRef[30];
    char  companyName[50];
    float priceScore;      
    float qualityScore;    
    float experienceScore; 
    float totalScore;
    int   compliant;       
    int   category;       
    char  grade;

    printf("========================================\n");
    printf(" MUNICIPAL TENDER EVALUATION SYSTEM\n");
    printf("========================================\n\n");

    
    printf("Enter Tender Reference: ");
    scanf("%29s", tenderRef);

    printf("Enter Company Name: ");
    scanf("%49s", companyName);

    printf("Is the tender fully compliant? (1 = Yes, 0 = No): ");
    scanf("%d", &compliant);

    
    if (compliant != 1) {
        printf("\n*** RESULT: DISQUALIFIED ***\n");
        printf("Reason: Tender is not compliant with municipal requirements.\n");
        printf("No further evaluation will be performed.\n");
        return 0;
    }

    printf("Enter Price Score (0-40): ");
    scanf("%f", &priceScore);

    printf("Enter Quality Score (0-30): ");
    scanf("%f", &qualityScore);

    printf("Enter Experience Score (0-30): ");
    scanf("%f", &experienceScore);

   
    if (priceScore < 0 || priceScore > 40) {
        printf("Invalid price score. Clamping to valid range.\n");
        if (priceScore < 0)
            priceScore = 0;
        else
            priceScore = 40;
    }

    if (qualityScore < 0 || qualityScore > 30) {
        printf("Invalid quality score. Clamping to valid range.\n");
        if (qualityScore < 0)
            qualityScore = 0;
        else
            qualityScore = 30;
    }

    if (experienceScore < 0 || experienceScore > 30) {
        printf("Invalid experience score. Clamping to valid range.\n");
        if (experienceScore < 0)
            experienceScore = 0;
        else
            experienceScore = 30;
    }

    totalScore = priceScore + qualityScore + experienceScore;

   
    if (totalScore >= 90)
        grade = 'A';
    else if (totalScore >= 75)
        grade = 'B';
    else if (totalScore >= 60)
        grade = 'C';
    else if (totalScore >= 50)
        grade = 'D';
    else
        grade = 'F';

    
    printf("\n---------- EVALUATION REPORT ----------\n");
    printf("Tender Ref   : %s\n", tenderRef);
    printf("Company      : %s\n", companyName);
    printf("Compliance   : PASSED\n");
    printf("Price Score  : %.1f / 40\n", priceScore);
    printf("Quality Score: %.1f / 30\n", qualityScore);
    printf("Experience   : %.1f / 30\n", experienceScore);
    printf("---------------------------------------\n");
    printf("Total Score  : %.1f / 100\n", totalScore);
    printf("Grade        : %c\n", grade);

    if (totalScore >= 75) {
        printf("Recommendation: AWARD TENDER\n");
        if (totalScore >= 90)
            printf("Note: Outstanding bid – preferred supplier status.\n");
        else
            printf("Note: Strong bid – proceed to contract negotiation.\n");
    } else if (totalScore >= 50) {
        printf("Recommendation: CONSIDER WITH CONDITIONS\n");
        printf("Note: Request clarification or negotiation on weak areas.\n");
    } else {
        printf("Recommendation: REJECT TENDER\n");
        printf("Note: Score below acceptable municipal threshold.\n");
    }

    
    printf("\n--- Category (switch) ---\n");
    switch (grade) {
    case 'A':
        printf("Category: Excellent\n");
        break;
    case 'B':
        printf("Category: Good\n");
        break;
    case 'C':
        printf("Category: Satisfactory\n");
        break;
    case 'D':
        printf("Category: Marginal\n");
        break;
    case 'F':
        printf("Category: Unsatisfactory\n");
        break;
    default:
        printf("Category: Unknown\n");
    }

    
    printf("\nSelect follow-up action:\n");
    printf("1. Print full report\n");
    printf("2. Flag for committee review\n");
    printf("3. Archive only\n");
    printf("Enter choice (1-3): ");
    scanf("%d", &category);

    switch (category) {
    case 1:
        printf("Action: Full report sent to printer/queue.\n");
        break;
    case 2:
        printf("Action: Tender flagged for municipal committee review.\n");
        break;
    case 3:
        printf("Action: Evaluation archived. No further action.\n");
        break;
    default:
        printf("Action: Invalid choice – no action taken.\n");
    }

    return 0;
}