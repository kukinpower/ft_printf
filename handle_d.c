/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_d.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkristie <kukinpower@ya.ru>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/01 17:42:04 by mkristie          #+#    #+#             */
/*   Updated: 2020/06/11 16:44:01 by mkristie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void		*check_int_max(int num)
{
	char	*res;

	if (num == 2147483647)
		res = ft_strdup("2147483647");
	else if (num == -2147483648)
		res = ft_strdup("-2147483648");
	else
		res = ft_itoa(num);
	if (!res)
		return (NULL);
	return (res);
}

_Bool		just_num(va_list args, t_go *sv)
{
	sv->d_num = va_arg(args, int);
	if (!(sv->d_num == 0 && sv->f_dot == 1 && sv->precision == 0))
	{
		if (!(sv->temp = check_int_max(sv->d_num)))
			return (0);
		if (!(sv->toprint = ft_strjoin_free(sv->toprint, sv->temp, 0)))
			return (0);
	}
	return (1);
}

_Bool		handle_d(va_list args, t_go *sv)
{
	if (sv->precision > 0)
	{
		if (!(handle_precision(args, sv)))
			return (0);
	}
	if (sv->width > 0)
	{
		if (!(handle_width(args, sv)))
			return (0);
	}
	else if (sv->width == 0 && sv->d_spec == 0)
	{
		if (!(just_num(args, sv)))
			return (0);
	}
	else if (sv->d_spec == 1)
	{
		if (!(sv->toprint = ft_strjoin_free(sv->toprint, sv->temp, 0)))
			return (0);
	}
	sv->temp = ft_free_and_clear(sv->temp);
	make_flags_zero(sv);
	return (1);
}
