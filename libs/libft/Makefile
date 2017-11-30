# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jonkim <jonkim@student.42.us.org>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/09 17:13:28 by jonkim            #+#    #+#              #
#    Updated: 2017/11/26 12:58:16 by jonkim           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = ft_memset.c     \
      ft_bzero.c      \
      ft_memcpy.c     \
      ft_memccpy.c    \
      ft_memmove.c    \
      ft_memchr.c     \
      ft_memcmp.c     \
      ft_strlen.c     \
      ft_strdup.c     \
      ft_strcpy.c     \
      ft_strncpy.c    \
      ft_strcat.c     \
      ft_strncat.c    \
      ft_strlcat.c    \
      ft_strchr.c     \
      ft_strrchr.c    \
      ft_strstr.c     \
      ft_strnstr.c    \
      ft_strcmp.c     \
      ft_strncmp.c    \
      ft_atoi.c       \
      ft_isalpha.c    \
      ft_isdigit.c    \
      ft_isalnum.c    \
      ft_isascii.c    \
      ft_isprint.c    \
      ft_toupper.c    \
      ft_tolower.c    \
      ft_memalloc.c   \
      ft_memdel.c     \
      ft_strnew.c     \
      ft_strdel.c     \
      ft_strclr.c     \
      ft_striter.c    \
      ft_striteri.c   \
      ft_strmap.c     \
      ft_strmapi.c    \
      ft_strequ.c     \
      ft_strnequ.c    \
      ft_strsub.c     \
      ft_strjoin.c    \
      ft_strtrim.c    \
      ft_strsplit.c   \
      ft_itoa.c       \
      ft_putchar.c    \
      ft_putstr.c     \
      ft_putendl.c    \
      ft_putnbr.c     \
      ft_putchar_fd.c \
      ft_putstr_fd.c  \
      ft_putendl_fd.c \
      ft_putnbr_fd.c  \
      ft_lstnew.c     \
      ft_lstdelone.c  \
      ft_lstdel.c     \
      ft_lstadd.c     \
      ft_lstiter.c    \
      ft_lstmap.c     \
	  ft_find_length.c\
	  ft_str_upcase.c \
	  ft_str_lowcase.c\
	  ft_atoi_base.c  \
	  ft_itoa_base.c  \
	  get_next_line.c

OBJ = $(SRC:.c=.o)

SRC_DIR = srcs

OBJ_DIR = objs

SRCS = $(addprefix $(SRC_DIR)/, $(SRC))

OBJS = $(addprefix $(OBJ_DIR)/, $(OBJ))

WFLAGS = -Wall -Wextra -Werror

.PHONY: all clean fclean re

all: $(NAME)

$(OBJS): $(SRCS)
	@/bin/mkdir -p $(OBJ_DIR)
	@gcc -c $(WFLAGS) $(SRCS) -I includes
	@/bin/mv $(OBJ) $(OBJ_DIR)/

$(NAME): $(OBJS)
	@ar rc $@ $^

clean:
	@/bin/rm -rf $(OBJ_DIR)

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all
