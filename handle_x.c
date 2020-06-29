/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_x.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkristie <kukinpower@ya.ru>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/01 17:31:11 by mkristie          #+#    #+#             */
/*   Updated: 2020/06/12 11:46:12 by mkristie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*check_int_max_x(unsigned int num)
{
	char	*res;

	res = ft_itoa_base((unsigned long long int)num, 16);
	if (!res)
		return (NULL);
	return (res);
}

_Bool	utils_x(t_go *sv)
{
	if (sv->width > 0)
	{
		if (!(handle_width_u(sv)))
			return (0);
	}
	else if ((sv->width == 0 && sv->u_spec == 0 && sv->f_dot == 0) || \
			(sv->f_dot == 1 && sv->precision == 0 && sv->u_num != 0))
	{
		if (!(sv->toprint = ft_strjoin_free(sv->toprint, sv->temp, 0)))
			return (0);
	}
	else if (sv->u_spec == 1)
	{
		if (!(sv->toprint = ft_strjoin_free(sv->toprint, sv->temp, 0)))
			return (0);
	}
	return (1);
}

_Bool	handle_x(va_list args, char c, t_go *sv)
{
	sv->base = 16;
	sv->u_num = va_arg(args, unsigned int);
	if (sv->f_dot == 1 && sv->precision == 0 && sv->u_num == 0)
	{
		if (!(sv->temp = ft_strdup("")))
			return (0);
	}
	else
	{
		if (!(sv->temp = \
			ft_itoa_base((unsigned long long int)sv->u_num, sv->base)))
			return (0);
		is_hex_lower(sv, c);
	}
	if (sv->precision > 0 || sv->f_ast_pr > 0)
	{
		if (!(handle_precision_u(sv)))
			return (0);
	}
	if (!(utils_x(sv)))
		return (0);
	sv->temp = ft_free_and_clear(sv->temp);
	make_flags_zero(sv);
	return (1);
}
