/* Paiza Online Hackathon Vol. 7 */
/* https://paiza.jp/poh/ando */
/* Tier 02: Hair */
/* Challenge 7 */
/* ツインテールセット */
/* paizaランクD相当問題 */
/* Determine the most cost-effective of 2 energy drinks.
 * Cost-effective = more caffeine per 円.
 * Input is in the form:
 * c_1 p_1 // mg caffeine, price in JPY
 * c_2 p_2
 */

#include <stdio.h>

int main(void)
{
	int c1, p1;
	fscanf(stdin, "%d %d", &c1, &p1);
	int c2, p2;
	fscanf(stdin, "%d %d", &c2, &p2);

	double rat1 = (double) c1 / p1;
	double rat2 = (double) c2 / p2;

	printf("%c\n", (rat1 > rat2) ? '1' : '2');
	return 0;
}
