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
			inside_node.c\
			verif_node.c\
			sort.c\
			small.c\
			false.c\


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

test: all
	@echo "10 tests/ 0 - 500"
	@./push_swap `ruby -e "puts (1..500).to_a.shuffle.join(' ')"` | wc -l
	@./push_swap `ruby -e "puts (1..500).to_a.shuffle.join(' ')"` | wc -l
	@./push_swap `ruby -e "puts (1..500).to_a.shuffle.join(' ')"` | wc -l
	@./push_swap `ruby -e "puts (1..500).to_a.shuffle.join(' ')"` | wc -l
	@./push_swap `ruby -e "puts (1..500).to_a.shuffle.join(' ')"` | wc -l
	@./push_swap `ruby -e "puts (1..500).to_a.shuffle.join(' ')"` | wc -l
	@./push_swap `ruby -e "puts (1..500).to_a.shuffle.join(' ')"` | wc -l
	@./push_swap `ruby -e "puts (1..500).to_a.shuffle.join(' ')"` | wc -l
	@./push_swap `ruby -e "puts (1..500).to_a.shuffle.join(' ')"` | wc -l
	@./push_swap `ruby -e "puts (1..500).to_a.shuffle.join(' ')"` | wc -l