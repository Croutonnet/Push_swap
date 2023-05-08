/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapelcha <rapelcha@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 09:28:42 by rapelcha          #+#    #+#             */
/*   Updated: 2023/05/08 10:04:16 by rapelcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

typedef struct s_node
{
	int				val;
	struct s_node	*next;
	int				cat;
	int				i;
	int				icat;
}					t_node;

typedef struct s_vari
{
	int	nbcats;
	int	div;
	int	limit;
	int	nb_in_cat;
	int	id_reverse;
}					t_vari;

void	sa(t_node **p_a);
void	sb(t_node **p_b);
void	ss(t_node **p_a, t_node **p_b);
void	f_ss(t_node **p_a, t_node **p_b);
void	pa(t_node **p_a, t_node **p_b);
void	pb(t_node **p_a, t_node **p_b);
void	ra(t_node **p_a);
void	rb(t_node **p_b);
void	rr(t_node **p_a, t_node **p_b);
void	f_rr(t_node **p_a, t_node **p_b);
void	rra(t_node **p_a);
void	rrb(t_node **p_b);
void	rrr(t_node **p_a, t_node **p_b);
void	f_rrr(t_node **p_a, t_node **p_b);
int		false_sort(void (*f)(t_node **, t_node **), int val, t_node **p, int w);
//--------------------UTILS--------------------//
t_node	*get_element(t_node **node, int index);
t_node	*create_node(int val);
t_node	*copy_node(t_node **p);
void	free_node(t_node *p);
void	small(t_node **p_a, t_node **p_b, int len);
void	create_list(char **arg, t_node **p_a);
int		ft_sstrlen(char *str, int i);
void	push(t_node **p_a, int val, int cat, int i);
void	push_and_repush(t_node **p_a, t_node **p_b, t_vari *var);
void	repush(t_node **p_a, t_node **p_b, int cat);
void	pushcat(t_node **p_a, t_node **p_b, t_vari *var, int cat);
void	index_in_cat(t_node **p, int cat);
void	manage_node_index(t_node **p, int len);
void	howmanycat(t_node **p, t_vari *var);
void	three(t_node **p);
void	check_int(t_node **p);
void	check_alphabet(char **str);
void	check_double(t_node **p);
void	index_node(t_node **p, int i);
void	four(t_node **p_a, t_node **p_b);
void	five(t_node **p_a, t_node **p_b);
void	sort(t_node **p_a, t_node **p_b, t_vari *var, int len);
void	move_pile_b(t_node **p_a, t_node **p_b);
void	error_handler(void);
int		which_cat(t_node **p, int limit, int i);
int		isallset(t_node **p, int cat);
int		iscatthere(t_node **p, int cat);
int		is_sort(t_node **p);
int		biggest(t_node **p, int cat);
int		ff(t_node **p_a, t_node **p_b, int cat, int w);
int		node_len(t_node *p_a);
int		set_limit(t_node **p, int cat, int moy);
#endif