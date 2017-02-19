#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bmiller <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/13 23:25:56 by bmiller           #+#    #+#              #
#    Updated: 2017/01/14 20:50:46 by bmiller          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = libft.a
SRC = ft_strlen.c ft_strchr.c ft_strdup.c ft_strnew.c ft_lstnew.c ft_lstadd.c\
	ft_strncpy.c ft_memcpy.c
SRCS = $(basename $(SRC))
OBJ = $(addprefix $(OBJDIR),$(SRC:.c=.o))
CFLAGS = -Wall -Werror -Wextra
OBJDIR	= ./obj/
SRCDIR	= ./src/
INCDIR	= ./includes/

all: $(NAME)

$(NAME): obj $(OBJ) $(INCDIR)libft.h
	ar rc $(NAME) $(OBJ) && ranlib $(NAME)

obj:
	mkdir -p $(OBJDIR)

$(OBJDIR)%.o:$(SRCDIR)%.c obj
	gcc $(CFLAGS) -I $(INCDIR) -o $@ -c $<

$(SRCS):%:$(OBJDIR)%.o obj

clean:
	rm -rf $(OBJDIR)

fclean: clean
	rm -f $(NAME)

re: fclean $(NAME)
