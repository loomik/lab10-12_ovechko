#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "struct.h"
#include "read.h"
#include "lab_12.h"


int main_lab12() { // Мэйн для кольцевой односвязного списка
    head h = MakeHead();
    int r, j=12;
    r = read(&h, j);
    puts("Your list");
    display_ring(&h);
    if (r == 2) {
        if (h.size == 0) {
            puts("Error. List is empty");
        } else {
            menu_select(&h);
        }
    }

    return 0;
}


void add12(GameDev* Game, head* h ) { // Добавление елемента в список
    GameDev *current = NULL;
    Game->next = NULL;
    Game->id = 1;

    if (h->first == NULL) {
        h->first = Game;
        Game->next = h->first;
    } else {
        Game->next = h->first;
        Game->id++;
        (h->size)++;
        current = h->first;
        while (current->next != h->first) {
            Game->id++;
            current = current->next;
        }
        h->last = current;
        current->next = Game;
    }
}

void display_ring(head *h) {
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
    printf("%-3d|%-20s|%-25s|%-25s|%d.%d.%d\t  |%-25.2f|%-21d|%-19.2f|%-23d|%-23d|\n", current->id,
           current->name, current->chapter, current->developer, current->date[0], current->date[1],
           current->date[2], current->Publisherrate, current->Gamersrate, current->bothrate,
           current->Publisher1, current->Publisher2);
    current = current->next;
    printf("---+--------------------+-------------------------+-------------------------+----"
           "---------+-------------------------+---------------------+-------------------+-----"
           "------------------+-----------------------+\n");
    while (current != h->first) {
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

void menu_select(head *h){ // Меню для выбора выводимого поля
    int k, p;
    printf("1 - derivation id\n2 - derivation name\n3 - derivation chapter\n4 - derivation developer\n5 - derivation date\n"
           "6 - derivation publisher rate\n7 - derivation gamers rate\n8 - derivation both rate\n"
           "9 - derivation first publisher rate\n10 - derivation second publisher rate\nPrint parametr: ");
    scanf("%d", &k);
    while (k < 1 || k > 10) {
        printf("Incorrect input! Try again: ");
        scanf("%d", &k);
    }
    printf("\n1 - derivation in direct order\n2 - derivation in reverse order\nPrint parametr: ");
    scanf("%d", &p);
    while (p < 1 || p > 2) {
        printf("Incorrect input! Try again: ");
        scanf("%d", &p);
    }
    uninstall(h, p);
    display_ring(h);
    if (k == 1)
        derivation_id(h,p);
    else if (k == 2)
        derivation_name(h, p);
    else if (k == 3)
        derivation_chapter(h, p);
    else if (k == 4)
        derivation_dev(h, p);
    else if (k == 5)
        derivation_date(h, p);
    else if (k == 6)
        derivation_Publisherrate(h, p);
    else if (k == 7)
        derivation_Gamersrate(h, p);
    else if (k == 8)
        derivation_bothrate(h, p);
    else if (k == 9)
        derivation_Publisher1(h, p);
    else if (k == 10)
        derivation_Publisher2(h, p);
}

void uninstall(head* h, int p) { // Удаление последнего элемента, в зависимости от выбранного вывода
    GameDev *current = h->first;
    GameDev *previous = current;
    GameDev *remember = NULL;
    int c = 0;
    if (p == 1) {
        while (current != h->first || c == 0) {
            c++;
            if (current->id == h->size) {
                previous->next = current->next;
                if (current == h->first)
                    h->first = current->next;
                free(current);
            }
            previous = current;
            current = current->next;
        }
    } else if (p == 2) {
        while (current != h->first || c == 0) {
            c++;
            if (current->id == c) {
                free(remember);
            }
        }
    }
}

void derivation_id(head *h, int p){ // Вывод поля с id
    if (p == 1) {
        GameDev *current = h->first;
        printf("Output id in direct order with the last item removed: \n");
        int c = 0;
        while (current != h->first || c == 0) {
            c++;
            printf("|%3d |\n", current->id);
            current = current->next;
        }
    }
    else if (p == 2) {
        GameDev *current = h->first;
        GameDev *previous = h->last;
        int c = 0, k = h->size;
        printf("Output id in reverse order with the last item removed: \n");
        while (current != previous || c == 0) {
            c++;
            if (k == 1)
                return;
            if (current->id == k) {
                printf("|%3d |\n", current->id);
                k--;
            }
            current = current->next;
            previous = previous->next;
        }
    }
}


void derivation_name(head *h, int p){ // Вывод поля с названием игры
    if (p == 1) {
        GameDev *current = h->first;
        printf("Output name in direct order with the last item removed: \n");
        int c = 0;
        while (current != h->first || c == 0) {
            c++;
            printf("|%20s |\n", current->name);
            current = current->next;
        }
    }
    else if (p == 2) {
        GameDev *current = h->first;
        GameDev *previous = h->last;
        int c = 0, k = h->size;
        printf("Output name in reverse order with the last item removed: \n");
        while (current != previous || c == 0) {
            c++;
            if (k == 1)
                return;
            if (current->id == k) {
                printf("|%20s |\n", current->name);
                k--;
            }
            current = current->next;
            previous = previous->next;
        }
    }
}


void derivation_chapter(head *h, int p){ // Вывод поля с названием части игры
    if (p == 1) {
        GameDev *current = h->first;
        printf("Output chapter in direct order with the last item removed: \n");
        int c = 0;
        while (current != h->first || c == 0) {
            c++;
            printf("|%12s |\n", current->chapter);
            current = current->next;
        }
    }
    else if (p == 2) {
        GameDev *current = h->first;
        GameDev *previous = h->last;
        int c = 0, k = h->size;
        printf("Output chapter in reverse order with the last item removed: \n");
        while (current != previous || c == 0) {
            c++;
            if (k == 1)
                return;
            if (current->id == k) {
                printf("|%12s |\n", current->chapter);
                k--;
            }
            current = current->next;
            previous = previous->next;
        }
    }
}


void derivation_dev(head *h, int p){ // Вывод поля с названием разработчика игры
    if (p == 1) {
        GameDev *current = h->first;
        printf("Output developer in direct order with the last item removed: \n");
        int c = 0;
        while (current != h->first || c == 0) {
            c++;
            printf("|%32s |\n", current->developer);
            current = current->next;
        }
    }
    else if (p == 2) {
        GameDev *current = h->first;
        GameDev *previous = h->last;
        int c = 0, k = h->size;
        printf("Output developer in reverse order with the last item removed: \n");
        while (current != previous || c == 0) {
            c++;
            if (k == 1)
                return;
            if (current->id == k) {
                printf("|%32s |\n", current->developer);
                k--;
            }
            current = current->next;
            previous = previous->next;
        }
    }
}

void derivation_date(head *h, int p){ // Вывод поля с датой выпуска игры
    if (p == 1) {
        GameDev *current = h->first;
        printf("Output date in direct order with the last item removed: \n");
        int c = 0;
        while (current != h->first || c == 0) {
            c++;
            printf("|%3d.%2d.%4d |\n", current->date[0], current->date[1], current->date[2]);
            current = current->next;
        }
    }
    else if (p == 2) {
        GameDev *current = h->first;
        GameDev *previous = h->last;
        int c = 0, k = h->size;
        printf("Output date in reverse order with the last item removed: \n");
        while (current != previous || c == 0) {
            c++;
            if (k == 1)
                return;
            if (current->id == k) {
                printf("|%3d.%2d.%4d |\n", current->date[0], current->date[1], current->date[2]);
                k--;
            }
            current = current->next;
            previous = previous->next;
        }
    }
}

void derivation_Publisherrate(head *h, int p){  // Вывод поля с средними оценками изданий
    if (p == 1) {
        GameDev *current = h->first;
        printf("Output publisher rate in direct order with the last item removed: \n");
        int c = 0;
        while (current != h->first || c == 0) {
            c++;
            printf("|%3.2f |\n", current->Publisherrate);
            current = current->next;
        }
    }
    else if (p == 2) {
        GameDev *current = h->first;
        GameDev *previous = h->last;
        int c = 0, k = h->size;
        printf("Output publisher rate in reverse order with the last item removed: \n");
        while (current != previous || c == 0) {
            c++;
            if (k == 1)
                return;
            if (current->id == k) {
                printf("|%3.2f |\n", current->Publisherrate);
                k--;
            }
            current = current->next;
            previous = previous->next;
        }
    }
}

void derivation_Gamersrate(head *h, int p){  // Вывод поля с оценками игроков
    if (p == 1) {
        GameDev *current = h->first;
        printf("Output gamers rate in direct order with the last item removed: \n");
        int c = 0;
        while (current != h->first || c == 0) {
            c++;
            printf("|%3d |\n", current->Gamersrate);
            current = current->next;
        }
    }
    else if (p == 2) {
        GameDev *current = h->first;
        GameDev *previous = h->last;
        int c = 0, k = h->size;
        printf("Output gamers rate in reverse order with the last item removed: \n");
        while (current != previous || c == 0) {
            c++;
            if (k == 1)
                return;
            if (current->id == k) {
                printf("|%3d |\n", current->Gamersrate);
                k--;
            }
            current = current->next;
            previous = previous->next;
        }
    }
}

void derivation_bothrate(head *h, int p){ // Вывод поля основной оценкой игры
    if (p == 1) {
        GameDev *current = h->first;
        printf("Output both rate in direct order with the last item removed: \n");
        int c = 0;
        while (current != h->first || c == 0) {
            c++;
            printf("|%3.2f |\n", current->bothrate);
            current = current->next;
        }
    }
    else if (p == 2) {
        GameDev *current = h->first;
        GameDev *previous = h->last;
        int c = 0, k = h->size;
        printf("Output both rate in reverse order with the last item removed: \n");
        while (current != previous || c == 0) {
            c++;
            if (k == 1)
                return;
            if (current->id == k) {
                printf("|%3.2f |\n", current->bothrate);
                k--;
            }
            current = current->next;
            previous = previous->next;
        }
    }
}

void derivation_Publisher1(head *h, int p){ // Вывод поля оценкой первого издания
    if (p == 1) {
        GameDev *current = h->first;
        printf("Output rate first publisher in direct order with the last item removed: \n");
        int c = 0;
        while (current != h->first || c == 0) {
            c++;
            printf("|%3d |\n", current->Publisher1);
            current = current->next;
        }
    }
    else if (p == 2) {
        GameDev *current = h->first;
        GameDev *previous = h->last;
        int c = 0, k = h->size;
        printf("Output rate first publisher in reverse order with the last item removed: \n");
        while (current != previous || c == 0) {
            c++;
            if (k == 1)
                return;
            if (current->id == k) {
                printf("|%3d |\n", current->Publisher1);
                k--;
            }
            current = current->next;
            previous = previous->next;
        }
    }
}

void derivation_Publisher2(head *h, int p){ // Вывод поля оценкой второго издания
    if (p == 1) {
        GameDev *current = h->first;
        printf("Output rate second publisher in direct order with the last item removed: \n");
        int c = 0;
        while (current != h->first || c == 0) {
            c++;
            printf("|%3d |\n", current->Publisher2);
            current = current->next;
        }
    }
    else if (p == 2) {
        GameDev *current = h->first;
        GameDev *previous = h->last;
        int c = 0, k = h->size;
        printf("Output rate second publisher in reverse order with the last item removed: \n");
        while (current != previous || c == 0) {
            c++;
            if (k == 1)
                return;
            if (current->id == k) {
                printf("|%3d |\n", current->Publisher2);
                k--;
            }
            current = current->next;
            previous = previous->next;
        }
    }
}


