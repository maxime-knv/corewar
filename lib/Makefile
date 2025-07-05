##
## EPITECH PROJECT, 2025
## corewar
## File description:
## Makefile
##

SRC =	d_putchar.c \
		d_putstr.c \
		stringlen.c \
		convert_base.c \
		hexa_base.c \
		revstr.c \
		strcmpare.c \
		d_putnbr.c \
		d_ptr.c \
		d_mini_printf.c \
		memoryset.c	\
		charisalpha.c \
		stringdup.c \
		stringcpy.c \
		free_array.c \
		print_array.c \
		getnumber.c \

OBJ = $(SRC:.c=.o)

CFLAGS += -Wall -Wextra

NAMELIB = libmy.a

all:	$(NAMELIB)

$(NAMELIB):	$(OBJ)
	$(AR) rc $(NAMELIB) $(OBJ)

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(NAMELIB)

re:	fclean all

.PHONY: all clean fclean re
