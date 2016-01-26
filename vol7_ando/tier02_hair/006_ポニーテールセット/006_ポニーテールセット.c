/* Paiza Online Hackathon Vol. 7 */
/* https://paiza.jp/poh/ando */
/* Tier 02: Hair */
/* Challenge 6 */
/* ポニーテールセット */
/* paizaランクD相当問題 */
/* Count down from N to 0!!
 */

#include <stdio.h>

int main(void)
{
	int n;
	fscanf(stdin, "%d", &n);
	do
	{
		printf("%d", n);
		if (n == 0)
			printf("%s", "!!");
		printf("%c", '\n');
	} while (n-- > 0);
	return 0;
}
