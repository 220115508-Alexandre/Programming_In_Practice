#include <stdio.h>

int main() {
    char municipalityName[50];
    char mayorName[50];
    int population;

    printf("--- Municipal Financial Management System ---\n\n");

    printf("Welcome to Windhoek Municipality\n\n");

    printf("Enter Municipality Name: ");
    scanf("%s", municipalityName);

    printf("Enter Mayor's Name: ");
    scanf("%s", mayorName);

    printf("Enter Population: ");
    scanf("%d", &population);

    printf("\n--- Municipal Report ---\n");
    printf("Municipality Name: %s\n", municipalityName);
    printf("Mayor's Name: %s\n", mayorName);
    printf("Population: %d\n", population);

    return 0;
}