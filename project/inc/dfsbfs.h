#ifndef SEARCH_H
#define SEARCH_H

#include "deque.h"

Element find_start(char **maze, int rows, int cols);
Element find_end(char **maze, int rows, int cols);
int in_range(int r, int c, int rows, int cols);

int bfs(char **maze, int rows, int cols);
int dfs(char **maze, int rows, int cols);

void print_maze_color(char **maze, int rows, int cols);

#endif
