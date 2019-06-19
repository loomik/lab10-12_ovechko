#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "lab_10.h"
#include "lab_11.h"
#include "lab_12.h"
#include "struct.h"

int main() {
    printf("Select the list you want to continue working with:\n1 - Linear simply linked list (lab10)\n"
           "2 - The linear double linked list (lab11)\n3 - Ring single-linked list (lab12)\nPrint parametr: " );
    int c;
    scanf("%d", &c);
    while ((c!=1) && (c!=2) && (c!=3)) {
        printf("Incorrect input! Try again: ");
        scanf("%d", &c);
    }
    if(c == 1)
        c = main_lab10();
    else if(c == 2)
        c = main_lab11();
    else if(c == 3)
        c = main_lab12();

    puts("Enter '1' to exit program");
    int h;
    scanf("%d", &h);
    return c;
}