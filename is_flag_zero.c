/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_flag_zero.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkristie <kukinpower@ya.ru>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/04 13:19:20 by mkristie          #+#    #+#             */
/*   Updated: 2020/06/11 12:35:19 by mkristie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	is_flag_zero(t_go *sv, char *wd, char *temp)
{
	if (sv->f_zero > 0 && sv->f_min_wd == 0 && \
		sv->precision == 0 && sv->f_ast_pr == 0 && sv->d_num != 0)
		ft_memset(wd, '0', sv->width - ft_strlen(temp));
	else
		ft_memset(wd, ' ', sv->width - ft_strlen(temp));
}
