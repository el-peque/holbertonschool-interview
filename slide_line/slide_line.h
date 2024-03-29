#ifndef SLIDE_LINE_H
#define SLIDE_LINE_H

#include <stdio.h>
#include <stdlib.h>

#define SLIDE_LEFT 0
#define SLIDE_RIGHT 1

int slide_line(int *line, size_t size, int direction);
int slide_right(int *line, int *changes, size_t size);
int slide_left(int *line, int *changes, size_t size);
void fill_zeroes(int *array, size_t size);

#endif /* SLIDE_LINE_H */
