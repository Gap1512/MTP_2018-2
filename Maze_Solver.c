/* Maze_Solver.c */
/* Gustavo Alves Pacheco */
/* 11821ECP011 */

#include <stdio.h>

#define MAX 8

void print_maze(char maze[MAX][MAX]) {
  int i, j;
  printf("+--------+\n");
  for (i = 0; i < MAX; i++){
    printf("|");
    for (j = 0; j < MAX; j++){
      printf("%c", maze[i][j]);
    }
    printf("|\n");
  }
  printf("+--------+\n");
}

int solve_maze_aux(char maze[MAX][MAX], int x_atual, int y_atual) {

  if (maze[x_atual][y_atual] == '-' || maze[x_atual][y_atual] == 'O') {
    return 0;
  }
  else if (x_atual == MAX - 1 && y_atual == MAX - 1) {
    maze[x_atual][y_atual] = 'X';
    return 1;
  }
  else {
    maze[x_atual][y_atual] = 'O';
    if      (solve_maze_aux(maze, x_atual, y_atual + 1)) {
      maze[x_atual][y_atual] = 'X';
      return 1;
    }
    else if (solve_maze_aux(maze, x_atual, y_atual - 1)) {
      maze[x_atual][y_atual] = 'X';
      return 1;
    }
    else if (solve_maze_aux(maze, x_atual + 1, y_atual)) {
      maze[x_atual][y_atual] = 'X';
      return 1;
    }
    else if (solve_maze_aux(maze, x_atual - 1, y_atual)) {
      maze[x_atual][y_atual] = 'X';
      return 1;
    }
  }
}


void solve_maze(char maze[MAX][MAX]){
  solve_maze_aux(maze, 0, 0);
}

int main(int argc, char const *argv[]) {
  char maze[MAX][MAX] =  {'$','@','-','@','@','@','-','-',
                          '-','@','-','@','-','-','-','-',
                          '-','@','@','@','@','@','@','@',
                          '-','@','-','-','@','-','-','-',
                          '@','@','-','@','@','@','@','-',
                          '-','@','-','-','@','-','-','-',
                          '-','@','@','@','@','@','@','@',
                          '-','-','-','-','-','-','-','$'};
  print_maze(maze);
  solve_maze(maze);
  printf("\n");
  print_maze(maze);
  return 0;
}
