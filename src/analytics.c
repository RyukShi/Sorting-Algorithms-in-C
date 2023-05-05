#include "./analytics.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

FILE	*open_file(char *fname)
{
	FILE	*fptr;

	fptr = fopen(fname, "a");
	if (fptr == NULL)
	{
		fprintf(stderr, "Error: could not open file.\n");
		exit(1);
	}
	return (fptr);
}

void	close_file(FILE *fptr)
{
	fclose(fptr);
}

clock_t	start_timer(void)
{
	return (clock());
}

double	get_execution_time(clock_t t1)
{
	clock_t	t2;

	t2 = clock();
	return (((double)t2 - t1) / CLOCKS_PER_SEC);
}

void	write_in_file(FILE *fptr, double time_taken, char *algorithm,
		unsigned int size)
{
	fprintf(fptr, "%f,%s,%u\n", time_taken, algorithm, size);
}
