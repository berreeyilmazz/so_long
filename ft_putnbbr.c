/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: havyilma <havyilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 05:09:18 by havyilma          #+#    #+#             */
/*   Updated: 2023/03/25 01:01:50 by havyilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_intlen(long n)
{
	int	count;

	count = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n = n / 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	char	*str;
	long	size;
	long	real;

	real = n;
	size = ft_intlen(real) + 1;
	str = malloc(sizeof(char) * size);
	if (!str)
		return (0);
	str[size - 1] = '\0';
	size--;
	while (--size >= 0)
	{
		str[size] = (n % 10) + 48;
		n = n / 10;
	}
	return (str);
}
