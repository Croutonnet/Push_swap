/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapelcha <rapelcha@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 09:37:29 by rapelcha          #+#    #+#             */
/*   Updated: 2023/03/14 16:27:51 by rapelcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_node **p_a)
{
	t_node	*top;
	t_node	*tempb;

	if ((*p_a) == NULL || (*p_a)->next == NULL)
		return ;
	top = (*p_a)->next;
	tempb = get_element(p_a, node_len(*p_a));
	tempb->next = *p_a;
	(*p_a)->next = NULL;
	*p_a = top;
}

void	rb(t_node **p_b)
{
	t_node	*top;
	t_node	*tempb;

	if ((*p_b) == NULL || (*p_b)->next == NULL)
		return ;
	top = (*p_b)->next;
	tempb = get_element(p_b, node_len(*p_b));
	tempb->next = *p_b;
	(*p_b)->next = NULL;
	*p_b = top;
}

void	rr(t_node **p_a, t_node **p_b)
{
	if (p_a)
		ra(p_a);
	if (p_b)
		rb(p_b);
	if (p_a && p_b)
		ft_putendl_fd("rr", 1);
	else if (p_a)
		ft_putendl_fd("ra", 1);
	else if (p_b)
		ft_putendl_fd("rb", 1);
}
