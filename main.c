#include "get_next_line.h"
#include "test_get_next_line_bonus.h"

int test_compare(char *str_1, char *str_2)
{
	while (*str_1 || *str_2)
	{
		if (*str_1++ != *str_2++)
			return (0);
	}
	return (1);
}

int mini_atoi(char *str)
{
	int rst = 0;

	while (*str)
		rst = (rst * 10) + *str++ - 48;
	return rst;
}

int main(int ac, char **av)
{
	
	// int status = 0;
	// char *line;
	// int statust = 0;
	// char *linet;
	// int i = 0;
	// int j = 0;
	// int compare = 0;
	// int iterations = mini_atoi(av[1]);
	// int id_tag = 0;

	// int fd_list[12];
	// char name_list[12][100] = {"test", "test_t", "test_vide", "test_vide_t", "test_lignes_vides", "test_lignes_vides_t",
	//  "test_continu", "test_continu_t", "test_ligne_7+1", "test_ligne_7+1_t", "test_ligne_8+1", "test_ligne_8+1_t"};

	// while (i < 12)
	// {
	// 	fd_list[i] = open(name_list[i], O_RDONLY);
	// 	i++;
	// }

	// i = 0;

	// int verbose = 0;

	// if (ac > 2)
	// {
	// 	printf("VERBOSE\n");
	// 	verbose = 1;
	// 	printf("\n");

	// }

	// compare = 0;
	// while (i++ < iterations)
	// {
	// 	j = 0;
	// 	while (j < 12)
	// 	{
	// 		status = get_next_line(fd_list[j], &line);
	// 		statust = test_get_next_line(fd_list[j + 1], &linet);
	// 		compare = test_compare(line, linet);
	// 		if (!compare || status != statust || verbose == 1)
	// 		{
	// 			if (id_tag == 0)
	// 			{
	// 				printf("FOPEN_MAX = %d\n", FOPEN_MAX);
	// 				printf("BUFFER_SIZE = %d\n", BUFFER_SIZE);
	// 				printf("iterations = %d\n", iterations);
	// 				printf("\n");
	// 				id_tag = 1;
	// 			}
	// 			printf("%s vs %s : line nr. %d", name_list[j], name_list[j + 1], i);
	// 			if (status != statust)
	// 				printf("\t>>> return value error : %d (test) vs. %d (reference)", status, statust);
	// 			if (!compare)
	// 				printf("\t>>> different line error");
	// 			printf("\n");
	// 			printf("fd 0 - test\n line = '%s'\n status = %d\n", line, status);
	// 			printf("fd 0t - reference test\n line = '%s'\n status = %d\n", linet, statust);
	// 			printf("\n");
	// 		}
	// 		free(line);
	// 		free(linet);
	// 		j = j + 2;
	// 	}
	// }
}