/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapelcha <rapelcha@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 12:50:52 by rapelcha          #+#    #+#             */
/*   Updated: 2023/05/05 08:59:50 by rapelcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static long	ft_splatoi(char *str, int i)
{
	int		neg;
	long	res;

	if (!str)
		return (0);
	neg = 1;
	res = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == 43 || str[i] == 45)
	{
		if (str[i] == 45)
			neg = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res *= 10;
		res += str[i] - 48;
		i++;
	}
	return (res * neg);
}

int	ft_sstrlen(char *str, int i)
{
	int	j;

	j = 0;
	while (str[i] && str[i] != ' ')
	{
		i++;
		j++;
	}
	return (j);
}

void	create_list(char **arg, t_node **p_a)
{
	int	i;
	int	j;

	i = 1;
	while (arg[i])
	{
		j = 0;
		while (arg[i][j])
		{
			if (ft_splatoi(arg[i], j) > INT_MAX
				|| ft_splatoi(arg[i], j) < INT_MIN
				|| ft_sstrlen(arg[i], j) > 11)
				error_handler();
			push(p_a, ft_splatoi(arg[i], j), 0, 0);
			while ((arg[i][j] >= '0' && arg[i][j] <= '9') || arg[i][j] == '-')
				j++;
			while (arg[i][j] == ' ')
				j++;
		}
		i++;
	}
}
