#ifndef LAB10_12_OVECHKO_LAB_11_H
#define LAB10_12_OVECHKO_LAB_11_H

#include "struct.h"


int main_lab11(); // Мэйн для линейного двусвязного списка
void add11(GameDev*, head*); // Добавление елемента в список

void menu_choose(head*); // Меню для выбора выводимого поля

void delete(head*, int); // Удаление последнего элемента, в зависимости от выбранного вывода

void output_id(head*, int); // Вывод поля с id
void output_name(head*, int); // Вывод поля с названием игры
void output_chapter(head *h, int p); // Вывод поля с названием части игры
void output_dev(head *h, int p);  // Вывод поля с названием разработчика игры
void output_date(head *h, int p); // Вывод поля с датой выпуска игры
void output_Publisherrate(head *h, int p); // Вывод поля с средними оценками изданий
void output_Gamersrate(head *h, int p);  // Вывод поля с оценками игроков
void output_bothrate(head *h, int p); // Вывод поля основной оценкой игры
void output_Publisher1(head *h, int p); // Вывод поля оценкой первого издания
void output_Publisher2(head *h, int p);  // Вывод поля оценкой второго издания

#endif //LAB10_12_OVECHKO_LAB_11_H
