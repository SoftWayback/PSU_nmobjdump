##
## EPITECH PROJECT, 2021
## B-PSU-400-NCY-4-1-nmobjdump-yann.julitte
## File description:
## Makefile
##


NAMENM	=	my_nm
NAMEOBJ	=	my_objdump

DIRNM	=	nm
DIROBJ	=	obj

SRCSNM	=	$(DIRNM)/src/main.c		\
			$(DIRNM)/src/parser.c 	\
			$(DIRNM)/src/table.c \
			$(DIRNM)/src/symbol.c

SRCSOBJ	=	$(DIROBJ)/src/main.c		\
			$(DIROBJ)/src/parser.c \
			$(DIROBJ)/src/table.c \
			$(DIROBJ)/src/symbol.c

CFLAGSNM	+=	-W -Wall -Wextra 
CFLAGSNM	+=	-I nm/include

CFLAGS	+=	-W -Wall -Wextra 
CFLAGS	+=	-I obj/include
CC	=	gcc

RM	=	rm -f

OBJSNM	=	$(SRCSNM:.c=.o)
OBJSOBJ	=	$(SRCSOBJ:.c=.o)

%.o: %.c
		@printf "[\033[0;32mcompiled\033[0m] % 29s\n" $< | tr ' ' '.'
		@$(CC) -c -o $@ $< $(CFLAGSNM) $(LDFLAGS)

%.u: %.c
		@printf "[\033[0;32mcompiled\033[0m] % 29s\n" $< | tr ' ' '.'
		@$(CC) -c -o $@ $< $(CFLAGSOBJ) $(LDFLAGS)

all:		nm objdump

nm:		$(NAMENM)

objdump:	$(NAMEOBJ);

$(NAMENM):	$(OBJSNM)
		@$(CC) $(OBJSNM) -o $(NAMENM) $(LDFLAGS)
		@printf "[\033[0;36mbuilt\033[0m] % 32s\n" $(NAMENM) | tr ' ' '.'

$(NAMEOBJ):	$(OBJSOBJ)
		@$(CC) $(OBJSOBJ) -u $(NAMEOBJ) $(LDFLAGS)
		@printf "[\033[0;36mbuilt\033[0m] % 32s\n" $(NAMEOBJ) | tr ' ' '.'

clean:
		@$(RM) $(OBJSNM)
		@printf "[\033[0;31mdeleted\033[0m] % 30s\n" $(OBJSNM) | tr ' ' '.'
		@$(RM) $(OBJSOBJ)
		@printf "[\033[0;31mdeleted\033[0m] % 30s\n" $(OBJSOBJ) | tr ' ' '.'

fclean:		clean
		@$(RM) $(NAMENM)
		@printf "[\033[0;31mdeleted\033[0m] % 30s\n" $(NAMENM) | tr ' ' '.'
		@$(RM) $(NAMEOBJ)
		@printf "[\033[0;31mdeleted\033[0m] % 30s\n" $(NAMEOBJ) | tr ' ' '.'

re:		fclean all

.PHONY:		all clean fclean re