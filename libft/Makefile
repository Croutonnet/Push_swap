# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rapelcha <rapelcha@student.42quebec.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/18 09:23:06 by rapelcha          #+#    #+#              #
#    Updated: 2023/03/28 10:30:24 by rapelcha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#------------------------------------------------------------------------------#
#                                VARIABLES                                     #
#------------------------------------------------------------------------------#

NAME = libft.a

# Compiler and flags
CC		=	gcc
CFLAGS	=	-Wall -Werror -Wextra
RM		=	rm -f

# Sources are all .c files
SRCS	=	ft_atoi.c\
			ft_atol.c\
			ft_bzero.c\
			ft_calloc.c\
			ft_isalnum.c\
			ft_isalpha.c\
			ft_isascii.c\
			ft_isdigit.c\
			ft_isprint.c\
			ft_itoa.c\
			ft_memchr.c\
			ft_memcmp.c\
			ft_memcpy.c\
			ft_memmove.c\
			ft_memset.c\
			ft_putchar_fd.c\
			ft_putendl_fd.c\
			ft_putnbr_fd.c\
			ft_putstr_fd.c\
			ft_split.c\
			ft_strchr.c\
			ft_strdup.c\
			ft_striteri.c\
			ft_strjoin.c\
			ft_strlcat.c\
			ft_strlcpy.c\
			ft_strlen.c\
			ft_strmapi.c\
			ft_strncmp.c\
			ft_strnstr.c\
			ft_strrchr.c\
			ft_strtrim.c\
			ft_substr.c\
			ft_tolower.c\
			ft_realloc.c\
			ft_searchstr.c\
			ft_xfree.c\
			get_next_line.c\
			ft_toupper.c

OBJS = $(SRCS:.c=.o)
# BSources are all .c files
BSRCS	=	ft_lstnew.c\
			ft_lstadd_front.c\
			ft_lstsize.c\
			ft_lstlast.c\
			ft_lstadd_back.c\
			ft_lstdelone.c\
			ft_lstclear.c\
			ft_lstiter.c\
			ft_lstmap.c

BOBJS = $(BSRCS:.c=.o)

#------------------------------------------------------------------------------#
#                                 TARGETS                                      #
#------------------------------------------------------------------------------#

all: $(NAME)

# Generates output file
$(NAME): $(OBJS)
	@ar -rcs $(NAME) $(OBJS)

# Compiles sources into objects
$(OBJS): $(SRCS)
	@$(CC) $(CFLAGS) -c $(SRCS)

bonus: $(BOBJS)
	@ar -rs $(NAME) $(BOBJS)

$(BOBJS): $(BSRCS)
	@$(CC) $(CFLAGS) -c $(BSRCS)

# Removes objects
clean:
	@$(RM) $(OBJS) $(BOBJS)

# Removes objects and executables
fclean: clean
	@$(RM) $(NAME)

# Removes objects and executables and remakes
re: fclean all
