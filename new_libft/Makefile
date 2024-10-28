# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lemarian <lemarian@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/12 14:28:29 by lemarian          #+#    #+#              #
#    Updated: 2024/09/12 16:00:45 by lemarian         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

CFLAGS = -Wall -Werror -Wextra -g

NAME = libft.a

SRCS = ft_isascii.c ft_memcpy.c ft_putstr_fd.c ft_strlcat.c \
ft_strrchr.c ft_atoi.c ft_isdigit.c ft_memmove.c ft_split.c \
ft_strlcpy.c ft_strtrim.c ft_bzero.c ft_isprint.c ft_memset.c \
ft_strchr.c ft_strlen.c ft_substr.c ft_calloc.c ft_itoa.c \
ft_putchar_fd.c ft_strdup.c ft_strmapi.c ft_tolower.c ft_isalnum.c \
ft_memchr.c ft_putendl_fd.c ft_striteri.c ft_strncmp.c ft_toupper.c \
ft_isalpha.c ft_memcmp.c ft_putnbr_fd.c ft_strjoin.c ft_strnstr.c \
ft_printf.c print_address.c print_char.c print_hexa.c print_nb.c \
print_str.c print_unsigned.c get_next_line.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
