/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inside_node.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapelcha <rapelcha@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 12:53:42 by rapelcha          #+#    #+#             */
/*   Updated: 2023/03/27 14:06:38 by rapelcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	biggest(t_node **p, int cat)
{
	t_node	*temp;
	int		big;
	int		j;

	temp = (*p);
	big = INT_MIN;
	j = 1;
	while (temp != NULL)
	{
		if (cat == -2)
		{
			if (temp->val >= big && temp->icat == 0)
				big = temp->val;
		}	
		else if (cat == -1)
		{
			if (temp->val >= big)
				big = temp->val;
		}
		else if (temp->val >= big && temp->i == 0 && temp->cat == cat)
			big = temp->val;
		temp = temp->next;
	}
	return (big);
}

int	isallset(t_node **p, int cat)
{
	t_node	*temp;

	temp = (*p);
	while (temp != NULL)
	{
		if (temp->i == 0 && temp->cat == cat)
			return (0);
		temp = temp->next;
	}
	return (1);
}

void	index_in_cat(t_node **p, int cat)
{
	t_node	*temp;
	int		big;
	int		j;

	temp = (*p);
	j = 1;
	big = biggest(p, cat);
	while (isallset(p, cat) == 0)
	{
		if (temp == NULL)
		{
			temp = (*p);
			continue ;
		}
		else if (big == INT_MIN || isallset(p, cat) == 1)
			return ;
		else if (temp->val == big && temp->i == 0)
		{
			temp->i = j;
			j++;
			big = biggest(p, cat);
		}
		temp = temp->next;
	}
}

t_node	*get_element(t_node **node, int index)
{
	t_node	*temp;
	int		size;

	if (node == NULL)
		return (NULL);
	if (*node != NULL)
	{
		temp = *node;
		size = node_len(temp);
		if (size == 0)
			return (NULL);
		while (--size && --index)
			temp = temp->next;
		return (temp);
	}
	return (NULL);
}