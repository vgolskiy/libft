/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mskinner <mskinner@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/29 21:46:09 by mskinner          #+#    #+#             */
/*   Updated: 2020/04/30 00:25:22 by mskinner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t n)
{
	size_t	i;
	int		add;
	size_t	len_d;
	size_t	len_s;

	len_d = ft_strlen(dest);
	len_s = ft_strlen(src);
	add = n - len_d;
	if (add > 0)
	{
		i = 0;
		while ((--add) && (src[i] != '\0'))
		{
			dest[len_d + i] = src[i];
			i++;
		}
		dest[len_d + i] = '\0';
	}
	len_d = (len_d > n) ? n : len_d;
	return (len_d + len_s);
}
