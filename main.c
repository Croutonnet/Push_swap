/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapelcha <rapelcha@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 09:13:27 by rapelcha          #+#    #+#             */
/*   Updated: 2023/05/05 09:10:15 by rapelcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_pile_b(t_node **p_a, t_node **p_b)
{
	t_node	*last;

	last = get_element(p_b, node_len((*p_b)));
	if ((*p_b)->icat > last->icat)
		rr(p_a, p_b);
	else
		return ;
}

int	set_limit(t_node **p, int cat, int cal)
{
	int	limits;
	int	i;

	i = cat;
	if (!(*p))
		return (0);
	limits = cal;
	while (i > 1)
	{
		limits = limits + cal;
		i--;
	}
	return (limits);
}

int	node_len(t_node *p_a)
{
	int		size;

	size = 1;
	if (p_a == NULL)
		return (0);
	while (p_a->next)
	{
		p_a = p_a->next;
		if (p_a)
			size++;
	}
	return (size);
}

void	push_and_repush(t_node **p_a, t_node **p_b, t_vari *var)
{
	int	cat;
	int	cal;

	cat = 1;
	cal = (node_len((*p_a)) / var->nbcats + 1);
	if (is_sort(p_a) == 0)
	{
		while (cat <= var->nbcats)
		{
			var->limit = set_limit(p_a, cat, cal);
			var->nb_in_cat = which_cat(p_a, var->limit, cat);
			pushcat(p_a, p_b, var, cat);
			cat++;
		}
		cat = var->nbcats;
		while (cat > 0)
		{
			index_in_cat(p_b, cat);
			repush(p_a, p_b, cat);
			cat--;
		}
	}
}

int	main(int argc, char **argv)
{
	t_node	*p_a;
	t_node	*p_b;
	t_vari	var;
	int		i;

	i = 1;
	if (argc < 2)
		return (0);
	while (argv[i][0] == '\0' && i < (argc - 1))
		i++;
	if (argv[i][0] == '\0')
		error_handler();
	p_a = NULL;
	p_b = NULL;
	check_alphabet(argv);
	create_list(argv, &p_a);
	check_double(&p_a);
	if (is_sort(&p_a) == 0)
		sort(&p_a, &p_b, &var, node_len(p_a));
	if (p_a)
		free_node(p_a);
	if (p_b)
		free_node(p_b);
}
