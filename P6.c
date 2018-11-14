/* P6.c */
/* Gustavo Alves Pacheco */
/* 11821ECP011 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
  double x, y;
} Point;

typedef
  double
Angle;

//Angle Array -> Point Array
//Receive an array of angles, allocates memory for the points array and returns the base adress
Point * angles_points(Angle *angles, int divisions);

//Angle -> Points
//Receive an angle and return the corresponding point
//Given 0, Returns (0, 0)
//Given pi/2, Returns (0, 1)
//Given pi, Returns (-1, 0)
//Given 2pi, Returns (1, 0)
Point angle_point(Angle angle);

//Number -> Angle Array
//Receive the number of divisions, allocates memory for the angles array and returns the base adress
//Given 2, Returns {0, pi}
//Given 4, Returns {0, pi/2, pi, 3pi/4}
Angle * divisions_angles(int divisions);

//Points Array -> Void
//Prints All The Points
void print_points(Point *points, int divisions);

int main() {
  int divisions;
  Point *points;
  Angle *angles;

  printf("Enter The Number Of Divisions\n");
  scanf("%d", &divisions); getchar();

  angles = divisions_angles(divisions);
  points = angles_points(angles, divisions);

  print_points(points, divisions);

  printf("\n");

  free(points);
  free(angles);
  return 0;
}

Point angle_point(Angle angle) {
  Point point;
  point.x = cos(angle);
  point.y = sin(angle);
  return point;
}

Point * angles_points(Angle *angles, int divisions) {
  Point *points = (Point *) malloc(divisions * (sizeof(Point)));
  int i;
  for (i = 0; i < divisions; i++) {
    points[i] = angle_point(angles[i]);
  }
  return points;
}

Angle * divisions_angles(int divisions) {
  Angle *angles = (Angle *) malloc(divisions * (sizeof(Angle)));
  int i;
  Angle sum = ((2 * M_PI) / (divisions - 1));
  angles[0] = 0.;
  for (i = 1; i < divisions; i++) {
    angles[i] = angles[i - 1] + sum;
  }
  return angles;
}

void print_points(Point *points, int divisions) {
  if (divisions) {
    printf("(%.3lf, %.3lf) ", points->x, points->y);
    print_points(points + 1, divisions - 1);
  }
  return;
}
