#ifndef SLIDE_LINE_H
#define SLINE_LINE_H

#define SLIDE_LEFT 0
#define SLIDE_RIGHT 1

#include <stddef.h>

int slide_line(int *line, size_t size, int direction);
void fill_zeroes(int *array, size_t size);

#endif /* SLIDE_LINE_H */
