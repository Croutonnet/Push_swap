/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapelcha <rapelcha@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 09:13:27 by rapelcha          #+#    #+#             */
/*   Updated: 2023/03/27 15:43:37 by rapelcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_node(t_node *p_a)
{
	t_node	*current;

	current = p_a;
	while (current != NULL)
	{
		printf("%d	%d	%d	%d\n", current->val, current->cat, current->i, current->icat);
		current = current->next;
	}
}
// A enlever print_node

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
	int		nb;

	if (argc < 2)
		return (0);
	p_a = NULL;
	p_b = NULL;
	argv++;
	while (*argv)
	{
		nb = ft_atoi(*argv);
		push(&p_a, nb, 0, 0);
		p_a->i = 0;
		argv++;
	}
	if (is_sort(&p_a) == 0)
		sort(&p_a, &p_b, &var, node_len(p_a));
	if (p_a)
		free_node(p_a);
	if (p_b)
		free_node(p_b);
}
	