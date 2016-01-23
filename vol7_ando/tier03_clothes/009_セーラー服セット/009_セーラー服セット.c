/* Paiza Online Hackathon Vol. 7 */
/* https://paiza.jp/poh/ando */
/* Tier 03: Clothes */
/* Challenge 9 */
/* セーラー服セット */
/* paizaランクD相当問題 */
/* Take the following input:
 * N
 * str0
 * str1
 * ...
 * strN
 * Output as "str1_str2_strN"
 */

#include <stdio.h>

int main(void)
{
	unsigned n;
	fscanf(stdin, "%u", &n);
	unsigned i;
	for (i = 0; i < n; i++)
	{
		char buf[1000];
		fscanf(stdin, "%s", &buf);
		printf("%s", buf);
		if (i != n - 1)
			printf("%c", '_');
	}
	printf("%c", '\n');
	return 0;
}
