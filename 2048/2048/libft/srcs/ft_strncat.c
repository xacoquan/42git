/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarie-c <smarie-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/18 16:21:11 by smarie-c          #+#    #+#             */
/*   Updated: 2015/02/18 16:21:17 by smarie-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	unsigned int	i;
	int				j;

	j = 0;
	i = 0;
	while (s1[j])
		j++;
	while (i < n && s2[i])
		s1[j++] = s2[i++];
	s1[j] = '\0';
	return (s1);
}
