/*
** EPITECH PROJECT, 2021
** B-PSU-400-NCY-4-1-nmobjdump-yann.julitte
** File description:
** table
*/

#include "include.h"
#include "flags.h"


char *check_validate(unsigned int value)
{
    switch (value)
    {
    case STT_SECTION:
        return "BAD";
    case STT_FILE:
        return "FILE";
    default:
        return "<unknow>";
    }
}

void print_nm(Elf64_Sym *sym, Elf64_Shdr *symtab, Elf64_Shdr *strt, void *buf, Elf64_Shdr *shrd)
{
    char *str;

    sym = (Elf64_Sym *)(buf + symtab->sh_offset);
    str = (char *)(buf + strt->sh_offset);
    for (size_t i = 0; i < symtab->sh_size / symtab->sh_entsize; i++)
    {
        if (sym[i].st_name != 0 && strcmp(check_validate(sym[i].st_info), "BAD") != 0 && strcmp(check_validate(sym[i].st_info), "FILE") != 0)
         {
            if (sym[i].st_value != 0)
                printf("%016lx ", sym[i].st_value);
            else
                printf("%s ", "                ");
            printf("%s ", find_symbol(sym[i], shrd));
            printf("%s\n", str + sym[i].st_name);
        }
    }
}

void nm(void *buffer, struct stat *s)
{
    Elf64_Ehdr *elf = buffer;
    Elf64_Shdr *shdr = (Elf64_Shdr *)(buffer + elf->e_shoff);
    Elf64_Shdr *symtab;
    Elf64_Shdr *shstrtab;
    Elf64_Shdr *strtab;
    Elf64_Sym *sym;
    char *str = (char *)(buffer + shdr[elf->e_shstrndx].sh_offset);

    if (elf->e_shnum * shdr->sh_entsize + shdr->sh_offset > s->st_size)
        return 84;
    for (int i = 0; i < elf->e_shnum; i++)
        if (shdr[i].sh_size)
        {
            if (strcmp(&str[shdr[i].sh_name], ".symtab") == 0)
                symtab = (Elf64_Shdr *)&shdr[i];
            if (strcmp(&str[shdr[i].sh_name], ".shstrtab") == 0)
                shstrtab = (Elf64_Shdr *)&shdr[i];
            if (strcmp(&str[shdr[i].sh_name], ".strtab") == 0)
                strtab = (Elf64_Shdr *)&shdr[i];
        }
    sym = (Elf64_Sym *)(buffer + symtab->sh_offset);
    print_nm(sym, symtab, strtab, buffer, shdr);
}