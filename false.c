/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   false.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapelcha <rapelcha@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 13:52:18 by rapelcha          #+#    #+#             */
/*   Updated: 2023/03/27 14:00:48 by rapelcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	f_ss(t_node **p_a, t_node **p_b)
{
	if (p_a && p_b)
	{
		sa(p_a);
		sb(p_b);
	}
	else if (p_a)
		sa(p_a);
	else if (p_b)
		sb(p_b);
}

void	f_rrr(t_node **p_a, t_node **p_b)
{
	if (p_a)
		rra(p_a);
	if (p_b)
		rrb(p_b);
}

void	f_rr(t_node **p_a, t_node **p_b)
{
	if (p_a)
		ra(p_a);
	if (p_b)
		rb(p_b);
}

int	ff(t_node **p_a, t_node **p_b, int cat, int w)
{
	int	nbrr;
	int	nbrrr;

	if (p_a)
	{
		nbrr = false_sort(&f_rr, cat, p_a, w);
		nbrrr = false_sort(&f_rrr, cat, p_a, w);
	}
	else
	{
		nbrr = false_sort(&f_rr, cat, p_b, w);
		nbrrr = false_sort(&f_rrr, cat, p_b, w);
	}
	if (nbrr < nbrrr)
		return (1);
	else
		return (2);
}