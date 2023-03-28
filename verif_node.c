/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_node.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapelcha <rapelcha@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 12:48:21 by rapelcha          #+#    #+#             */
/*   Updated: 2023/03/28 10:44:46 by rapelcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*copy_node(t_node **p)
{
	t_node	*copy;
	t_node	*temp;

	temp = (*p);
	if ((*p) == NULL)
		return (NULL);
	copy = create_node(temp->val);
	if (temp->next)
		temp = temp->next;
	copy->cat = temp->cat;
	while (temp)
	{
		push(&copy, temp->val, temp->cat, temp->i);
		temp = temp->next;
	}
	return (copy);
}

void	free_node(t_node *p)
{
	t_node	*temp1;
	t_node	*temp2;

	temp1 = p;
	while (temp1)
	{
		temp2 = temp1->next;
		free(temp1);
		temp1 = temp2;
	}
}

void	manage_node_index(t_node **p, int len)
{
	while (len > 0)
	{
		index_node(p, len);
		len--;
	}
}

int	is_sort(t_node **p)
{
	t_node	*temp;
	int		big;

	temp = (*p);
	big = biggest(p, -1);
	while (temp->next)
	{
		if (temp->val > temp->next->val)
			return (0);
		temp = temp->next;
	}
	if (big == temp->val)
		return (1);
	return (0);
}

void	index_node(t_node **p, int i)
{
	t_node	*temp;
	int		big;

	temp = (*p);
	big = biggest(p, -2);
	while (temp)
	{
		if (temp->val == big)
			temp->icat = i;
		temp = temp->next;
	}
}
