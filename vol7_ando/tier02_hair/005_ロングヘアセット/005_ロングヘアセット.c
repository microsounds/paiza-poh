/* Paiza Online Hackathon Vol. 7 */
/* https://paiza.jp/poh/ando */
/* Tier 02: Hair */
/* Challenge 5 */
/* ロングヘアセット */
/* paizaランクD相当問題 */
/* Count the number of "yes" or "no" votes in a list
 * Determine the one with the most votes.
 */

#include <stdio.h>

int main(void)
{
	unsigned yes_ct = 0;
	unsigned no_ct = 0;
	char buf[100] = { 0 };
	while (fscanf(stdin, "%s", buf))
	{
		if (feof(stdin))
			break;

		if (buf[0] == 'y')
			yes_ct++;
		else
			no_ct++;
	}
	printf("%s\n", (yes_ct > no_ct) ? "yes" : "no");
	return 0;
}
