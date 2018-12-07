/* P7.c */
/* Gustavo Alves Pacheco */
/* 11821ECP011 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define true 1

typedef struct
{
    double x, y;
} Point;

typedef double
    Angle;

//Angle Array -> Point Array
//Receive an array of angles, allocates memory for the points array and returns the base adress
Point *angles_points(Angle *angles, int divisions);

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
Angle *divisions_angles(int divisions);

//Points Array -> Void
//Prints All The Points
void print_points(Point *points, int divisions);

//Points Angle -> Void
//Asks How Many Points And Save Them On A Binary File
void write_on_file(Point *points, Angle *angles);

//Points -> Void
//Prints The Points Coordinates From A File
void read_from_file(Point *points);

int main() {
    unsigned int opt;
    Point *points;
    Angle *angles;

    printf( "1 - Write Points On File\n2 - Read Points From File\nOption[1/2]: ");
    scanf("%u", &opt);
    getchar();

    switch(opt) {
        case 1:
            write_on_file (points, angles);
            break;
        case 2:
            read_from_file(points);
            break;
        default:
            printf("%u Isn't A Valid Choice\n", opt);
            return 0;
            break;
    }

    free(points);
    free(angles);
    return 0;
}

void write_on_file(Point *points, Angle *angles) {
    unsigned int divisions;
    FILE *file;
    file = fopen("pontos.dat", "wb");

    printf("Enter The Number Of Divisions\n");
    scanf("%u", &divisions);
    getchar();

    angles = divisions_angles(divisions);
    points = angles_points(angles, divisions);

    fwrite(points, divisions, sizeof(Point), file);

    printf("File Recorded\n");
}

void read_from_file(Point *points) {
    unsigned int N = 0;
    FILE *file;
    file = fopen("pontos.dat", "rb");

    points = (Point *)malloc(sizeof(Point));

    while(true) {
        fread(points, 1, sizeof(Point), file);
        if(feof(file)) break;
        N++;
    }

    rewind(file);
    points = (Point *)realloc(points, N * sizeof(Point));
    fread(points, N, sizeof(Point), file);

    print_points(points, N);
    printf("\n");
}

Point angle_point(Angle angle)
{
    Point point;
    point.x = cos(angle);
    point.y = sin(angle);
    return point;
}

Point *angles_points(Angle *angles, int divisions)
{
    Point *points = (Point *)malloc(divisions * (sizeof(Point)));
    int i;
    for (i = 0; i < divisions; i++)
    {
        points[i] = angle_point(angles[i]);
    }
    return points;
}

Angle *divisions_angles(int divisions)
{
    Angle *angles = (Angle *)malloc(divisions * (sizeof(Angle)));
    int i;
    Angle sum = ((2 * M_PI) / (divisions - 1));
    angles[0] = 0.;
    for (i = 1; i < divisions; i++)
    {
        angles[i] = angles[i - 1] + sum;
    }
    return angles;
}

void print_points(Point *points, int divisions)
{
    if (divisions)
    {
        printf("(%.3lf, %.3lf) ", points->x, points->y);
        print_points(points + 1, divisions - 1);
    }
    return;
}
