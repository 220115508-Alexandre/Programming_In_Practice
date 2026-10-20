#include <stdio.h>
#include <string.h>

#define MAX_SUPPLIERS 5
#define NAME_LEN      100
#define EMAIL_LEN     100
#define PHONE_LEN     30
#define TOWN_LEN      50

// Parallel arrays for up to MAX_SUPPLIERS suppliers
char supplierName[MAX_SUPPLIERS][NAME_LEN];
char email[MAX_SUPPLIERS][EMAIL_LEN];
char phone[MAX_SUPPLIERS][PHONE_LEN];
char town[MAX_SUPPLIERS][TOWN_LEN];
int  supplierCount = 0;


void stripNewline(char *s)
{
    s[strcspn(s, "\n")] = '\0';
}

void addSupplier(void)
{
    if (supplierCount >= MAX_SUPPLIERS) {
        printf("Maximum number of suppliers (%d) reached.\n", MAX_SUPPLIERS);
        return;
    }

    printf("Enter supplier name: ");
    fgets(supplierName[supplierCount], NAME_LEN, stdin);
    stripNewline(supplierName[supplierCount]);

    printf("Enter email: ");
    fgets(email[supplierCount], EMAIL_LEN, stdin);
    stripNewline(email[supplierCount]);

    printf("Enter phone: ");
    fgets(phone[supplierCount], PHONE_LEN, stdin);
    stripNewline(phone[supplierCount]);

    printf("Enter town: ");
    fgets(town[supplierCount], TOWN_LEN, stdin);
    stripNewline(town[supplierCount]);

    printf("Supplier added successfully.\n");
    supplierCount++;
}

void displaySuppliers(void)
{
    int i;
    if (supplierCount == 0) {
        printf("No suppliers stored yet.\n");
        return;
    }
    printf("\n--- SUPPLIER DETAILS ---\n");
    for (i = 0; i < supplierCount; i++) {
        printf("\nSupplier %d\n", i + 1);
        printf("Name  : %s\n", supplierName[i]);
        printf("Email : %s\n", email[i]);
        printf("Phone : %s\n", phone[i]);
        printf("Town  : %s\n", town[i]);
        printf("Name length: %zu\n", strlen(supplierName[i]));
    }
}

void searchSupplier(void)
{
    char searchName[NAME_LEN];
    int  i, found = 0;

    if (supplierCount == 0) {
        printf("No suppliers to search.\n");
        return;
    }

    printf("Enter supplier name to search: ");
    fgets(searchName, NAME_LEN, stdin);
    stripNewline(searchName);

    for (i = 0; i < supplierCount; i++) {
        if (strcmp(supplierName[i], searchName) == 0) {
            printf("Supplier found:\n");
            printf("Name  : %s\n", supplierName[i]);
            printf("Email : %s\n", email[i]);
            printf("Phone : %s\n", phone[i]);
            printf("Town  : %s\n", town[i]);
            found = 1;
            break;
        }
    }
    if (!found)
        printf("Supplier not found.\n");
}

void showNameLength(void)
{
    int i;
    if (supplierCount == 0) {
        printf("No suppliers stored.\n");
        return;
    }
    for (i = 0; i < supplierCount; i++) {
        printf("%s -> length %zu\n",
               supplierName[i], strlen(supplierName[i]));
    }
}

// Demonstration of strcpy and strcat on the first supplier
void demoCopyConcat(void)
{
    char backup[NAME_LEN];
    char description[200];

    if (supplierCount == 0) {
        printf("Add at least one supplier first.\n");
        return;
    }

   
    strcpy(backup, supplierName[0]);
    printf("Original : %s\n", supplierName[0]);
    printf("Backup   : %s\n", backup);

    // strcat – build a description sentence
    strcpy(description, supplierName[0]);
    strcat(description, " operates in ");
    strcat(description, town[0]);
    strcat(description, ".");
    printf("Description: %s\n", description);
}

void displayMenu(void)
{
    printf("\n================================\n");
    printf(" MUNICIPAL FINANCIAL MANAGEMENT\n");
    printf("================================\n");
    printf("1. Add Supplier\n");
    printf("2. Display Suppliers\n");
    printf("3. Search Supplier\n");
    printf("4. Show Name Lengths\n");
    printf("5. Demo Copy & Concatenate\n");
    printf("6. Exit\n");
    printf("Enter choice: ");
}

int main(void)
{
    int choice;
    char line[20];

    do {
        displayMenu();
        if (fgets(line, sizeof line, stdin) == NULL)
            break;
        if (sscanf(line, "%d", &choice) != 1)
            choice = -1;

        switch (choice) {
        case 1: addSupplier();      break;
        case 2: displaySuppliers(); break;
        case 3: searchSupplier();   break;
        case 4: showNameLength();   break;
        case 5: demoCopyConcat();   break;
        case 6: printf("Goodbye.\n"); break;
        default: printf("Invalid choice.\n");
        }
    } while (choice != 6);

    return 0;
}
