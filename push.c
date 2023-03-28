/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapelcha <rapelcha@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 09:37:34 by rapelcha          #+#    #+#             */
/*   Updated: 2023/03/21 14:30:50 by rapelcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_node **p_a, t_node **p_b)
{
	t_node	*tempa;
	t_node	*tempb;

	if (!(*p_b))
		return ;
	tempb = (*p_b)->next;
	tempa = (*p_a);
	(*p_a) = (*p_b);
	(*p_a)->next = tempa;
	(*p_b) = tempb;
	ft_putendl_fd("pa", 1);
}

void	pb(t_node **p_a, t_node **p_b)
{
	t_node	*tempa;
	t_node	*tempb;

	if (!(*p_a))
		return ;
	tempa = (*p_a)->next;
	tempb = (*p_b);
	(*p_b) = (*p_a);
	(*p_b)->next = tempb;
	(*p_a) = tempa;
	ft_putendl_fd("pb", 1);
}
