/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xacoquan <xacoquan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/14 12:33:23 by xacoquan          #+#    #+#             */
/*   Updated: 2014/12/01 14:39:42 by xacoquan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

int		empty(char **line, char **ret)
{
	*line = ft_strdup(*ret);
	free(*ret);
	*ret = NULL;
	if ((*line)[0] == '\0')
		return (0);
	return (1);
}

void	mapping(char *buff, char **fdp, int index)
{
	char *tmp;

	buff[index] = '\0';
	tmp = *fdp;
	*fdp = ft_strjoin(*fdp, buff);
	free(tmp);
}

t_list	*ft_search_fd(t_list **list, int fd)
{
	t_list	*l;

	l = *list;
	while (l)
	{
		if (fd = l->fd)
		{
			if (l->ret == NULL)
				l->ret = ft_strnew(0);
			return (l);
		}
		l = l->next;
	}
	l = (t_list*)malloc(sizeof(t_list));
	if (l)
	{
		l->fd = fd;
		l->ret = ft_strnew(0);
		l->next = *list;
		*list = l;
	}
	return (l);
}

int		get_next_line(int const fd, char **line)
{
	char    buff[BUFF_SIZE + 1];
	int     index;
	static t_list *list = NULL;
	char    *tmp1;
	t_list	*tmp;

	if (fd == -1 || BUFF_SIZE <= 0)
		return (-1);
	index = 0; 
	if (!(tmp = ft_search_fd(&list, fd)))
		return (-1);
	while ((ft_strchr(tmp->ret, '\n') == NULL)
		   && (index = read(fd, buff, BUFF_SIZE)) > 0)
		mapping(buff, &(tmp->ret), index);
	if (index == -1)
		return (-1);
	else if (index == 0 && ft_strchr(tmp->ret, '\n') == NULL)
		return (empty(line, &(tmp->ret)));
	tmp1 = ft_strchr(tmp->ret, '\n') + 1;
	*line = ft_strsub(tmp->ret, 0, (size_t)(tmp1 - 1 - tmp->ret));
	tmp->ret = ft_strdup(tmp1);
	return (1);
}

int		main(int ac, char **av)
{
	int fd;
	char *test;
	int		i;

	i = 1;
	if (av[i])
		fd = open(av[i], O_RDONLY);
	else
		fd = 0;
	if (fd < 0)
	{
		ft_putendl("no fd u noob");
		exit(0);
	}
	while (get_next_line(fd, &test) > 0)
	{
		printf("%s\n", test);
		free(test);
	}
//	printf("%s\n", test);
	free(test);
	return (ac);
}
