/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapelcha <rapelcha@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 09:39:17 by rapelcha          #+#    #+#             */
/*   Updated: 2023/05/04 14:24:23 by rapelcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	which_cat(t_node **p, int limit, int i)
{
	int		nb;
	t_node	*temp;

	nb = 0;
	temp = (*p);
	while (temp != NULL)
	{
		if (temp->icat <= limit && temp->cat == 0)
		{
			temp->cat = i;
			if (temp->cat == i)
				nb++;
		}
		temp = temp->next;
	}
	return (nb);
}

t_node	*create_node(int val)
{
	t_node	*temp;

	temp = ft_calloc(1, sizeof(t_node));
	if (!temp)
		return (NULL);
	temp->val = val;
	temp->cat = 0;
	return (temp);
}

void	push(t_node **p_a, int val, int cat, int i)
{
	t_node	*current;

	if (*p_a == NULL)
	{
		(*p_a) = create_node(val);
		return ;
	}
	current = (*p_a);
	while (current->next != NULL)
		current = current->next;
	current->next = create_node(val);
	if (!current->next)
		return ;
	current->next->cat = cat;
	current->next->i = i;
}

int	iscatthere(t_node **p, int cat)
{
	t_node	*temp;

	temp = (*p);
	while (temp != NULL)
	{
		if (temp->cat == cat)
			return (1);
		temp = temp->next;
	}
	return (0);
}

void	howmanycat(t_node **p, t_vari *var)
{
	int	len;

	len = node_len((*p));
	if (len < 300 && len > 5)
		var->nbcats = 5;
	else if (len >= 300 && len < 500)
		var->nbcats = 12;
	else
		var->nbcats = 13;
	return ;
}
