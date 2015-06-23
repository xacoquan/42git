/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xacoquan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/21 04:43:27 by xacoquan          #+#    #+#             */
/*   Updated: 2015/06/22 02:02:33 by xacoquan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char *strnchr(


int ft_atoi_base(const char *str, int str_base)
{
	int sign;
	const buf1[] = "0123456789abcdef";
	const buf2[] = "0123456789ABCDEF";
	char *tmp;
	int size;

	size = 0;
	if (*str == "-")
		sign = -1;
	else
		sign = 1;
	while (str)
	{
		if (*str && (tmp = ft_strnchr(buf1, *tmp, str_base)))
			tmp - 
	}

	return(tmp * sign);
}



int main(int ac, char **av)
{
	ft_atoi_base("2A", 8)
}
