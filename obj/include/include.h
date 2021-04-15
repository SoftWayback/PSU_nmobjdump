/*
** EPITECH PROJECT, 2021
** B-PSU-400-NCY-4-1-nmobjdump-yann.julitte
** File description:
** include
*/

#ifndef INCLUDE_H_
#define INCLUDE_H_
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <elf.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <link.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/types.h>
#include <unistd.h>
#include <elf.h>
#include <error.h>
#include <errno.h>
#include <stdbool.h>
int main(int argc, char **argv);
int file_parser(char *filename);
void nm(void *buffer, struct stat *s);
int check_file_format(void *buffer, char *filename, struct stat *s);
char other_symbol(Elf64_Sym sym, Elf64_Shdr *shdr, char c);
char *find_symbol(Elf64_Sym sym, Elf64_Shdr *shdr);
#endif /* !INCLUDE_H_ */
