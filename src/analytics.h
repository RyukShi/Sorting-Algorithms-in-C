#ifndef ANALYTICS_H
#define ANALYTICS_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

extern FILE		*open_file(char *fname);
extern void		close_file(FILE *fptr);
extern void		write_in_file(FILE *fptr, double time_taken);

extern clock_t	start_timer(void);
extern double	get_execution_time(clock_t t1);

#endif /* ANALYTICS_H */
