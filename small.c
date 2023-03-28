/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapelcha <rapelcha@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 10:05:17 by rapelcha          #+#    #+#             */
/*   Updated: 2023/03/27 14:04:35 by rapelcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	three(t_node **p)
{
	if ((*p)->val < (*p)->next->val && (*p)->next->val < (*p)->next->next->val)
		return ;
	else if ((*p)->val > (*p)->next->val && (*p)->next->val
		> (*p)->next->next->val && (*p)->val > (*p)->next->next->val)
	{
		rr(p, NULL);
		ss(p, NULL);
	}
	else if ((*p)->val < (*p)->next->val && (*p)->next->val
		> (*p)->next->next->val && (*p)->val > (*p)->next->next->val)
		rrr(p, NULL);
	else if ((*p)->val > (*p)->next->val && (*p)->next->val
		< (*p)->next->next->val && (*p)->val < (*p)->next->next->val)
		ss(p, NULL);
	else if ((*p)->val > (*p)->next->val && (*p)->next->val
		< (*p)->next->next->val && (*p)->val > (*p)->next->next->val)
		rr(p, NULL);
	else if ((*p)->val < (*p)->next->val && (*p)->next->val
		> (*p)->next->next->val && (*p)->val < (*p)->next->next->val)
	{
		ss(p, NULL);
		rr(p, NULL);
	}
}

void	five(t_node **p_a, t_node **p_b)
{
	int		nb;

	nb = 2;
	index_in_cat(p_a, 0);
	while (nb > 0)
	{
		if ((*p_a)->i == 4 || (*p_a)->i == 5)
		{
			pb(p_a, p_b);
			nb--;
		}	
		rrr(p_a, NULL);
	}
	three(p_a);
	if ((*p_b)->i == 4)
	{
		pa(p_a, p_b);
		pa(p_a, p_b);
	}
	else
	{
		rrr(NULL, p_b);
		pa(p_a, p_b);
		pa(p_a, p_b);
	}
}

void	four(t_node **p_a, t_node **p_b)
{
	int	big;

	big = biggest(p_a, 0);
	while ((*p_a)->val != big)
		rr(p_a, NULL);
	pb(p_a, p_b);
	three(p_a);
	pa(p_a, p_b);
	rr(p_a, NULL);
}

void	small(t_node **p_a, t_node **p_b, int len)
{
	if (len == 2 && (*p_a)->val > (*p_a)->next->val)
		ss(p_a, NULL);
	else if (len == 3)
		three(p_a);
	else if (len == 4)
		four(p_a, p_b);
	else if (len == 5)
		five(p_a, p_b);
}
