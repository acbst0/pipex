NAME		= pipex

FILES	= pipex.c \
			forpipe.c \
			utils/ft_split.c \
			utils/ft_strdup.c \
			utils/ft_strjoin.c \
			utils/ft_strlcpy.c \
			utils/ft_strlen.c \
			utils/ft_substr.c \

CC	= gcc

CFLAGS	= -Wall -Werror -Wextra

OFILES	= $(FILES:.c=.o)

$(NAME):
	$(CC) $(CFLAGS) -c $(FILES) -o $(NAME)

all: $(NAME)

clean:
	rm -f $(OFILES)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re