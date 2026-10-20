#include <stdio.h>
#include "utilities.h"

void clearInputBuffer(void)
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
        ;
}

void pauseScreen(void)
{
    printf("\nPress Enter to continue...");
    clearInputBuffer();
}

int readInt(const char *prompt)
{
    int value;
    printf("%s", prompt);
    while (scanf("%d", &value) != 1) {
        clearInputBuffer();
        printf("Invalid integer. Try again: ");
    }
    clearInputBuffer();
    return value;
}

float readFloat(const char *prompt)
{
    float value;
    printf("%s", prompt);
    while (scanf("%f", &value) != 1) {
        clearInputBuffer();
        printf("Invalid number. Try again: ");
    }
    clearInputBuffer();
    return value;
}
