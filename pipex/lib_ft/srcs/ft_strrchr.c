/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohamibr <mohamibr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 15:50:24 by mohamibr          #+#    #+#             */
/*   Updated: 2024/10/20 15:23:12 by mohamibr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

char	*ft_strrchr(const char *str, int ch)
{
	int		i;
	char	c;
	char	*s;
	char	*res;

	i = 0;
	c = (char)ch;
	s = (char *)str;
	res = NULL;
	if (c == '\0')
		return (s + ft_strlen(s));
	while (s[i])
	{
		if (s[i] == c)
			res = &s[i];
		i++;
	}
	return (res);
}
