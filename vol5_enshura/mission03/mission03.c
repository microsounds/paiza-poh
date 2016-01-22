/* Paiza Online Hackathon Vol. 5 */
/* https://paiza.jp/poh/enshura */
/* Mission 03 */
/* Output the string "MINAMI" or "RENA" */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
	time_t t; /* eheh~ */
	srand((unsigned) time(&t));
	printf("%s\n", (rand() % 2) ? "MINAMI" : "RENA");
	return 0;
}
