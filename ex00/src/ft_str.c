/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gseobang <gseobang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 17:10:39 by gseobang          #+#    #+#             */
/*   Updated: 2020/12/06 18:22:31 by gseobang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../head/dictionary.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		ft_strlen(char *str)
{
	int cnt;

	cnt = 0;
	while (*str)
	{
		cnt++;
		str++;
	}
	return (cnt);
}

char	*ft_strstr(char *str, char *to_find)
{
	int		i;
	char	*temp;

	if (*to_find == '\0')
		return (str);
	temp = to_find;
	i = -1;
	while (*str)
	{
		if (*str != *to_find)
		{
			i = -1;
			to_find = temp;
		}
		if (*str == *to_find)
		{
			to_find++;
			i++;
			if (*to_find == '\0')
				return (str - i);
		}
		str++;
	}
	return (0);
}
