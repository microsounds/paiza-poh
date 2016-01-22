/* Paiza Online Hackathon Vol. 5 */
/* https://paiza.jp/poh/enshura */
/* Mission 02 */
/* Given the list:
 * n   // number of items in the list, multiple of 7
 * s_1 // sales figures starting from 1 to n
 * s_2
 * s_3
 * ...
 * s_n
 * Calculate sales figures for every day of the week.
 */

#include <stdio.h>
#define DAYS 	7

int main(void)
{
	unsigned n;
	fscanf(stdin, "%u", &n);
	unsigned day[DAYS] = { 0 };
	unsigned i, j;
	for (i = 0; i < n; i++)
	{
		unsigned current;
		fscanf(stdin, "%u", &current);
		day[i % DAYS] += current;
	}
	for (i = 0; i < DAYS; i++)
	{
		printf("%u\n", day[i]);
	}
	return 0;
}
