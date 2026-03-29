#include <stdio.h>
#include <stdlib.h>
#include "dfsbfs.h"

Element find_start(char **maze, int rows, int cols){
     for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (maze[i][j] == 'S') {
                return (Element){i, j};
            }
        }
    }
    return (Element){-1, -1};
}

Element find_end(char **maze, int rows, int cols){
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (maze[i][j] == 'E') {
                return (Element){i, j};
            }
        }
    }
    return (Element){-1, -1};
}

int in_range(int r, int c, int rows, int cols){
    return (0<=r)&&(r<rows)&&(0<=c)&&(c<cols);
}

int bfs(char **maze, int rows, int cols){
    //queue
    Element start = find_start(maze, rows, cols);
    Element end = find_end(maze, rows, cols);

    if(start.r == -1 || end.r == -1){
        return 0;
    }

    int dr[4] = {-1, 1, 0, 0};
    int dc[4] = {0, 0, -1, 1};

    int **visited = (int **)malloc(sizeof(int *) * rows);
    for(int i = 0; i < rows; i++){
        visited[i] = (int *)calloc(cols, sizeof(int));
    }

    init();
    add_rear(start);
    visited[start.r][start.c] = 1;

    while(!is_empty()){
        Element cur = delete_front();

        if(cur.r == end.r && cur.c == end.c){
            for(int i = 0; i < rows; i++){
                free(visited[i]);
            }
            free(visited);
            return 1;
        }

        if(maze[cur.r][cur.c] == 'O'){
            maze[cur.r][cur.c] = '.';
        }

        for(int i = 0; i < 4; i++){
            int nr = cur.r + dr[i];
            int nc = cur.c + dc[i];

            if(!in_range(nr, nc, rows, cols)){
                continue;
            }

            if(visited[nr][nc]){
                continue;
            }

            if(maze[nr][nc] == 'X'){
                continue;
            }

            visited[nr][nc] = 1;
            add_rear((Element){nr, nc});
        }
    }

    for(int i = 0; i < rows; i++){
        free(visited[i]);
    }
    free(visited);

    return 0;
}

int dfs(char **maze, int rows, int cols){
    //stack
    Element start = find_start(maze, rows, cols);
    Element end = find_end(maze, rows, cols);

    if(start.r == -1 || end.r == -1){
        return 0;
    }

    int dr[4] = {-1, 1, 0, 0};
    int dc[4] = {0, 0, -1, 1};

    int **visited = (int **)malloc(sizeof(int *) * rows);
    for(int i = 0; i < rows; i++){
        visited[i] = (int *)calloc(cols, sizeof(int));
    }

    init();
    add_front(start);
    visited[start.r][start.c] = 1;

    while(!is_empty()){
        Element cur = delete_front();

        if(cur.r == end.r && cur.c == end.c){
            for(int i = 0; i < rows; i++){
                free(visited[i]);
            }
            free(visited);
            return 1;
        }

        if(maze[cur.r][cur.c] == 'O'){
            maze[cur.r][cur.c] = '.';
        }

        for(int i = 3; i >= 0; i--){
            int nr = cur.r + dr[i];
            int nc = cur.c + dc[i];

            if(!in_range(nr, nc, rows, cols)){
                continue;
            }

            if(visited[nr][nc]){
                continue;
            }

            if(maze[nr][nc] == 'X'){
                continue;
            }

            visited[nr][nc] = 1;
            add_front((Element){nr, nc});
        }
    }

    for(int i = 0; i < rows; i++){
        free(visited[i]);
    }
    free(visited);

    return 0;
}

void print_maze_color(char **maze, int rows, int cols){
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            if(maze[i][j] == '.'){
                printf("\x1b[43m \x1b[0m ");
            }
            else if(maze[i][j] == 'S'){
                printf("\x1b[42mS \x1b[0m");
            }
            else if(maze[i][j] == 'E'){
                printf("\x1b[44mE \x1b[0m");
            }
            else{
                printf("%c ", maze[i][j]);
            }
        }
        printf("\n");
    }
}

/*
void print_maze_color(char **maze, int rows, int cols){
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            if(maze[i][j] == 'X'){
                printf("\x1b[40m  \x1b[0m");
            }
            else if(maze[i][j] == 'O'){
                printf("\x1b[47m  \x1b[0m");
            }
            else if(maze[i][j] == 'S'){
                printf("\x1b[42mS \x1b[0m");
            }
            else if(maze[i][j] == 'E'){
                printf("\x1b[44mE \x1b[0m");
            }
            else if(maze[i][j] == '.'){
                printf("\x1b[43m  \x1b[0m");
            }
            else{
                printf("%c ", maze[i][j]);
            }
        }
        printf("\n");
    }
}

*/