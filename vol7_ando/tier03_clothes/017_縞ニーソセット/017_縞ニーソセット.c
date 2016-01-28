/* Paiza Online Hackathon Vol. 7 */
/* https://paiza.jp/poh/ando */
/* Tier 03: Clothes */
/* Challenge 17 */
/* 縞ニーソセット */
/* paizaランクC相当問題 */
/* Given the values:
 * N // length of stripe
 * M // length of pattern
 * n = 3, m = 10 should produce:
 * RRRWWWRRRW
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *make_str(int m)
{
	char *str = (char *) calloc(m + 1, sizeof(char));
	unsigned i;
	for (i = 0; i < m; i++)
	{
		str[i] = 'W';
	}
	str[i] = '\0'; /* null terminate */
	return str;
}

void draw_stripes(int n, char *str)
{
	int len = strlen(str);
	unsigned draw = 1; /* boolean */
	unsigned toggle = 0;
	unsigned i;
	for (i = 0; i < len; i++)
	{
		if (toggle == n)
		{
			draw = !draw;
			toggle = 0;
		}
		toggle++;
		if (draw)
			str[i] = 'R';
		else
			continue;
	}
}

int main(void)
{
	int n, m;
	fscanf(stdin, "%d\n%d", &n, &m);
	char *str = make_str(m);
	draw_stripes(n, str);
	printf("%s\n", str);
	free(str);
	return 0;
}
