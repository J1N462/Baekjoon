#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "mkmaze.h"
#include "dfsbfs.h"

int main(void) {
    int rows = 15;
    int cols = 15;
    int choice;

    srand((unsigned int)time(NULL));

    char **maze = alloc_maze(rows, cols);
    generate_maze(maze, rows, cols);

    printf("1. BFS\n");
    printf("2. DFS\n");
    printf("choose: ");
    scanf("%d", &choice);

    if(choice == 1){
        bfs(maze, rows, cols);
    }
    else if(choice == 2){
        dfs(maze, rows, cols);
    }
    else{
        printf("wrong choice\n");
        free_maze(maze, rows);
        return 0;
    }

    print_maze_color(maze, rows, cols);
    free_maze(maze, rows);

    return 0;
}

