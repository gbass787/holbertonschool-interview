#include "sandpiles.h"


/**
 * print_grid - Print 3x3 grid
 * @grid: 3x3 grid
 *
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
* distribution - Distribute sandpiles
* @grid1: 3x3 grid
* @grid2: 3x3 grid
*/
void distribution(int grid1[3][3], int grid2[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			if (grid1[i][j] > 3)
			{
				if (i > 0)
					grid2[i - 1][j]++;
				if (i < 2)
					grid2[i + 1][j]++;
				if (j > 0)
					grid2[i][j - 1]++;
				if (j < 2)
					grid2[i][j + 1]++;

				grid1[i][j] -= 4;
			}

	sandpiles_sum(grid1, grid2);
}

/**
* is_stable - Check if sandpile is stable
* @grid: 3x3 grid
*
* Return: 0 if stable, -1 if not
*/
int is_stable(int grid[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			if (grid[i][j] > 3)
				return (-1);

	return (0);
}

/**
* sandpiles_sum - Compute the sum of two sandpiles
* @grid1: 3x3 grid
* @grid2: 3x3 grid
*/
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
		{
			grid1[i][j] += grid2[i][j];
			grid2[i][j] = 0;
		}

	while (is_stable(grid1) == -1)
	{
		printf("=\n");
		print_grid(grid1);
		distribution(grid1, grid2);
	}
}
