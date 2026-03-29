#ifndef MKMAZE_H
#define MKMAZE_H

char **alloc_maze(int rows, int cols);
void free_maze(char **maze, int rows);
void generate_maze(char **maze, int rows, int cols);
void print_maze(char **maze, int rows, int cols);

#endif
