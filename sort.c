/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapelcha <rapelcha@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 14:56:29 by rapelcha          #+#    #+#             */
/*   Updated: 2023/03/28 15:26:59 by rapelcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pushcat(t_node **p_a, t_node **p_b, t_vari *var, int cat)
{
	int	false;

	if (var->nb_in_cat > 0)
	{
		false = ff(p_a, NULL, cat, 1);
		while (var->nb_in_cat > 0 && (*p_a) != NULL)
		{
			if ((*p_a)->cat == cat && var->nb_in_cat > 0)
			{
				pb(p_a, p_b);
				//move_pile_b(p_a, p_b);
				var->nb_in_cat--;
				false = ff(p_a, NULL, cat, 1);
			}
			else if (false == 1)
				rr(p_a, NULL);
			else
				rr(p_a, NULL);
		}
	}
}

void	repush(t_node **p_a, t_node **p_b, int cat)
{
	int	j;
	int	false;

	j = 1;
	false = ff(NULL, p_b, j, 2);
	while (iscatthere(p_b, cat) == 1)
	{
		if ((*p_b)->i == j)
		{
			pa(p_a, p_b);
			j++;
			false = ff(NULL, p_b, j, 2);
		}
		else if (false == 1)
			rr(NULL, p_b);
		else
			rrr(NULL, p_b);
	}
}

int	false_sort(void (*f)(t_node **, t_node **), int val, t_node **p, int w)
{
	int		nb;
	int		len;
	t_node	*copy;

	nb = 0;
	if ((*p) == NULL)
		return (0);
	copy = copy_node(p);
	if (copy == NULL)
		return (free_node(copy), 0);
	len = node_len(copy);
	while (len > 0)
	{
		if (copy->cat == val && w == 1)
			return (free_node(copy), nb);
		else if (copy->i == val && w == 2)
			return (free_node(copy), nb);
		nb++;
		len--;
		f(&copy, NULL);
	}
	return (free_node(copy), 0);
}

void	sort(t_node **p_a, t_node **p_b, t_vari *var, int len)
{
	if (len <= 5)
		small(p_a, p_b, len);
	else if (len > 5)
	{
		howmanycat(p_a, var);
		manage_node_index(p_a, len);
		push_and_repush(p_a, p_b, var);
	}
}
