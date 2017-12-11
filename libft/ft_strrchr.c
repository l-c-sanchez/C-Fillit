/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamy <alamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 17:02:44 by alamy             #+#    #+#             */
/*   Updated: 2017/11/14 13:02:08 by alamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char c1;
	char *s2;

	c1 = (char)c;
	s2 = (char *)s;
	while (*s2 != '\0')
		s2++;
	while (*s2 != c1)
	{
		if (s2 == s)
		{
			return (0);
		}
		s2--;
	}
	return ((char *)s2);
}
