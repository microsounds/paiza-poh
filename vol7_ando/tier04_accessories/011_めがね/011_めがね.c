/* Paiza Online Hackathon Vol. 7 */
/* https://paiza.jp/poh/ando */
/* Tier 04: Accessories */
/* Challenge 11 */
/* めがね */
/* paizaランクB相当問題 */
/* Take a grid pattern and a sub-pattern.
 * Locate the sub-pattern within the larger grid pattern and
 * print the upper-leftmost x y coordinate of where it occurs.
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct {
	unsigned x;
	unsigned y;
} point_t;

typedef struct {
	unsigned **grid;
	point_t size;
} grid_t;

grid_t *create_grid(unsigned x, unsigned y)
{
	/* create 2D grid */
	grid_t *ptr = (grid_t *) malloc(sizeof(grid_t));
	ptr->grid = (unsigned **) malloc(sizeof(unsigned *) * x);
	unsigned i;
	for (i = 0; i < x; i++)
		ptr->grid[i] = (unsigned *) malloc(sizeof(unsigned) * y);
	ptr->size.x = x;
	ptr->size.y = y;
	return ptr;
}

void destroy_grid(grid_t *ptr)
{
	unsigned i;
	for (i = 0; i < ptr->size.x; i++)
		free(ptr->grid[i]);
	free(ptr->grid);
	free(ptr);
}

void display_grid(grid_t *ptr)
{
	/* great for debugging */
	unsigned i, j;
	for (i = 0; i < ptr->size.x; i++)
	{
		for (j = 0; j < ptr->size.y; j++)
		{
			printf("%u", ptr->grid[i][j]);
			if (j != ptr->size.y - 1)
				printf("%c", ' ');
		}
		printf("%c", '\n');
	}
}

void fill_grid(grid_t *ptr)
{
	unsigned i, j;
	for (i = 0; i < ptr->size.x; i++)
	{
		for (j = 0; j < ptr->size.y; j++)
		{
			fscanf(stdin, "%u", &ptr->grid[i][j]);
		}
	}
}

unsigned search_subgrid(grid_t *pattern, grid_t *subpattern, point_t from)
{
	/* simultaneously compare subpattern and pattern using offset value */
	unsigned matches = 0;
	unsigned k, l;
	for (k = 0; k < subpattern->size.x; k++)
	{
		for (l = 0; l < subpattern->size.y; l++)
		{
			if (pattern->grid[from.x + k][from.y + l] == subpattern->grid[k][l])
				matches++;
		}
	}
	return matches;
}

void search_grid(grid_t *pattern, grid_t *subpattern)
{
	/* print x y coordinates of first match */
	unsigned FULL_MATCH = subpattern->size.x * subpattern->size.y;
	unsigned i, j;
	for (i = 0; i < pattern->size.x; i++)
	{
		for (j = 0; j < pattern->size.y; j++)
		{
			if (pattern->size.x - i < subpattern->size.x ||
			    pattern->size.y - j < subpattern->size.y) /* bounds checking */
				break;
			else
			{
				point_t from = { i, j }; /* offset */
				if (search_subgrid(pattern, subpattern, from) == FULL_MATCH)
				{
					printf("%u %u\n", from.x, from.y);
					return;
				}
			}
		}
	}
}

int main(void)
{
	unsigned N; /* pattern */
	fscanf(stdin, "%u", &N);
	grid_t *pattern = create_grid(N, N);
	fill_grid(pattern);

	unsigned M; /* subpattern */
	fscanf(stdin, "%u", &M);
	grid_t *subpattern = create_grid(M, M);
	fill_grid(subpattern);

	search_grid(pattern, subpattern);

	destroy_grid(pattern);
	destroy_grid(subpattern);
	return 0;
}
