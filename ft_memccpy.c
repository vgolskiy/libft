/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mskinner <mskinner@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/29 21:46:09 by mskinner          #+#    #+#             */
/*   Updated: 2020/04/30 00:25:22 by mskinner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char		ch;
	unsigned char		*tmp1;
	const unsigned char	*tmp2;

	ch = (unsigned char)c;
	tmp1 = (unsigned char *)dest;
	tmp2 = (const unsigned char	*)src;
	while (n--)
	{
		*tmp1 = *tmp2;
		if (*tmp2 == ch)
			return (dest + (tmp1 - (unsigned char *)dest) + 1);
		tmp1++;
		tmp2++;
	}
	return (00);
}
