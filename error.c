/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapelcha <rapelcha@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 10:21:40 by rapelcha          #+#    #+#             */
/*   Updated: 2023/05/05 08:59:29 by rapelcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_int(t_node **p)
{
	t_node	*temp;

	temp = (*p);
	while (temp->next)
	{
		if (temp->val > INT_MAX || temp->val < INT_MIN)
			error_handler();
		temp = temp->next;
	}
}

void	check_alphabet(char **str)
{
	int	i;
	int	j;

	i = 1;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			if ((str[i][j] == 45 && (ft_isdigit(str[i][j - 1]) == 1
				|| ft_isdigit(str[i][j + 1]) == 0)))
				error_handler();
			else if (!((str[i][j] >= 48 && str[i][j] <= 57) || str[i][j] == 32
				|| str[i][j] == 45))
				error_handler();
			j++;
		}
		i++;
	}
}

void	check_double(t_node **p)
{
	t_node	*temp1;
	t_node	*temp2;

	temp1 = (*p);
	while (temp1)
	{
		temp2 = temp1->next;
		while (temp2)
		{
			if (temp1->val == temp2->val)
				error_handler();
			temp2 = temp2->next;
		}
		temp1 = temp1->next;
	}
}

void	error_handler(void)
{
	ft_putendl_fd("Error", 2);
	exit(1);
}
