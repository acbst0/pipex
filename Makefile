NAME		= pipex

FILES	= forpipe.c \
			utils/ft_split.c \
			utils/ft_strdup.c \
			utils/ft_strjoin.c \
			utils/ft_strlcpy.c \
			utils/ft_strlen.c \
			utils/ft_substr.c \
			utils/ft_strnstr.c \

OBJS	= $(FILES:.c=.o)

CC	= gcc

RM	=	rm -f

MAIN	= pipex.c

CFLAGS	= -Wall -Werror -Wextra

${NAME}: ${OBJS}
	@$(CC) ${MAIN} ${FILES} ${CFLAGS} -o ${NAME}

all: $(NAME)

clean:
	${RM} $(OBJS)

fclean: clean
	${RM} $(NAME) 

re: fclean all

.PHONY: all, clean, fclean, re