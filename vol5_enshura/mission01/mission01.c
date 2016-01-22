/* Paiza Online Hackathon Vol. 5 */
/* https://paiza.jp/poh/enshura */
/* Mission 01 */
/* Decipher stdin by printing every odd char */

#include <stdio.h>

int main(void)
{
	char buf[1000];
	fscanf(stdin, "%[^\n]\n", &buf);
	unsigned i;
	for (i = 0; buf[i]; i++)
	{
		if (i % 2)
			continue;
		else
			printf("%c", buf[i]);
	}
	printf("%c", '\n');
	return 0;
}
