#ifndef LAB10_12_OVECHKO_LAB_10_H
#define LAB10_12_OVECHKO_LAB_10_H

#include "struct.h"

int main_lab10(); // Мэйн для линейного односвязного списка
int menu_delete(head*); // Меню для выбора удаляемого элемента

void add10(GameDev *Game, head *h); // Добавление элемента в список

int delete_id(int id, head *h); // Удаление элемента
int delete_name(char* c, head *h); // Удаление элемента
int delete_chapter(char *c, head *h); // Удаление элемента
int delete_dev(char *c, head *h); // Удаление элемента
int delete_release(int year, head *h); // Удаление элемента
int delete_Publisherrate(float rate, head *h); // Удаление элемента
int delete_Gamersrate(int rate, head *h); // Удаление элемента
int delete_bothrate(float rate, head *h); // Удаление элемента
int delete_Publisher1(int pub, head *h); // Удаление элемента
int delete_Publisher2(int pub, head *h); // Удаление элемента

#endif //LAB10_12_OVECHKO_LAB_10_H
