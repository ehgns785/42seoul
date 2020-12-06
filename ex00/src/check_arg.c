/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gseobang <gseobang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 17:10:39 by gseobang          #+#    #+#             */
/*   Updated: 2020/12/06 18:10:01 by gseobang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../head/dictionary.h"

int		check_arg(int argc, char *str)
{
	int	i;

	if (argc >= 4 || argc <= 0)
		return (1);
	if (argc == 1)
		return (0);
	i = -1;
	if (argc == 2 || argc == 3)
	{
		while (str[++i] != '\0')
		{
			if (!((str[i] >= '0') && (str[i] <= '9')))
				return (1);
		}
	}
	return (0);
}

int		error(void)
{
	write(1, "Error\n", 6);
	return (0);
}
