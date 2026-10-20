#include <stdio.h>
#include <string.h>
#include "suppliers.h"
#include "utilities.h"

static Supplier suppliers[MAX_SUPPLIERS];
static int supCount = 0;

void addSupplier(void)
{
    if (supCount >= MAX_SUPPLIERS) {
        printf("Supplier list full.\n");
        return;
    }
    readString("Supplier name: ", suppliers[supCount].name, 100);
    readString("Email: ", suppliers[supCount].email, 100);
    readString("Phone: ", suppliers[supCount].phone, 30);
    readString("Town: ", suppliers[supCount].town, 50);
    supCount++;
    printf("Supplier added.\n");
}

void listSuppliers(void)
{
    int i;
    if (supCount == 0) {
        printf("No suppliers recorded.\n");
        return;
    }
    for (i = 0; i < supCount; i++) {
        printf("\n%d. %s\n   Email: %s\n   Phone: %s\n   Town : %s\n",
               i + 1,
               suppliers[i].name,
               suppliers[i].email,
               suppliers[i].phone,
               suppliers[i].town);
    }
}

void searchSupplier(void)
{
    char name[100];
    int i, found = 0;
    readString("Enter name to search: ", name, 100);
    for (i = 0; i < supCount; i++) {
        if (strcmp(suppliers[i].name, name) == 0) {
            printf("Found: %s | %s | %s | %s\n",
                   suppliers[i].name, suppliers[i].email,
                   suppliers[i].phone, suppliers[i].town);
            found = 1;
            break;
        }
    }
    if (!found)
        printf("Supplier not found.\n");
}

int saveSuppliersText(void)
{
    FILE *fp = fopen("data/suppliers.txt", "w");
    int i;
    if (fp == NULL) {
        perror("data/suppliers.txt");
        return 0;
    }
    for (i = 0; i < supCount; i++) {
        fprintf(fp, "%s|%s|%s|%s\n",
                suppliers[i].name, suppliers[i].email,
                suppliers[i].phone, suppliers[i].town);
    }
    fclose(fp);
    printf("Saved %d supplier(s) to data/suppliers.txt\n", supCount);
    return supCount;
}

int loadSuppliersText(void)
{
    FILE *fp = fopen("data/suppliers.txt", "r");
    char name[100], email[100], phone[30], town[50];
    int count = 0;

    if (fp == NULL) {
        perror("data/suppliers.txt");
        printf("(File may not exist yet – that is OK on first run.)\n");
        return 0;
    }

    supCount = 0;
    while (supCount < MAX_SUPPLIERS &&
           fscanf(fp, "%99[^|]|%99[^|]|%29[^|]|%49[^\n]\n",
                  name, email, phone, town) == 4) {
        strncpy(suppliers[supCount].name,  name,  99);
        strncpy(suppliers[supCount].email, email, 99);
        strncpy(suppliers[supCount].phone, phone, 29);
        strncpy(suppliers[supCount].town,  town,  49);
        suppliers[supCount].name[99]  = '\0';
        suppliers[supCount].email[99] = '\0';
        suppliers[supCount].phone[29] = '\0';
        suppliers[supCount].town[49]  = '\0';
        supCount++;
        count++;
    }
    fclose(fp);
    printf("Loaded %d supplier(s) from data/suppliers.txt\n", count);
    return count;
}

void supplierMenu(void)
{
    int choice;
    do {
        printf("\n--- Supplier Management ---\n");
        printf("1. Add Supplier\n");
        printf("2. List Suppliers\n");
        printf("3. Search Supplier\n");
        printf("4. Save (text)\n");
        printf("5. Load (text)\n");
        printf("6. Back\n");
        choice = readInt("Choice: ");

        switch (choice) {
        case 1: addSupplier();      break;
        case 2: listSuppliers();    break;
        case 3: searchSupplier();   break;
        case 4: saveSuppliersText(); break;
        case 5: loadSuppliersText(); break;
        case 6: break;
        default: printf("Invalid choice.\n");
        }
    } while (choice != 6);
}
