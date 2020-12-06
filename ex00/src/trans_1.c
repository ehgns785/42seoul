/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trans_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gseobang <gseobang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 17:10:39 by gseobang          #+#    #+#             */
/*   Updated: 2020/12/06 18:08:18 by gseobang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../head/dictionary.h"
#include "../head/ft_str.h"
#include "../head/trans.h"

void	print_dic(char *str)
{
	while (*str != '\n')
	{
		write(1, &*str, 1);
		str++;
	}
	return ;
}

int		once_print(char *numarr, char *dic, int pos)
{
	char find[3];
	char *start;

	find[0] = numarr[pos];
	find[1] = ':';
	find[2] = '\0';
	start = ft_strstr(dic, find);
	while (*start != ':')
		start++;
	start++;
	print_dic(start);
	return (0);
}

int		print_num_to_unit(char *numarr, char *dic, int len, int minus)
{
	char	*length;
	int		count;
	char	*print;

	if (check_pass(numarr, len, minus))
		return (0);
	if (check_19_1(numarr, len, minus))
	{
		once_print(numarr, dic, (len - minus));
		write(1, " ", 1);
	}
	count = (minus / 3) * 3;
	if (!(length = malloc(sizeof(char) * count + 1 + 1)))
		return (1);
	one_zero(length, count);
	print = ft_strstr(dic, length);
	while (*print != ':')
		print++;
	print++;
	print_dic(print);
	write(1, " ", 1);
	free(length);
	return (0);
}

int		all_print(char *numarr, char *dic, int len)
{
	int minus;
	int malloc_error;

	malloc_error = 0;
	minus = len;
	while (minus)
	{
		if (minus > 3 && minus % 3 == 1)
			malloc_error = print_num_to_unit(numarr, dic, len, minus--);
		else if (minus % 3 == 0)
			malloc_error = print_num_to_100(numarr, dic, len, minus--);
		else if (minus % 3 == 2)
			malloc_error = print_num_to_10(numarr, dic, len, minus--);
		else if (minus == 1)
			malloc_error = print_num_to_end(numarr, dic, len, minus--);
		if (malloc_error)
			return (1);
	}
	return (0);
}

int		translate(char *numarr, char *dic)
{
	int len;

	len = ft_strlen(numarr);
	if (len == 1)
		return (once_print(numarr, dic, 0));
	else
		return (all_print(numarr, dic, len));
	return (0);
}
