/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xacoquan <xacoquan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 09:06:56 by xacoquan          #+#    #+#             */
/*   Updated: 2015/01/31 06:16:32 by xacoquan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strncpy(char *s1, const char *s2, size_t n)
{
	char	*dest;
	size_t	i;

	dest = s1;
	i = 0;
	while (n > i && *s2 != 0)
	{
		*dest = *s2;
		dest++;
		s2++;
		i++;
	}
	while (n > i)
	{
		*dest = '\0';
		dest++;
		i++;
	}
	return (s1);
}
