#include <stdbool.h>
#include <stdio.h>
#include "sandpiles.h"

/**
 * print_grid - Prints a 3x3 sandpile grid
 * @grid: The grid to print
 */
static void print_grid(int grid[3][3])
{
    int i, j;

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            if (j)
                printf(" ");
            printf("%d", grid[i][j]);
        }
        printf("\n");
    }
}

/**
 * is_stable - Checks if the sandpile is stable
 * @grid: The sandpile to check
 *
 * Return: true if stable, false otherwise
 */
static bool is_stable(int grid[3][3])
{
    int i, j;

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            if (grid[i][j] > 3)
                return false;
        }
    }
    return true;
}

/**
 * topple - Topples the sandpile
 * @grid: The sandpile to topple
 */
static void topple(int grid[3][3])
{
    int i, j;
    int temp[3][3];

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            temp[i][j] = grid[i][j];
            if (grid[i][j] > 3)
            {
                temp[i][j] -= 4;
                if (i > 0)
                    temp[i - 1][j]++;
                if (i < 2)
                    temp[i + 1][j]++;
                if (j > 0)
                    temp[i][j - 1]++;
                if (j < 2)
                    temp[i][j + 1]++;
            }
        }
    }

    for (i = 0; i < 3; i++)
        for (j = 0; j < 3; j++)
            grid[i][j] = temp[i][j];
}

/**
 * sandpiles_sum - Computes the sum of two sandpiles
 * @grid1: The first sandpile
 * @grid2: The second sandpile
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
    int i, j;

    for (i = 0; i < 3; i++)
        for (j = 0; j < 3; j++)
            grid1[i][j] += grid2[i][j];

    while (!is_stable(grid1))
    {
        printf("=\n");
        print_grid(grid1);
        topple(grid1);
    }
}
