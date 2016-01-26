/* Paiza Online Hackathon Vol. 7 */
/* https://paiza.jp/poh/ando */
/* Tier 02: Hair */
/* Challenge 4 */
/* ショートヘアセット */
/* paizaランクD相当問題 */
/* Add 2 numbers.
 */

#include <stdio.h>
#include <string.h>

int main(void)
{
	int sum = 0;
	int n;
	while (fscanf(stdin, "%d", &n))
	{
		if (feof(stdin))
			break;
		sum += n;
	}
	printf("%d\n", sum);
	return 0;
}
