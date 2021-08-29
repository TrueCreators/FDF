/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sreicher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/15 17:09:21 by sreicher          #+#    #+#             */
/*   Updated: 2018/12/17 21:47:57 by sreicher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int		result;
	int		sign;
	size_t	i;

	result = 0;
	sign = 1;
	i = 0;
	while (*str == ' ' || *str == '\t' || *str == '\r' || *str == '\n' ||
			*str == '\f' || *str == '\v' || *str == '0')
		str++;
	if (*str == '-')
		sign = -1;
	if (*str == '+' || *str == '-')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		if (i == 10 && sign == -1)
			return (0);
		if (i == 10 && sign == 1)
			return (-1);
		result = result * 10 + *str - '0';
		str++;
		i++;
	}
	return (result * sign);
}
