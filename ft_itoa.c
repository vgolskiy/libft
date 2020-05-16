/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mskinner <mskinner@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/29 21:46:09 by mskinner          #+#    #+#             */
/*   Updated: 2020/04/30 00:25:22 by mskinner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_negative(char *res, int n)
{
	size_t			len;
	unsigned int	tmp;
	unsigned int	num;

	len = 1;
	num = n * (-1);
	tmp = num;
	while (tmp > 0)
	{
		tmp /= 10;
		len++;
	}
	if (!(res = (char *)ft_calloc((len + 1), sizeof(char))))
		return (00);
	res[0] = '-';
	while (num > 0)
	{
		res[--len] = num % 10 + '0';
		num /= 10;
	}
	return (res);
}

char		*ft_itoa(int n)
{
	size_t	len;
	int		tmp;
	char	*res;

	res = 00;
	len = 1;
	tmp = n;
	if (n < 0)
		return (ft_negative(res, n));
	while (tmp >= 10)
	{
		tmp /= 10;
		len++;
	}
	if (!(res = (char *)ft_calloc((len + 1), sizeof(char))))
		return (00);
	if (!n)
		res[0] = '0';
	while (n > 0)
	{
		res[--len] = n % 10 + '0';
		n /= 10;
	}
	return (res);
}
