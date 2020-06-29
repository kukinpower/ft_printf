/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_u.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkristie <kukinpower@ya.ru>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/01 17:47:12 by mkristie          #+#    #+#             */
/*   Updated: 2020/06/11 17:30:32 by mkristie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*check_int_max_u(unsigned int num)
{
	char	*res;

	if (num == 4294967295)
		res = ft_strdup("4294967295");
	else
		res = ft_itoa_base((unsigned long long int)num, 10);
	if (!res)
		return (NULL);
	return (res);
}

_Bool	u_utils(t_go *sv)
{
	if (sv->precision > 0 || sv->f_ast_pr > 0)
	{
		if (!(handle_precision_u(sv)))
			return (0);
	}
	if (sv->width > 0)
	{
		if (!(handle_width_u(sv)))
			return (0);
	}
	else if ((sv->width == 0 && sv->u_spec == 0 && sv->f_dot == 0) || \
			(sv->f_dot == 1 && sv->precision == 0 && sv->u_num != 0) || \
			sv->u_spec == 1)
	{
		if (!(sv->toprint = ft_strjoin_free(sv->toprint, sv->temp, 0)))
			return (0);
	}
	return (1);
}

_Bool	handle_u(va_list args, t_go *sv)
{
	sv->base = 10;
	sv->u_num = va_arg(args, unsigned int);
	if (sv->f_dot == 1 && sv->precision == 0 && sv->u_num == 0)
	{
		if (!(sv->temp = ft_strdup("")))
			return (0);
	}
	else
	{
		if (!(sv->temp = check_int_max_u(sv->u_num)))
			return (0);
	}
	if (!(u_utils(sv)))
		return (0);
	sv->temp = ft_free_and_clear(sv->temp);
	make_flags_zero(sv);
	return (1);
}
