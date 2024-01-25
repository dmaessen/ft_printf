NAME = libftprintf.a

SRC = ft_printf.c ft_putchar.c ft_puthexa.c ft_putnbr.c ft_putstr.c ft_utoa.c ft_putptr.c ft_putpercentage.c ft_itoa.c \

OBJS = $(SRC:.c=.o)

AR = ar rcs
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o ${<:.c=.o}

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all