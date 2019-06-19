#ifndef LAB10_12_OVECHKO_READ_H
#define LAB10_12_OVECHKO_READ_H

#include "struct.h"


head MakeHead(); // Создание головы
int read(head *h, int); // Считывание с файла
head *entry(head *h, FILE *f, int ); // Добавление по строке
void add(GameDev *Game, head *h);
void display(head *h); // Вывод списка


#endif //LAB10_12_OVECHKO_READ_H
