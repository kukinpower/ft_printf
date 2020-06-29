/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_p.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkristie <kukinpower@ya.ru>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/01 17:44:32 by mkristie          #+#    #+#             */
/*   Updated: 2020/06/11 12:35:19 by mkristie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*hex_tolower_and_add_zerox(char *hexadecimal)
{
	int	i;

	i = 0;
	while (hexadecimal[i])
	{
		if (ft_isalpha(hexadecimal[i]))
			hexadecimal[i] = ft_tolower(hexadecimal[i]);
		i++;
	}
	return (ft_strjoin_free("0x", hexadecimal, 1));
}

_Bool	p_utils(t_go *sv)
{
	if (!(sv->temp = hex_tolower_and_add_zerox(sv->temp)))
		return (0);
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
	else if ((sv->width == 0 && sv->u_spec == 0 && \
				sv->f_dot == 0) || sv->u_spec == 1)
	{
		if (!(sv->toprint = ft_strjoin_free(sv->toprint, sv->temp, 0)))
			return (0);
	}
	return (1);
}

_Bool	handle_p(va_list args, t_go *sv)
{
	sv->base = 16;
	if (sv->f_dot == 1 && sv->precision == 0)
	{
		if (!(sv->temp = ft_strdup("")))
			return (0);
	}
	else
	{
		if (!(sv->temp = ft_itoa_base(va_arg(args, unsigned long long), 16)))
			return (0);
	}
	if (!(p_utils(sv)))
		return (0);
	sv->temp = ft_free_and_clear(sv->temp);
	make_flags_zero(sv);
	return (1);
}
