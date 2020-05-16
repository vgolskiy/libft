/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mskinner <mskinner@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/29 21:46:09 by mskinner          #+#    #+#             */
/*   Updated: 2020/04/30 00:25:22 by mskinner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *find, size_t n)
{
	size_t i;
	size_t j;

	if (*find == '\0')
		return ((char *)str);
	i = 0;
	while ((i < n) && (str[i] != '\0'))
	{
		j = 0;
		while ((str[i] == find[j]) && (i < n))
		{
			if (find[j + 1] == '\0')
				return ((char *)str + (i - j));
			i++;
			j++;
		}
		i = i - j;
		i++;
	}
	return (00);
}
