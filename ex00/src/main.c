/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gseobang <gseobang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 17:10:39 by gseobang          #+#    #+#             */
/*   Updated: 2020/12/06 18:33:18 by gseobang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../head/check_arg.h"
#include "../head/dictionary.h"
#include "../head/ft_str.h"
#include "../head/trans.h"

void	dict_print(char *buf)
{
	int	i;

	i = 0;
	while (buf[i] != '\0')
		ft_putchar(buf[i++]);
}

int		main(int argc, char **argv)
{
	char	*dic_name;
	char	buffer[10000];
	char	sort_dic[10000];
	int		fd;

	if (check_arg(argc, argv[argc - 1]))
		return (error());
	if (argc == 1)
	{
		fd = open("numbers.dict", O_RDONLY);
		buffer[read(fd, buffer, 10000)] = '\0';
		dict_print(buffer);
		close(fd);
		return (0);
	}
	dic_name = (argc == 2) ? "numbers.dict" : argv[1];
	if (make_dic(dic_name, buffer, sort_dic))
		return (0);
	if (translate(argv[argc - 1], sort_dic))
		return (error());
	write(1, "\n", 1);
}
