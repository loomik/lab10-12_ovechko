#ifndef LAB10_12_OVECHKO_LAB_12_H
#define LAB10_12_OVECHKO_LAB_12_H

#include "struct.h"

int main_lab12(); // Мэйн для кольцевой односвязного списка
void add12(GameDev*, head*); // Добавление елемента в список
void display_ring(head *h);

void menu_select(head*);
void uninstall(head*, int); // Удаление последнего элемента, в зависимости от выбранного вывода

void derivation_id(head*, int); // Вывод поля с id
void derivation_name(head*, int); // Вывод поля с названием игры
void derivation_chapter(head *h, int p); // Вывод поля с названием части игры
void derivation_dev(head *h, int p);  // Вывод поля с названием разработчика игры
void derivation_date(head *h, int p); // Вывод поля с датой выпуска игры
void derivation_Publisherrate(head *h, int p); // Вывод поля с средними оценками изданий
void derivation_Gamersrate(head *h, int p);  // Вывод поля с оценками игроков
void derivation_bothrate(head *h, int p); // Вывод поля основной оценкой игры
void derivation_Publisher1(head *h, int p); // Вывод поля оценкой первого издания
void derivation_Publisher2(head *h, int p);  // Вывод поля оценкой второго издания

#endif //LAB10_12_OVECHKO_LAB_12_H
