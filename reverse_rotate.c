/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapelcha <rapelcha@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 09:37:26 by rapelcha          #+#    #+#             */
/*   Updated: 2023/03/27 14:04:13 by rapelcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_node **p_a)
{
	t_node	*top;
	t_node	*last;

	if ((*p_a) == NULL || (*p_a)->next == NULL)
		return ;
	last = get_element(p_a, (node_len((*p_a)) - 1));
	top = last->next;
	top->next = (*p_a);
	(*p_a) = top;
	last->next = NULL;
}

void	rrb(t_node **p_b)
{
	t_node	*top;
	t_node	*last;

	if ((*p_b) == NULL || (*p_b)->next == NULL)
		return ;
	last = get_element(p_b, (node_len((*p_b)) - 1));
	top = last->next;
	top->next = (*p_b);
	(*p_b) = top;
	last->next = NULL;
}

void	rrr(t_node **p_a, t_node **p_b)
{
	if (p_a)
		rra(p_a);
	if (p_b)
		rrb(p_b);
	if (p_a && p_b)
		ft_putendl_fd("rrr", 1);
	else if (p_a)
		ft_putendl_fd("rra", 1);
	else if (p_b)
		ft_putendl_fd("rrb", 1);
}
