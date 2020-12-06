/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trans.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gseobang <gseobang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 17:10:39 by gseobang          #+#    #+#             */
/*   Updated: 2020/12/06 17:13:01 by gseobang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TRANS_H
# define TRANS_H

void	print_dic(char *str);
void	one_zero(char *str, int count);
int		check_19_1(char *numarr, int len, int minus);
int		print_num_to_10(char *numarr, char *dic, int len, int minus);
int		print_num_to_100(char *numarr, char *dic, int len, int minus);
int		print_num_to_end(char *numarr, char *dic, int len, int minus);
int		once_print(char *numarr, char *dic, int pos);
int		check_pass(char *numarr, int len, int minus);
int		translate(char *numarr, char *dic);

#endif
