/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_go.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkristie <kukinpower@ya.ru>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/03 08:27:01 by mkristie          #+#    #+#             */
/*   Updated: 2020/06/11 12:16:52 by mkristie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	*init_go(t_go *sv, void *format_str_input)
{
	if (!(sv->toprint = ft_strdup("")))
		return (NULL);
	if (!(sv->fmt = ft_strdup(format_str_input)))
		return (NULL);
	sv->operate_temp = NULL;
	make_flags_zero(sv);
	sv->click = 0;
	sv->l = 0;
	sv->onemoreflag = 0;
	sv->i = 0;
	sv->chrzero = 0;
	sv->remember_len = 0;
	sv->f_zero_rem = 0;
	sv->ret_len = 0;
	return (sv->fmt);
}
