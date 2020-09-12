#include "get_next_line.h"
int main()
{
	char *line;
	int status = 1;

	while (status != 0)
	{
		status = get_next_line(42, &line);
		printf("line = %s\n", line);
		printf("status = %d\n", status);
	}
}