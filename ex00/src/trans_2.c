/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trans_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gseobang <gseobang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 17:10:39 by gseobang          #+#    #+#             */
/*   Updated: 2020/12/06 17:16:44 by gseobang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../head/dictionary.h"
#include "../head/ft_str.h"
#include "../head/trans.h"

void	one_zero(char *str, int count)
{
	int i;

	i = 1;
	str[0] = '1';
	while (count--)
		str[i++] = '0';
	str[i] = '\0';
}

int		check_19_1(char *numarr, int len, int minus)
{
	if (numarr[len - minus] == '0')
		return (0);
	if (numarr[len - minus - 1] == '1')
		return (0);
	return (1);
}

void	set_num_19(char *str, char *numarr, int len, int minus)
{
	str[0] = '1';
	str[1] = numarr[len - minus + 1];
	str[2] = ':';
	str[3] = '\0';
}

void	set_num(char *str, char *numarr, int len, int minus)
{
	str[0] = numarr[len - minus];
	str[1] = '0';
	str[2] = ':';
	str[3] = '\0';
}

int		print_num_to_10(char *numarr, char *dic, int len, int minus)
{
	char *dest;
	char *print;

	if (numarr[len - minus] == '0')
		return (0);
	if (!(dest = malloc(sizeof(char) * 2 + 1 + 1)))
		return (1);
	if (numarr[len - minus] == '1')
		set_num_19(dest, numarr, len, minus);
	else
		set_num(dest, numarr, len, minus);
	print = ft_strstr(dic, dest);
	while (*print != ':')
		print++;
	print++;
	print_dic(print);
	if (minus > 2)
		write(1, " ", 1);
	else if (numarr[len - minus] > '1' && numarr[len - 1] != '0')
		write(1, " ", 1);
	free(dest);
	return (0);
}
