NAME = pipex

NAME2 = srcs/pipex_bonus

LIBFT = libft.a

LIBFTD = ./lib/libft/

PIP = libpip.a

PIPD = ./lib/

GNLD = ./lib/GNL/

SRCD = ./srcs/

COMPILE = gcc

CFLAGS = -Wall -Wextra -Werror



SRC =	$(GNLD)get_next_line.c \
		$(GNLD)get_next_line_utils.c \
		$(SRCD)reader.c \
		$(SRCD)ft_split2.c \
		$(SRCD)stopper.c \
		$(SRCD)forker.c \
		$(SRCD)executeur.c \
		$(SRCD)piper.c \
		$(SRCD)checker_fd.c

SRCBONUS =	$(GNLD)get_next_line.c \
			$(GNLD)get_next_line_utils.c \
			$(SRCD)reader.c \
			$(SRCD)ft_split2.c \
			$(SRCD)stopper.c \
			$(SRCD)forker.c \
			$(SRCD)executeur.c \
			$(SRCD)piper.c \
			$(SRCD)checker_fd.c \
			$(SRCD)main_bonus.c \
			$(SRCD)reader_bonus.c \
			$(SRCD)stopper_bonus.c \
			$(SRCD)piper_bonus.c \
			$(SRCD)here_doc_bonus.c \
			$(SRCD)checker_fd_bonus.c


OBJ = $(SRC:%.c=%.o)

OBJ2 = $(SRCBONUS:%.c=%.o)

%.o: %.c
	$(COMPILE) $(CFLAGS) -c $< -o $@

all:	$(NAME)

bonus:	$(NAME2)

$(NAME) :	$(OBJ) $(SRCD)/main.c
			$(RM) $(NAME)
			make -C $(LIBFTD)
			cp $(LIBFTD)$(LIBFT) $(PIPD)$(PIP)
			ar rc $(PIPD)$(PIP) $(OBJ)
			/bin/rm -f $(LIBFT)
			ranlib $(PIPD)$(PIP)
			$(COMPILE) -o $(NAME) $(SRCD)/main.c  $(PIPD)$(PIP)

$(NAME2) :	$(OBJ2) $(SRCD)/main2_bonus.c
			$(RM) $(NAME)
			$(RM) $(NAME2)
			make -C $(LIBFTD)
			cp $(LIBFTD)$(LIBFT) $(PIPD)$(PIP)
			ar rc $(PIPD)$(PIP) $(OBJ2)
			/bin/rm -f $(LIBFT)
			ranlib $(PIPD)$(PIP)
			$(COMPILE) -o $(NAME2) $(SRCD)/main2_bonus.c  $(PIPD)$(PIP)
			cp $(NAME2) ./$(NAME)

clean:
	$(RM) $(wildcard $(OBJ))
	$(RM) $(wildcard $(OBJ2))
	make clean -C $(LIBFTD)
	$(RM) $(NAME2)

fclean: clean
	$(RM) $(NAME)
	$(RM) $(NAME2)
	$(RM) $(LIBFTD)$(LIBFT)
	$(RM) $(PIPD)$(PIP)
	make fclean -C $(LIBFTD)

re: fclean all

.PHONY: clean fclean all re bonus
