#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "mkmaze.h"

typedef struct {
    int r;
    int c;
} Node;

char **alloc_maze(int rows, int cols) {
    char **maze = (char **)malloc(sizeof(char *) * rows);
    for (int i = 0; i < rows; i++) {
        maze[i] = (char *)malloc(sizeof(char) * cols);
    }
    return maze;
}

void free_maze(char **maze, int rows) {
    for (int i = 0; i < rows; i++) {
        free(maze[i]);
    }
    free(maze);
}

static void shuffle(int dir[4]) {
    for (int i = 3; i > 0; i--) {
        int j = rand() % (i + 1);
        int temp = dir[i];
        dir[i] = dir[j];
        dir[j] = temp;
    }
}

void generate_maze(char **maze, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            maze[i][j] = 'X';
        }
    }

    Node *stack = (Node *)malloc(sizeof(Node) * rows * cols);
    int top = -1;

    maze[1][1] = 'O';
    stack[++top] = (Node){1, 1};

    int dr[4] = {-2, 2, 0, 0};
    int dc[4] = {0, 0, -2, 2};

    while (top >= 0) {
        Node cur = stack[top];
        int dirs[4] = {0, 1, 2, 3};
        shuffle(dirs);

        int moved = 0;

        for (int i = 0; i < 4; i++) {
            int d = dirs[i];
            int nr = cur.r + dr[d];
            int nc = cur.c + dc[d];

            if (nr <= 0 || nr >= rows - 1 || nc <= 0 || nc >= cols - 1) {
                continue;
            }

            if (maze[nr][nc] == 'X') {
                maze[cur.r + dr[d] / 2][cur.c + dc[d] / 2] = 'O';
                maze[nr][nc] = 'O';
                stack[++top] = (Node){nr, nc};
                moved = 1;
                break;
            }
        }

        if (!moved) {
            top--;
        }
    }

    maze[1][1] = 'S';
    maze[rows - 2][cols - 2] = 'E';

    free(stack);
}

void print_maze(char **maze, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (maze[i][j] == 'X') {
                printf("\x1b[40m  \x1b[0m");
            }
            else if (maze[i][j] == 'O') {
                printf("\x1b[47m  \x1b[0m");
            }
            else if (maze[i][j] == 'S') {
                printf("\x1b[42mS \x1b[0m");
            }
            else if (maze[i][j] == 'E') {
                printf("\x1b[41mE \x1b[0m");
            }
            else if (maze[i][j] == '.') {
                printf("\x1b[43m  \x1b[0m");
            }
            else {
                printf("%c ", maze[i][j]);
            }
        }
        printf("\n");
    }
}
