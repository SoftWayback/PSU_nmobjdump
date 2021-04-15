/*
** EPITECH PROJECT, 2021
** B-PSU-400-NCY-4-1-nmobjdump-yann.julitte [WSL: Ubuntu-20.04]
** File description:
** main
*/

#include <stdio.h>
#include "include.h"
#include "flags.h"

int main(int argc, char **argv)
{
	int status;
	int i;

	if (argc <= 2)
		return (file_parser(argc == 1 ? "a.out" : argv[1]));
	status = 0;
	i = 1;
	while (argc-- > 1)
	{
		printf("\n%s:\n", argv[i]);
		if (file_parser(argv[i++]) == 84)
			status = 84;
	}
	return status;
}
