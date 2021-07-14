NAME = pipex

LIBFT = libft.a

LIBFTD = ./lib/libft/

PIP = libpip.a

PIPD = ./lib/

SRCD = ./srcs/

COMPILE = gcc

CFLAGS = -Wall -Wextra -Werror

SRC =	$(SRCD)reader.c \
		$(SRCD)ft_split2.c

OBJ = $(SRC:.c=.o)

%.o: %.c
	$(COMPILE) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME) : $(OBJ) $(SRCD)/main.c
		rm -rf $(NAME)
		make -C $(LIBFTD)
		cp $(LIBFTD)$(LIBFT) $(PIPD)$(PIP)
		ar rc $(PIPD)$(PIP) $(OBJ)
		/bin/rm -f $(LIBFT)
		ranlib $(PIPD)$(PIP)
		$(COMPILE) -o $(NAME) $(SRCD)/main.c  $(PIPD)$(PIP) -I$(INCL)

clean:
	rm -rf $(OBJ)
	rm -rf objects
	make clean -C $(LIBFTD)

fclean: clean
	rm -rf $(NAME)
	rm -rf $(LIBFTD)$(LIBFT)
	rm -rf $(PIPD)$(PIP)
	make fclean -C $(LIBFTD)

re: fclean all

.PHONY: clean fclean all re
