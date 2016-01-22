/* Paiza Online Hackathon Vol. 7 */
/* https://paiza.jp/poh/ando */
/* Tier 01: Eyes */
/* No. 2 */
/* 眼帯 */
/* paizaランクC相当問題 */
/* Take a list containing the book volume numbers:
 * N                // # of total published volumes
 * M1               // # of volumes you own
 * x_1 x_2 ... x_M1 // list of volume #'s of books you own
 * M2               // # of volumes in used book stores
 * y_1 y_2 ... y_M2 // list of volume #'s of books in used book stores
 * Determine the volumes you don't have which are available used.
 * Print "None" if you already have them all.
 */

#include <stdio.h>

int main(void)
{
	unsigned i;
	unsigned N;
	fscanf(stdin, "%u", &N);
	unsigned M1; /* get M1 values */
	fscanf(stdin, "%u", &M1);
	unsigned owned[M1];
	for (i = 0; i < M1; i++)
		fscanf(stdin, "%u ", &owned[i]);
	unsigned M2; /* get M2 values */
	fscanf(stdin, "%u", &M2);
	unsigned available[M2];
	for (i = 0; i < M2; i++)
		fscanf(stdin, "%u ", &available[i]);
	unsigned found = 0; /* bolt */
	for (i = 1; i <= N; i++) /* determine availability */
	{
		unsigned exists = 0;
		unsigned j;
		for (j = 0; j < M2; j++)
		{
			if (available[j] == i)
				exists = 1;
		}
		for (j = 0; j < M1; j++)
		{
			if (owned[j] == i) /* undo */
				exists = 0;
		}
		if (exists)
		{
			if (!found) /* blow bolt */
				found = !found;

			printf("%u", i);
			if (i != N)
				printf(" ");
		}
	}
	if (!found)
		printf("%s", "None\n");
	else
		printf("%c", '\n');
	return 0;
}
