/*
** EPITECH PROJECT, 2021
** B-PSU-400-NCY-4-1-nmobjdump-yann.julitte
** File description:
** parser
*/

#include "include.h"
#include "flags.h"
int check_file_format(void *buffer, char *filename, struct stat *s)
{
    Elf64_Ehdr *elf;
    elf = buffer;
    if (elf->e_ident[EI_MAG0] == 0x7f && elf->e_ident[EI_MAG1] == 'E' 
            && elf->e_ident[EI_MAG2] == 'L' && elf->e_ident[EI_MAG3] == 'F')
            nm(buffer, s);
    else {
            printf("nm: %s: file format not recognized\n", filename);
            return 84;
    }
    return 0;
}

int file_parser(char *filename)
{
    int fd;
    void *buf;
    struct stat s;
    fd = open(filename, O_RDONLY);
    if (fd != -1) {
        fstat(fd, &s);
        if (S_ISDIR(s.st_mode) == 1) {
            return 84;
        }
        buf = mmap(NULL, s.st_size, PROT_READ, MAP_PRIVATE, fd, 0);
        if (buf != NULL) {
            check_file_format(buf, filename, &s);
        } else {
            perror("mmap");
            return 84;
        }
        close(fd);
        return 0;
    } else {
        printf(" '%s' No such file\n", filename);
        return 84;
    }
}