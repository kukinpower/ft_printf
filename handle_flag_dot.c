/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_flag_dot.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkristie <kukinpower@ya.ru>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/12 11:45:30 by mkristie          #+#    #+#             */
/*   Updated: 2020/06/12 11:46:38 by mkristie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void		handle_flag_dot(t_go *sv)
{
	sv->f_dot = 1;
	if (sv->f_zero == 1)
	{
		sv->f_zero_rem = 1;
		sv->f_zero = 0;
	}
}
