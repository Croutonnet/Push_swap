NAME	=	push_swap
LIBFT	= 	libft.a
LDIR	=	libft/

CC		=	gcc
CFLAGS	=	-Wall -Werror -Wextra
RM		=	rm -f

SRCS	=	push.c\
			main.c\
			reverse_rotate.c\
			rotate.c\
			swap.c\
			utils.c\
			error.c\
			inside_node.c\
			verif_node.c\
			sort.c\
			small.c\
			false.c\
			tools.c\


OBJS	=	$(SRCS:.c=.o)


all: $(NAME)

$(NAME): $(OBJS)
	@$(MAKE) -C $(LDIR)
	@$(CC) $(CFLAGS) $(SRCS) $(LDIR)$(LIBFT) -o $(NAME)

run: all
	@./$(NAME)

clean:
	@$(RM) $(OBJS)
	@make -C $(LDIR) clean

fclean: clean
	@$(RM) $(NAME)
	@make -C $(LDIR) fclean

visu:
	./push_swap_visualizer/build/bin/visualizer

re: fclean all

visumake: 
	git clone https://github.com/o-reo/push_swap_visualizer.git && cd push_swap_visualizer && mkdir build && cd build && cmake .. && make
tester:
	git clone https://github.com/LeoFu9487/push_swap_tester.git