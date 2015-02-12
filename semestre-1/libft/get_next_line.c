/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kperreau <kperreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/10 15:54:21 by kperreau          #+#    #+#             */
/*   Updated: 2015/01/27 19:00:41 by kperreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static t_lst		*ft_del_elem(t_lst **stack, t_info *info)
{
	t_lst	*next;
	t_lst	*pstack;

	pstack = *stack;
	next = pstack->next;
	if (pstack == info->head)
		info->head = next;
	if (pstack == info->tail)
		info->tail = NULL;
	free(pstack);
	*stack = NULL;
	return (next);
}

static char			*ft_join_elem(t_info *info)
{
	char		*line;
	t_lst		*list;
	char		*temp;

	if (!(line = (char*)malloc(sizeof(char) * info->len + 1)))
		return (NULL);
	temp = line;
	list = info->head;
	while (list)
	{
		while (*list->buf && *list->buf != '\n')
			*line++ = *list->buf++;
		if (list->buf - list->buff >= list->ret)
			list = ft_del_elem(&list, info);
		else
		{
			++list->buf;
			break ;
		}
	}
	*line = '\0';
	info->len = 0;
	return (temp);
}

static int			ft_trait(t_lst *stack, t_info *info, char **line)
{
	const char	*s;

	s = stack->buf;
	while (*s != '\n' && *s != '\0')
		s++;
	stack->n = (*s != '\n') ? 0 : (size_t)s;
	if (stack->n)
	{
		info->len += stack->n - (size_t)stack->buf;
		*line = ft_join_elem(info);
		return (1);
	}
	info->len += stack->ret;
	return (0);
}

static t_lst		*ft_add_elem(t_info *info)
{
	t_lst	*list;
	t_lst	*temp;

	if (!(list = malloc(sizeof(t_lst))))
		return (NULL);
	list->buff[0] = '\0';
	list->buf = list->buff;
	list->ret = 0;
	list->next = NULL;
	if (!info->head)
	{
		info->head = list;
		info->tail = list;
	}
	else
	{
		temp = info->tail;
		temp->next = list;
		info->tail = list;
	}
	return (list);
}

int					get_next_line(int const fd, char **line)
{
	static t_lst	*stack = NULL;
	static t_info	*info = NULL;

	if (!info)
		ft_init_gnl(&info);
	if (stack && ft_trait(stack, info, line))
		return (1);
	if (fd < 0 || !(stack = ft_add_elem(info)))
		return (-1);
	while ((stack->ret = read(fd, stack->buff, BUFF_SIZE)) > 0)
	{
		stack->buff[stack->ret] = '\0';
		if (ft_trait(stack, info, line))
			return (1);
		if (!(stack = ft_add_elem(info)))
			return (-1);
	}
	if (stack->ret < 0)
		return (-1);
	*line = ft_join_elem(info);
	return (ft_reset_gnl(&info));
}
