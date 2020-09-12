#include "get_next_line.h"
int main()
{
	char *line;
	int status = 1;

	printf("FOPEN_MAX = %d\n", MAX_FD);

	while (status != 0 && status != -1)
	{
		status = get_next_line(42, &line);
		printf("line = %s\n", line);
		printf("status = %d\n", status);
		free (line);
	}
}