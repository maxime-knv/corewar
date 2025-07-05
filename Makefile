##
## EPITECH PROJECT, 2025
## Makefile
## File description:
## Makfile
##

SRC =		$(addprefix src/, \
				$(addprefix cor_loop/, \
					corewar_loop.c	\
					)\
				$(addprefix error_handling/, \
					$(addprefix core_h/, \
						display_h.c \
					)\
					error_handling.c \
					check_files.c \
				)\
				$(addprefix files_actions/, \
					$(addprefix arena/, \
						set_arena.c \
						display_arena.c \
					)\
					$(addprefix fill_struct/,  \
						file_parsing.c \
						get_info_path_files.c \
						read_cor_files.c \
						is_specific_flag.c \
					)\
					browse_files_actions.c \
				)\
				$(addprefix free/, \
					free_utils.c \
				)\
				$(addprefix instructions/, \
					$(addprefix exec_ins/, \
						exec_zjump.c \
						exec_sti.c \
						exec_live.c \
						exec_ld.c  \
						exec_st.c \
						exec_add.c \
						exec_sub.c \
						exec_and.c \
						exec_or.c  \
						exec_xor.c \
						exec_ldi.c \
						exec_fork.c \
						exec_lld.c \
						exec_lldi.c \
						exec_lfork.c \
						exec_aff.c \
						exec_null.c \
					)\
				)\
				$(addprefix utils/, \
					read_codding_byte.c \
					check_cb.c \
					move_pc.c \
					get_pos.c \
					decompose_val.c \
					insert_to_map.c \
					compose_val.c \
					read_map.c \
				)\
				get_file_size.c \
				check_bin_file_errors.c \
				op.c\
				main.c \
			)


BON =		$(addprefix src/, \
				$(addprefix cor_loop/, \
					corewar_loop.c	\
					)\
				$(addprefix error_handling/, \
					$(addprefix core_h/, \
						display_h.c \
					)\
					error_handling.c \
					check_files.c \
				)\
				$(addprefix files_actions/, \
					$(addprefix arena/, \
						set_arena.c \
					)\
					$(addprefix fill_struct/,  \
						file_parsing.c \
						get_info_path_files.c \
						read_cor_files.c \
						is_specific_flag.c \
					)\
					browse_files_actions.c \
				)\
				$(addprefix free/, \
					free_utils.c \
				)\
				$(addprefix instructions/, \
					$(addprefix exec_ins/, \
						exec_zjump.c \
						exec_sti.c \
						exec_live.c \
						exec_ld.c  \
						exec_st.c \
						exec_add.c \
						exec_sub.c \
						exec_and.c \
						exec_or.c  \
						exec_xor.c \
						exec_ldi.c \
						exec_fork.c \
						exec_lld.c \
						exec_lldi.c \
						exec_lfork.c \
						exec_aff.c \
						exec_null.c \
					)\
				)\
				$(addprefix utils/, \
					read_codding_byte.c \
					check_cb.c \
					move_pc.c \
					get_pos.c \
					decompose_val.c \
					insert_to_map.c \
					compose_val.c \
					read_map.c \
				)\
				get_file_size.c \
				check_bin_file_errors.c \
				op.c\
				main.c \
			) \
			$(addprefix bonus_file/, \
				display_arena.c \
			)\

OBJ =		$(SRC:.c=.o)

BOBJ = 		$(BON:.c=.o)

NAME =		corewar

all:		$(NAME)

CC ?= gcc

CFLAGS +=	-Wall -Wextra

CPPFLAGS =	-iquoteinclude -iquotelib

LDFLAGS = 	-L ./lib/

LDLIB = 	-lmy -lm -lncurses

$(NAME):	$(OBJ)
	$(MAKE) -C ./lib
	$(CC) -o $(NAME) $(OBJ) $(LDFLAGS) $(LDLIB)

debug: CFLAGS += -g3
debug: fclean $(OBJ)
	make -C lib/ CFLAGS+=-g3
	$(CC) -o $(NAME) $(OBJ) $(LDFLAGS) $(LDLIB)

ncurses: CFLAGS += -g3
ncurses: fclean $(BOBJ)
	make -C lib/ CFLAGS+=-g3
	$(CC) -o $(NAME) $(BOBJ) $(LDFLAGS) $(LDLIB) -o corewar

clean:
	$(RM) $(OBJ)
	$(MAKE) -C ./lib clean

fclean:	clean
	$(RM) $(NAME)
	$(MAKE) -C ./lib fclean

re:	fclean all

.PHONY:	all clean fclean re debug
