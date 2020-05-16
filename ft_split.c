/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mskinner <mskinner@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/29 21:46:09 by mskinner          #+#    #+#             */
/*   Updated: 2020/04/30 00:25:22 by mskinner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_splits_qty(const char *s, char c)
{
	int i;
	int qty;

	i = 0;
	qty = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		if (s[i] != '\0')
			qty++;
		while ((s[i] != '\0') && (s[i] != c))
			i++;
	}
	return (qty);
}

static char	**ft_free_mem(char **lst, size_t n)
{
	size_t i;

	i = 0;
	while (i < n)
		free(lst[i++]);
	free(lst);
	return (00);
}

static char	**ft_fill_lst(char **res, const char *s, char c)
{
	size_t	i;
	size_t	j;
	size_t	start;

	i = 0;
	j = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		start = i;
		while ((s[i] != c) && (s[i] != '\0'))
			i++;
		if (start < i)
		{
			res[j] = ft_substr(s, start, i - start);
			if (!res[j])
				return (ft_free_mem(res, j));
			j++;
		}
	}
	res[j] = 0;
	return (res);
}

char		**ft_split(const char *s, char c)
{
	char	**res;

	if (s == 00)
		return (00);
	res = (char **)ft_calloc(ft_splits_qty(s, c) + 1, sizeof(char *));
	if (res == 00)
		return (00);
	return (ft_fill_lst(res, s, c));
}
