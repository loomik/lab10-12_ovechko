#include "lab_11.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "struct.h"
#include "read.h"


int main_lab11() {  // Мэйн для линейного двусвязного списка
    head h = MakeHead();
    int r, j=11;
    r = read(&h, j);
    puts("Your list");
    display(&h);
    if (r == 2) {
        if (h.size == 0) {
            puts("Error. List is empty");
        } else {
            menu_choose(&h);
        }
    }
    return 0;
}


void add11(GameDev *Game, head *h) {   // Добавление елемента в список
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
        Game->prev = current;
        h->last = Game;
        current->next = Game;
    }
}

void menu_choose(head *h){ // Меню для выбора выводимого поля
    int k, p;
    printf("1 - output id\n2 - output name\n3 - output chapter\n4 - output developer\n5 - output date\n"
           "6 - output publisher rate\n7 - output gamers rate\n8 - output both rate\n"
           "9 - output first publisher rate\n10 - output second publisher rate\nPrint parametr: ");
    scanf("%d", &k);
    while (k < 1 || k > 10) {
        printf("Incorrect input! Try again: ");
        scanf("%d", &k);
    }
    printf("\n1 - output in direct order\n2 - output in reverse order\nPrint parametr: ");
    scanf("%d", &p);
    while (p < 1 || p > 2) {
        printf("Incorrect input! Try again: ");
        scanf("%d", &p);
    }
    delete(h, p);
    if (k == 1)
        output_id(h,p);
    else if (k == 2)
        output_name(h, p);
    else if (k == 3)
        output_chapter(h, p);
    else if (k == 4)
        output_dev(h, p);
    else if (k == 5)
        output_date(h, p);
    else if (k == 6)
        output_Publisherrate(h, p);
    else if (k == 7)
        output_Gamersrate(h, p);
    else if (k == 8)
        output_bothrate(h, p);
    else if (k == 9)
        output_Publisher1(h, p);
    else if (k == 10)
        output_Publisher2(h, p);
}

void delete(head* h, int p) { // Удаление последнего элемента, в зависимости от выбранного вывода
    GameDev *current = h->first;
    GameDev *previous = current;
    if (p == 1) {
        while (current != NULL) {
            if (current->id == h->size) {
                previous->next = current->next;
                if (current == h->first)
                    h->first = current->next;
                free(current);
            }
            previous = current;
            current = current->next;
        }
    } else if (p == 2){
        while (current != NULL) {
            if (current->id == 1) {
                previous->next = current->next;
                if (current == h->first)
                    h->first = current->next;
                free(current);
            }
            previous = current;
            current = current->next;
        }
    }
}

void output_id(head *h, int p){ // Вывод поля с id
    if (p == 1) {
        GameDev *current = h->first;
        printf("Output id in direct order with the last item removed: \n");
        while (current != NULL) {
            printf("|%3d |\n", current->id);
            current = current->next;
        }
    }
    else if (p == 2) {
        GameDev *previous = h->last;
        printf("Output id in reverse order with the last item removed: \n");
        while (previous->prev != NULL) {
            printf("|%3d |\n", previous->id);
            previous = previous->prev;
        }
    }
}


void output_name(head *h, int p){ // Вывод поля с названием игры
    if (p == 1) {
        GameDev *current = h->first;
        printf("Output name in direct order with the last item removed: \n");
        while (current != NULL) {
            printf("|%20s |\n", current->name);
            current = current->next;
        }
    }
    else if (p == 2) {
        GameDev *previous = h->last;
        printf("Output name in reverse order with the last item removed: \n");
        while (previous->prev != NULL) {
            printf("|%20s |\n", previous->name);
            previous = previous->prev;
        }
    }
}


void output_chapter(head *h, int p){ // Вывод поля с названием части игры
    if (p == 1) {
        GameDev *current = h->first;
        printf("Output chapter in direct order with the last item removed: \n");
        while (current != NULL) {
            printf("|%12s |\n", current->chapter);
            current = current->next;
        }
    }
    else if (p == 2) {
        GameDev *previous = h->last;
        printf("Output chapter in reverse order with the last item removed: \n");
        while (previous->prev != NULL) {
            printf("|%12s |\n", previous->chapter);
            previous = previous->prev;
        }
    }
}


void output_dev(head *h, int p){ // Вывод поля с названием разработчика игры
    if (p == 1) {
        GameDev *current = h->first;
        printf("Output developer in direct order with the last item removed: \n");
        while (current != NULL) {
            printf("|%32s |\n", current->developer);
            current = current->next;
        }
    }
    else if (p == 2) {
        GameDev *previous = h->last;
        printf("Output developer in reverse order with the last item removed: \n");
        while (previous->prev != NULL) {
            printf("|%32s |\n", previous->developer);
            previous = previous->prev;
        }
    }
}

void output_date(head *h, int p){ // Вывод поля с датой выпуска игры
    if (p == 1) {
        GameDev *current = h->first;
        printf("Output date in direct order with the last item removed: \n");
        while (current != NULL) {
            printf("|%3d.%2d.%4d |\n", current->date[0], current->date[1], current->date[2]);
            current = current->next;
        }
    }
    else if (p == 2) {
        GameDev *previous = h->last;
        printf("Output date in reverse order with the last item removed: \n");
        while (previous->prev != NULL) {
            printf("|%3d.%2d.%4d |\n", previous->date[0], previous->date[1], previous->date[2]);
            previous = previous->prev;
        }
    }
}

void output_Publisherrate(head *h, int p){  // Вывод поля с средними оценками изданий
    if (p == 1) {
        GameDev *current = h->first;
        printf("Output publisher rate in direct order with the last item removed: \n");
        while (current != NULL) {
            printf("|%3.2f |\n", current->Publisherrate);
            current = current->next;
        }
    }
    else if (p == 2) {
        GameDev *previous = h->last;
        printf("Output publisher rate in reverse order with the last item removed: \n");
        while (previous->prev != NULL) {
            printf("|%3.2f |\n", previous->Publisherrate);
            previous = previous->prev;
        }
    }
}

void output_Gamersrate(head *h, int p){  // Вывод поля с оценками игроков
    if (p == 1) {
        GameDev *current = h->first;
        printf("Output gamers rate in direct order with the last item removed: \n");
        while (current != NULL) {
            printf("|%3d |\n", current->Gamersrate);
            current = current->next;
        }
    }
    else if (p == 2) {
        GameDev *previous = h->last;
        printf("Output gamers rate in reverse order with the last item removed: \n");
        while (previous->prev != NULL) {
            printf("|%3d |\n", previous->Gamersrate);
            previous = previous->prev;
        }
    }
}

void output_bothrate(head *h, int p){ // Вывод поля основной оценкой игры
    if (p == 1) {
        GameDev *current = h->first;
        printf("Output both rate in direct order with the last item removed: \n");
        while (current != NULL) {
            printf("|%3.2f |\n", current->bothrate);
            current = current->next;
        }
    }
    else if (p == 2) {
        GameDev *previous = h->last;
        printf("Output both rate in reverse order with the last item removed: \n");
        while (previous->prev != NULL) {
            printf("|%3.2f |\n", previous->bothrate);
            previous = previous->prev;
        }
    }
}

void output_Publisher1(head *h, int p){ // Вывод поля оценкой первого издания
    if (p == 1) {
        GameDev *current = h->first;
        printf("Output rate first publisher in direct order with the last item removed: \n");
        while (current != NULL) {
            printf("|%3d |\n", current->Publisher1);
            current = current->next;
        }
    }
    else if (p == 2) {
        GameDev *previous = h->last;
        printf("Output rate first publisher in reverse order with the last item removed: \n");
        while (previous->prev != NULL) {
            printf("|%3d |\n", previous->Publisher1);
            previous = previous->prev;
        }
    }
}

void output_Publisher2(head *h, int p){ // Вывод поля оценкой второго издания
    if (p == 1) {
        GameDev *current = h->first;
        printf("Output rate second publisher in direct order with the last item removed: \n");
        while (current != NULL) {
            printf("|%3d |\n", current->Publisher2);
            current = current->next;
        }
    }
    else if (p == 2) {
        GameDev *previous = h->last;
        printf("Output rate second publisher in reverse order with the last item removed: \n");
        while (previous->prev != NULL) {
            printf("|%3d |\n", previous->Publisher2);
            previous = previous->prev;
        }
    }
}