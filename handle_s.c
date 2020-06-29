/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_s.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkristie <kukinpower@ya.ru>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/01 17:35:19 by mkristie          #+#    #+#             */
/*   Updated: 2020/06/11 16:05:06 by mkristie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

_Bool	handling_s(va_list args, t_go *sv)
{
	char	*strarg;

	strarg = va_arg(args, char *);
	if (strarg == NULL)
	{
		if (!(sv->temp = ft_strdup("(null)")))
			return (0);
	}
	else
	{
		if (!(sv->temp = ft_strdup(strarg)))
			return (0);
	}
	if (sv->f_dot == 1 && sv->precision == 0)
	{
		sv->temp = ft_free_and_clear(sv->temp);
		if (!(sv->temp = ft_strdup("")))
			return (0);
	}
	return (1);
}

_Bool	handling_c(va_list args, t_go *sv)
{
	if (sv->f_dot == 1 && sv->precision == 0)
	{
		if (!(sv->temp = ft_strdup("")))
			return (0);
	}
	else
	{
		if (!(sv->temp = malloc(sizeof(char) * 2)))
			return (0);
		sv->temp[0] = (char)va_arg(args, int);
		if (sv->temp[0] == '\0')
			sv->chrzero = 1;
		sv->temp[1] = '\0';
	}
	return (1);
}

_Bool	handle_percent(t_go *sv)
{
	if (!(sv->temp = malloc(sizeof(char) * 2)))
		return (0);
	sv->temp[0] = '%';
	sv->temp[1] = '\0';
	return (1);
}

_Bool	utils_s(t_go *sv)
{
	if (sv->width > 0 && sv->width > (int)ft_strlen(sv->temp))
	{
		if (!(handle_width_s(sv)))
			return (0);
	}
	else if (sv->f_dot > 0 && sv->precision == 0)
	{
		if (!(sv->toprint = ft_strjoin_free(sv->toprint, "", 0)))
			return (0);
	}
	else if (sv->chrzero == 1 && sv->width == 0 && sv->f_dot == 0)
		sv->remember_len = (int)ft_strlen(sv->toprint) + 1;
	else
	{
		if (!(sv->toprint = ft_strjoin_free(sv->toprint, sv->temp, 0)))
			return (0);
	}
	return (1);
}

_Bool	handle_s(va_list args, char c, t_go *sv)
{
	if (c == 's')
	{
		if (!(handling_s(args, sv)))
			return (0);
	}
	else if (c == 'c')
	{
		if (!(handling_c(args, sv)))
			return (0);
	}
	else if (c == '%')
	{
		if (!(handle_percent(sv)))
			return (0);
	}
	if (sv->precision > 0 && sv->precision < (int)ft_strlen(sv->temp))
	{
		if (!(handle_precision_s(sv)))
			return (0);
	}
	if (!(utils_s(sv)))
		return (0);
	sv->temp = ft_free_and_clear(sv->temp);
	make_flags_zero(sv);
	return (1);
}
