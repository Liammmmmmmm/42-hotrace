#include "hashmap.h"
#include <stdio.h>

int main()
{
	hashmap_t hashmap;

	if (init_hashmap(&hashmap) == -1)
	{
		printf("Error\n");
		return (1);
	}

	printf("test %u\n", hashmap.rows[0].index1);
	printf("test %u\n", hashmap.rows[0].index2);
	printf("test %u\n", hashmap.rows[0].index3);
	printf("test %u\n", hashmap.rows[0].index4);
	printf("test %u\n", hashmap.rows[0].index5);
	printf("test %u\n", hashmap.rows[0].index6);
	printf("test %u\n", hashmap.rows[0].index7);
	printf("test %u\n", hashmap.rows[0].index8);
	printf("test %u\n", hashmap.rows[0].index9);
	printf("test %u\n", hashmap.rows[0].index10);
	printf("test %u\n", hashmap.rows[0].index11);
	printf("test %u\n", hashmap.rows[0].index12);
	printf("test %u\n", hashmap.rows[0].index13);
	printf("test %u\n", hashmap.rows[0].index14);
	printf("test %u\n", hashmap.rows[0].index15);
	printf("test %u\n", hashmap.rows[0].index16);

	// t_pos pos;

	// pos.index = 2097151;
	// pos.tab = 2047;
	// printf("Test: %u %u %u\n", pos.condensed, pos.tab, pos.index);
}