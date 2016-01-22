/* Paiza Online Hackathon Vol. 5 */
/* https://paiza.jp/poh/enshura */
/* Mission 04 -- Minami's Route */
/* Given an x * y grid, advance gameplay and simulate gravity in a tetris clone */
/* 0 is empty space, 1 is inert bomb, 2 is ignited bomb */

#include <stdio.h>
#include <stdlib.h>

typedef enum {
	EMPTY = 0,
	BOMB = 1,
	IGNITED = 2
} state_t;

void swap(unsigned *a, unsigned *b)
{
	register unsigned tmp = *a;
	*a = *b;
	*b = tmp;
}

int compare(unsigned a, unsigned b)
{
	return (int) a - b;
}

int is_sorted(unsigned *arr, unsigned size)
{
	int sorted = 1;
	unsigned i;
	for (i = 0; i < size - 1; i++)
	{
		int state = compare(arr[i], arr[i+1]);
		if (state > 0)
			return 0;
	}
	return sorted;
}

void bubblesort(unsigned *arr, unsigned size)
{
	while (!is_sorted(arr, size))
	{
		unsigned i; /* --> */
		for (i = 0; i < size - 1; i++)
		{
			int state = compare(arr[i], arr[i+1]);
			if (state > 0)
				swap(arr+i, arr+i+1);
			else
				continue;
		}
	}
}

state_t **create_grid(unsigned x, unsigned y)
{
	unsigned i;
	state_t **grid = (state_t **) malloc(sizeof(state_t *) * x);
	for (i = 0; i < x; i++)
		grid[i] = (state_t *) malloc(sizeof(state_t) * y);
	return grid;
}

void fill_grid(state_t **grid, unsigned x, unsigned y)
{
	/* stdin is global, right? */
	unsigned i, j;
	for (i = 0; i < x; i++)
	{
		for (j = 0; j < y; j++)
		{
			fscanf(stdin, "%d ", &grid[i][j]);
		}
	}
}

void destroy_grid(state_t **grid, unsigned x, unsigned y)
{
	unsigned i;
	for (i = 0; i < x; i++)
		free(grid[i]);
	free(grid);
}

void display_grid(state_t **grid, unsigned x, unsigned y)
{
	unsigned i, j;
	for (i = 0; i < x; i++)
	{
		for (j = 0; j < y; j++)
		{
			printf("%d", grid[i][j]);
			if (j != y - 1)
				printf(" ");
		}
		printf("%c", '\n');
	}
}

void clear_bombs(state_t **grid, unsigned x, unsigned y)
{
	unsigned i, j;
	for (i = 0; i < x; i++)
	{
		for (j = 0; j < y; j++)
		{
			if (grid[i][j] == IGNITED)
				grid[i][j] = EMPTY;
		}
	}
}

void simulate_gravity(state_t **grid, unsigned x, unsigned y)
{
	/* simulate gravity by sorting every downward column */
	unsigned i, j;
	for (i = 0; i < y; i++)
	{
		unsigned tmp[x]; /* copy to tmp array and sort */
		for (j = 0; j < x; j++)
			tmp[j] = grid[j][i];
		bubblesort(tmp, x);
		for (j = 0; j < x; j++)
			grid[j][i] = tmp[j]; /* commit back to array */
	}
}

int main(void)
{
	unsigned x, y;
	fscanf(stdin, "%u %u", &x, &y);
	swap(&x, &y); /* their definition of x is "columns", not "rows" */
	state_t **grid = create_grid(x, y);
	fill_grid(grid, x, y);
	clear_bombs(grid, x, y);
	simulate_gravity(grid, x, y);
	display_grid(grid, x, y);
	destroy_grid(grid, x, y);
	return 0;
}
