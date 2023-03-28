/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapelcha <rapelcha@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 10:21:40 by rapelcha          #+#    #+#             */
/*   Updated: 2023/03/28 12:51:30 by rapelcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_int(char **str)
{
	int		i;
	long	nb;

	i = 1;
	while (str[i])
	{
		nb = ft_atol(str[i]);
		if (nb > INT_MAX || nb < INT_MIN || ft_strlen(str[i]) > 11)
		{
			ft_putendl_fd("Error", 2);
			exit (1);
		}
		i++;
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
			if (str[i][j] == 45 && (ft_isdigit(str[i][j - 1]) == 1
				|| ft_isdigit(str[i][j + 1]) == 0))
			{
				ft_putendl_fd("Error", 2);
				exit (1);
			}
			else if (!((str[i][j] >= 48 && str[i][j] <= 57) || str[i][j] == 32
				|| str[i][j] == 45))
			{
				ft_putendl_fd("Error", 2);
				exit (1);
			}
			j++;
		}
		i++;
	}
}

void	check_double(char **str)
{
	int	nb;
	int	verif;
	int	i;
	int	j;

	i = 1;
	while (str[i])
	{
		verif = ft_atoi(str[i]);
		j = i + 1;
		while (str[j])
		{
			nb = ft_atoi(str[j]);
			if (verif == nb)
			{
				ft_putendl_fd("Error", 2);
				exit (1);
			}
			j++;
		}
		i++;
	}
}
