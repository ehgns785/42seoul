/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trans_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gseobang <gseobang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 17:10:39 by gseobang          #+#    #+#             */
/*   Updated: 2020/12/06 17:14:11 by gseobang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../head/dictionary.h"
#include "../head/ft_str.h"
#include "../head/trans.h"

int	print_num_to_100(char *numarr, char *dic, int len, int minus)
{
	char *dest;
	char *print;

	if (numarr[len - minus] == '0')
		return (0);
	else
		once_print(numarr, dic, len - minus);
	write(1, " ", 1);
	if (!(dest = malloc(sizeof(char) * 3 + 1 + 1)))
		return (1);
	dest[0] = '1';
	dest[1] = '0';
	dest[2] = '0';
	dest[3] = ':';
	dest[4] = '\0';
	print = ft_strstr(dic, dest);
	while (*print != ':')
		print++;
	print++;
	print_dic(print);
	write(1, " ", 1);
	free(dest);
	return (0);
}

int	print_num_to_end(char *numarr, char *dic, int len, int minus)
{
	char *dest;
	char *print;

	if (numarr[len - minus] == '0' || numarr[len - minus - 1] == '1')
		return (0);
	if (!(dest = malloc(sizeof(char) * 1 + 1 + 1)))
		return (1);
	dest[0] = numarr[len - minus];
	dest[1] = ':';
	dest[2] = '\0';
	print = ft_strstr(dic, dest);
	while (*print != ':')
		print++;
	print++;
	print_dic(print);
	free(dest);
	return (0);
}

int	check_pass(char *numarr, int len, int minus)
{
	if (len - minus > 2 && numarr[len - minus] == '0'
	&& numarr[len - minus - 1] == '0'
	&& numarr[len - minus - 2] == '0')
		return (1);
	return (0);
}
