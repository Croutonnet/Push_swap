/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapelcha <rapelcha@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 09:37:31 by rapelcha          #+#    #+#             */
/*   Updated: 2023/03/27 13:49:49 by rapelcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_node **p_a)
{
	t_node	*top;
	t_node	*mid;
	t_node	*bot;

	if ((*p_a) && (*p_a)->next)
	{
		top = (*p_a);
		mid = (*p_a)->next;
		bot = (*p_a)->next->next;
		*p_a = mid;
		(*p_a)->next = top;
		(*p_a)->next->next = bot;
	}
}

void	sb(t_node **p_b)
{
	t_node	*top;
	t_node	*mid;
	t_node	*bot;

	if ((*p_b) && (*p_b)->next)
	{
		top = (*p_b);
		mid = (*p_b)->next;
		bot = (*p_b)->next->next;
		*p_b = mid;
		(*p_b)->next = top;
		(*p_b)->next->next = bot;
	}
}

void	ss(t_node **p_a, t_node **p_b)
{
	if (p_a && p_b)
	{
		ft_putendl_fd("ss", 1);
		sa(p_a);
		sb(p_b);
	}
	else if (p_a)
	{
		ft_putendl_fd("sa", 1);
		sa(p_a);
	}
	else if (p_b)
	{
		ft_putendl_fd("sb", 1);
		sb(p_b);
	}
}
