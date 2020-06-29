/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_precision.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkristie <kukinpower@ya.ru>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/05 14:27:38 by mkristie          #+#    #+#             */
/*   Updated: 2020/06/09 19:49:52 by mkristie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

_Bool		handle_precision(va_list args, t_go *sv)
{
	int		start;

	sv->d_num = va_arg(args, int);
	if (!(sv->temp = ft_itoa_u(sv->d_num)))
		return (0);
	sv->d_spec = 1;
	if (sv->precision > (int)ft_strlen(sv->temp))
	{
		if (!(sv->pr = malloc(sizeof(char) * (sv->precision + 1))))
			return (0);
		sv->pr[sv->precision] = '\0';
		ft_memset(sv->pr, '0', sv->precision);
		start = sv->precision - (int)ft_strlen(sv->temp);
		ft_memmove(sv->pr + start, sv->temp, ft_strlen(sv->temp));
		sv->temp = ft_free_and_clear(sv->temp);
		if (!(sv->temp = ft_strdup(sv->pr)))
			return (0);
		sv->pr = ft_free_and_clear(sv->pr);
	}
	if (sv->d_num < 0)
	{
		if (!(sv->temp = ft_strjoin_free("-", sv->temp, 1)))
			return (0);
	}
	return (1);
}
