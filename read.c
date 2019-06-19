#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "struct.h"
#include "read.h"
#include "lab_10.h"
#include "lab_11.h"
#include "lab_12.h"

head MakeHead()  // Создание головы
{
    head h;
    h.first = NULL;
    h.size = 1;
    return h;
}

int read(head *h, int j) {    // Считывание
    FILE *f;
    int r=1;
    if ((f = fopen("rates.csv", "r")) != NULL) {
        fseek(f,0,SEEK_END);
        long pos = ftell(f);
        if(pos>0) // Файл непустой
        {
            rewind(f);
            while (!(feof(f))) {
                h = entry(h, f, j);    // Добавление по строке
            }
        } else h->size = 0;
        if (fclose(f) == EOF) {
            puts("Error closing file");
            r=0;
        }
    }
    else {
        puts("Error opening file");
        r=0;
    }
    return r+1;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////

head *entry(head *h, FILE *f, int j) {		// Запись с файла
    GameDev *current;
    current = (GameDev*)malloc(sizeof(GameDev));
    current->name = (char*)malloc(256 * sizeof(char));
    current->chapter = (char*)malloc(256 * sizeof(char));
    current->developer = (char*)malloc(256 * sizeof(char));
    if (current && current->name) {
        fscanf(f, "%[^;];%[^;];%[^;];%d,%d,%d;%f;%d;%f;%d;%d", current->name, current->chapter,
                current->developer, &(current->date[0]), &(current->date[1]), &(current->date[2]),
                &(current->Publisherrate), &(current->Gamersrate), &(current->bothrate),
                &(current->Publisher1), &(current->Publisher2));
        fgetc(f);
        if (j == 10)
            add10(current, h);
        else if (j == 11)
            add11(current, h);
        else if (j == 12)
            add12(current, h);
    }
    else{
        puts("Memory allocation error!");
        if (current)
            free(current);
        if (current->name)
            free(current->name);
    }
    return h;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////


void display(head *h) {
    GameDev *current = h->first;
    if (current == NULL) {
        printf("List is empty\n");
        return;
    }
    printf("______________________________________________________________________________"
           "_______________________________________________________________________________"
           "__________________________________________________\n");
    printf("Id |Game\t\t|  Chapter\t\t  |  Developer\t\t    |Release date "
           "|Publishers average rating|Gamers average rating|Both average rating|"
           "Rate of first Publisher|Rate of second Publisher|\n");
    printf("___________________________________________________________________________"
           "________________________________________________________________________________"
           "____________________________________________________\n");
    while (current != NULL) {
        printf("%-3d|%-20s|%-25s|%-25s|%d.%d.%d\t  |%-25.2f|%-21d|%-19.2f|%-23d|%-23d|\n", current->id,
               current->name, current->chapter, current->developer, current->date[0], current->date[1],
               current->date[2], current->Publisherrate, current->Gamersrate, current->bothrate,
               current->Publisher1, current->Publisher2);
        current = current->next;
        printf("---+--------------------+-------------------------+-------------------------+----"
               "---------+-------------------------+---------------------+-------------------+-----"
               "------------------+-----------------------+\n");
    }
}
