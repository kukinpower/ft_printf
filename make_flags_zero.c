/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_flags_zero.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkristie <kukinpower@ya.ru>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/03 16:44:05 by mkristie          #+#    #+#             */
/*   Updated: 2020/06/11 16:14:04 by mkristie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	make_flags_zero(t_go *sv)
{
	sv->width = 0;
	sv->precision = 0;
	sv->f_min_wd = 0;
	sv->f_min_pr = 0;
	sv->f_zero = 0;
	sv->f_dot = 0;
	sv->f_ast_wd = 0;
	sv->f_ast_pr = 0;
	sv->d_num = 0;
	sv->u_num = 0;
	sv->d_spec = 0;
	sv->u_spec = 0;
	sv->base = 0;
	sv->pr = NULL;
	sv->wd = NULL;
	sv->temp = NULL;
}
