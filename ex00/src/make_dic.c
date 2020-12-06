/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_dic.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gseobang <gseobang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 17:10:39 by gseobang          #+#    #+#             */
/*   Updated: 2020/12/06 18:16:44 by gseobang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../head/dictionary.h"

int	dic_error(void)
{
	write(1, "Dict Error\n", 11);
	return (1);
}

int	dic_open(char *dic_name, char *buf)
{
	int	fd;
	int	index;

	if ((fd = open(dic_name, O_RDONLY)) == -1)
		return (fd);
	index = read(fd, buf, 10000);
	buf[index] = '\0';
	return (fd);
}

int	check(char *buf, char *dic, int *i, int *j)
{
	int colon;

	colon = 0;
	while (buf[*i] != '\n' && buf[*i] != '\0')
	{
		if (buf[*i] != ' ' && buf[*i] != '\t')
		{
			if (colon == 0 && !(buf[*i] >= '0' && buf[*i] <= '9'))
			{
				return (1);
			}
			dic[++*j] = buf[*i];
		}
		*i += 1;
		if (buf[*i] == ':')
			colon = 1;
	}
	if (colon == 0)
	{
		printf("Cbuf i = %c\n", buf[*i]);
		return (1);
	}
	return (0);
}

int	sort_input(char *buf, char *dic)
{
	int i;
	int j;

	i = -1;
	j = -1;
	while (buf[++i] != '\0')
	{
		if (buf[i] == '\n')
			continue;
		if (check(buf, dic, &i, &j))
		{
			return (1);
		}
		dic[++j] = buf[i];
	}
	return (0);
}

int	make_dic(char *dic_name, char *buf, char *dic)
{
	int	fd;

	if ((fd = dic_open(dic_name, buf)) == -1)
		return (dic_error());
	if (sort_input(buf, dic))
		return (dic_error());
	close(fd);
	return (0);
}
