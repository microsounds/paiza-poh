/* Paiza Online Hackathon Vol. 7 */
/* https://paiza.jp/poh/ando */
/* Tier 01: Eyes */
/* No. 1 */
/* つり目セット */
/* paizaランクD相当問題 */
/* take N from stdin, print "Ann" N times */

#include <stdio.h>

int main(void)
{
	unsigned iters;
	fscanf(stdin, "%u", &iters);
	unsigned i;
	for (i = 0; i < iters; i++)
	{
		printf("Ann");
	}
	printf("%c", '\n');
	return 0;
}
