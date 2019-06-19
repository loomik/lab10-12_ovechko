#include "lab_10.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "struct.h"
#include "read.h"
#define eps 0.000001

int main_lab10() { // Мэйн для линейного односвязного списка
    head h = MakeHead();
    int r, j=10;
    r = read(&h, j);
    if (r == 2) {
        if (h.size == 0) {
            puts("Error. List is empty");
        } else {
            puts("Your list");
            display(&h);
            r = menu_delete(&h);
            if (r == 1) {
                puts("Removal was successful, the final list");
                display(&h);
            }
        }
        return 0;
    }
}


void add10(GameDev *Game, head *h) { // Добавление елемента в список
    GameDev *current = NULL;
    Game->next = NULL;
    Game->id = 1;

    if (h->first == NULL) {
        h->first = Game;
    } else {
        Game->id++;
        (h->size)++;
        current = h->first;
        while (current->next != NULL) {
            Game->id++;
            current = current->next;
        }
        current->next = Game;
    }
}

int menu_delete(head *h) { // Меню для выбора удаляемого элемента
    int k, u;
    char c[100];
    float f;
    printf("1 - delete by id\n2 - delete by name\n3 - delete by chapter\n4 - delete by developer\n5 - delete by year"
           "\n6 - delete by publisher rate\n7 - delete by gamers rate\n8 - delete by both rate\n"
           "9 - delete by first publisher rate\n10 - delete by second publisher rate\nPrint parametr: ");
    scanf("%d", &k);
    while (k < 1 || k > 10) {
        printf("Incorrect input! Try again: ");
        scanf("%d", &k);
    }
    if (k==1) {
        printf("Print id");
        scanf("%d", &k);
        u = delete_id(k, h);
    }
    else if (k==2)
    {
        printf("Print name");
        scanf("%s", c);
        u = delete_name(c, h);
    }
    else if (k==3)
    {
        printf("Print chapter");
        scanf("%s", c);
        u = delete_chapter(c, h);
    }
    else if (k==4)
    {
        printf("Print developer");
        scanf("%s", c);
        u = delete_dev(c, h);
    }
    else if (k==5) {
        printf("Print year");
        scanf("%d", &k);
        u = delete_release(k, h);
    }
    else if (k==6) {
        printf("Print publisher rate");
        scanf("%f", &f);
        u = delete_Publisherrate(f, h);
    }
    else if (k==7) {
        printf("Print gamers rate");
        scanf("%d", &k);
        u = delete_Gamersrate(k, h);
    }
    else if (k==8) {
        printf("Print both rate");
        scanf("%f", &f);
        u = delete_bothrate(f, h);
    }
    else if (k==9) {
        printf("Print rate first publisher");
        scanf("%d", &k);
        u = delete_Publisher1(k, h);
    }
    else if (k==10) {
        printf("Print rate second publisher");
        scanf("%d", &k);
        u = delete_Publisher2(k, h);
    }
    if (u == 0) {
        printf("Not found");
    }
    return u;
}

int delete_id(int id, head *h) {  // Удаление элемента
    GameDev *current = h->first;
    GameDev *previous = current;
    int u = 0;
    while (current != NULL)
    {
        if (current->id == id)
        {
            previous->next = current->next;
            if (current == h->first)
                h->first = current->next;
            free(current);
            u =1;
        }
        previous = current;
        current = current->next;
    }
    return u;
}

int delete_name(char* c, head *h) {  // Удаление элемента
    GameDev *current = h->first;
    GameDev *previous = current;
    int u = 0;
    while (current != NULL)
    {
        if (strcmp(current->name, c) == 0)
        {
            previous->next = current->next;
            if (current == h->first)
                h->first = current->next;
            free(current);
            u = 1;
        }
        previous = current;
        current = current->next;
    }
    return u;
}


int delete_chapter(char *c, head *h) {  // Удаление элемента
    GameDev *current = h->first;
    GameDev *previous = current;
    int u = 0;
    while (current != NULL)
    {
        if (strcmp(current->chapter, c) == 0)
        {
            previous->next = current->next;
            if (current == h->first)
                h->first = current->next;
            free(current);
            u = 1;
        }
        previous = current;
        current = current->next;
    }
    return u;
}


int delete_dev(char *c, head *h) {  // Удаление элемента
    GameDev *current = h->first;
    GameDev *previous = current;
    int u = 0;
    while (current != NULL)
    {
        if (strcmp(current->developer, c) == 0)
        {
            previous->next = current->next;
            if (current == h->first)
                h->first = current->next;
            free(current);
            u = 1;
        }
        previous = current;
        current = current->next;
    }
    return u;
}

int delete_release(int year, head *h) {  // Удаление элемента
    GameDev *current = h->first;
    GameDev *previous = current;
    int u = 0;
    while (current != NULL)
    {
        if (current->date[2] == year)
        {
            previous->next = current->next;
            if (current == h->first)
                h->first = current->next;
            free(current);
            u = 1;
        }
        previous = current;
        current = current->next;
    }
    return u;
}
int delete_Publisherrate(float rate, head *h) {  // Удаление элемента
    GameDev *current = h->first;
    GameDev *previous = current;
    int u = 0;
    while (current != NULL)
    {
        if (fabs(current->Publisherrate - rate)<eps)
        {
            previous->next = current->next;
            if (current == h->first)
                h->first = current->next;
            free(current);
            u = 1;
        }
        previous = current;
        current = current->next;
    }
    return u;
}
int delete_Gamersrate(int rate, head *h) {  // Удаление элемента
    GameDev *current = h->first;
    GameDev *previous = current;
    int u = 0;
    while (current != NULL)
    {
        if (current->Gamersrate == rate)
        {
            previous->next = current->next;
            if (current == h->first)
                h->first = current->next;
            free(current);
            u =1;
        }
        previous = current;
        current = current->next;
    }
    return u;
}


int delete_bothrate(float rate, head *h) {  // Удаление элемента
    GameDev *current = h->first;
    GameDev *previous = current;
    int u = 0;
    while (current != NULL)
    {
        if (fabs(current->bothrate - rate)<eps)
        {
            previous->next = current->next;
            if (current == h->first)
                h->first = current->next;
            free(current);
            u = 1;
        }
        previous = current;
        current = current->next;
    }
    return u;
}


int delete_Publisher1(int pub, head *h) {  // Удаление элемента
    GameDev *current = h->first;
    GameDev *previous = current;
    int u = 0;
    while (current != NULL)
    {
        if (current->Publisher1 == pub)
        {
            previous->next = current->next;
            if (current == h->first)
                h->first = current->next;
            free(current);
            u = 1;
        }
        previous = current;
        current = current->next;
    }
    return u;
}

int delete_Publisher2(int pub, head *h) {  // Удаление элемента
    GameDev *current = h->first;
    GameDev *previous = current;
    int u = 0;
    while (current != NULL)
    {
        if (current->Publisher2 == pub)
        {
            previous->next = current->next;
            if (current == h->first)
                h->first = current->next;
            free(current);
            u = 1;
        }
        previous = current;
        current = current->next;
    }
    return u;
}
