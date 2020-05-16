/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mskinner <mskinner@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/29 21:46:09 by mskinner          #+#    #+#             */
/*   Updated: 2020/04/30 00:25:22 by mskinner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_skip_left(const char *s, const char *set)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while ((set[i] != '\0') && (s[j] != '\0'))
	{
		if (set[i] == s[j])
		{
			j++;
			i = 0;
		}
		else
			i++;
	}
	return (j);
}

static int	ft_skip_right(const char *s, const char *set)
{
	int i;
	int j;
	int len;

	i = 0;
	len = ft_strlen(s);
	j = len - 1;
	while ((set[i] != '\0') && (j >= 0))
	{
		if (set[i] == s[j])
		{
			j--;
			i = 0;
		}
		else
			i++;
	}
	return (len - j - 1);
}

char		*ft_strtrim(const char *s1, const char *set)
{
	int		left;
	int		right;
	int		len;

	if (!s1)
		return (00);
	if ((s1) && (!set))
		return (ft_strdup(s1));
	left = ft_skip_left(s1, set);
	right = ft_skip_right(s1, set);
	len = ft_strlen(s1) - left - right;
	if (len > 0)
		return (ft_substr(s1, left, len));
	else
		return (ft_strdup(""));
}
