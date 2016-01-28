/* Paiza Online Hackathon Vol. 7 */
/* https://paiza.jp/poh/ando */
/* Tier 03: Clothes */
/* Challenge 10 */
/* カーディガンセット */
/* paizaランクD相当問題 */
/* Output the factorial of N */

#include <stdio.h>

int factorial(int n)
{
	int product = n;
	while (n-- > 1)
	{
		product *= n;
	}
	return product;
}

int main(void)
{
	int n = 3;
	fscanf(stdin, "%d", &n);
	printf("%d\n", factorial(n));
	return 0;
}
