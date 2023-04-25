/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adi-nata <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 14:51:09 by adi-nata          #+#    #+#             */
/*   Updated: 2022/10/25 14:51:10 by adi-nata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_strtrim(const char *s1, const char *set)
{
	int			star;
	int			end;
	char		*d;

	if (!*s1)
		return (ft_strdup(s1));
	if (!*set)
		return (ft_strdup(s1));
	star = 0;
	end = (int)ft_strlen(s1);
	while (s1[star] && ft_strchr(set, s1[star]) != NULL)
		star++;
	while (ft_strchr(set, s1[end]) != NULL)
		end--;
	if ((end - star) < 0)
	{
		d = (char *)malloc(sizeof(char) * 1);
		d[0] = '\0';
		return (d);
	}
	return (ft_substr(s1, star, (end - star + 1)));
}
