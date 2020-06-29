/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_width.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkristie <kukinpower@ya.ru>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/05 14:14:45 by mkristie          #+#    #+#             */
/*   Updated: 2020/06/11 12:42:02 by mkristie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

_Bool	wd_alloc(t_go *sv, char c)
{
	if (!(sv->wd = malloc(sizeof(char) * (sv->width + 1))))
		return (0);
	ft_memset(sv->wd, c, sv->width);
	sv->wd[sv->width] = '\0';
	return (1);
}

_Bool	handle_width_util(t_go *sv)
{
	size_t		start;

	if (sv->f_zero > 0 && sv->f_min_wd == 0)
	{
		if (!(wd_alloc(sv, '0')))
			return (0);
	}
	else
	{
		if (!(wd_alloc(sv, ' ')))
			return (0);
	}
	if (sv->f_min_wd > 0)
		ft_memmove(sv->wd, sv->temp, ft_strlen(sv->temp));
	else
	{
		start = ft_strlen(sv->wd) - ft_strlen(sv->temp);
		ft_memmove(sv->wd + start, sv->temp, ft_strlen(sv->temp));
		if (sv->precision <= 0 && sv->d_num < 0 && sv->wd[0] == '0')
			sv->wd[0] = '-';
	}
	if (!(sv->toprint = ft_strjoin_free(sv->toprint, sv->wd, 0)))
		return (0);
	sv->wd = ft_free_and_clear(sv->wd);
	return (1);
}

_Bool	one_more_case(va_list args, t_go *sv)
{
	sv->d_num = va_arg(args, int);
	if (sv->d_num != 0 || (sv->width > 0 && sv->d_num == 0 && sv->f_dot == 0))
	{
		if (!(sv->temp = ft_itoa(sv->d_num)))
			return (0);
	}
	else
	{
		if (!(sv->temp = ft_strdup("")))
			return (0);
	}
	return (1);
}

_Bool	width_utils_two(va_list args, t_go *sv)
{
	if (sv->d_spec == 0 && sv->f_zero > 0 && sv->f_min_wd == 0)
	{
		sv->d_num = va_arg(args, int);
		if (!(sv->temp = ft_itoa_u(sv->d_num)))
			return (0);
		if (sv->width <= (int)ft_strlen(sv->temp) && sv->d_num < 0)
		{
			if (!(sv->temp = ft_strjoin_free("-", sv->temp, 1)))
				return (0);
		}
	}
	else if (sv->d_spec == 0 && sv->f_zero == 0)
	{
		if (!(one_more_case(args, sv)))
			return (0);
	}
	return (1);
}

_Bool	handle_width(va_list args, t_go *sv)
{
	if (!(width_utils_two(args, sv)))
		return (0);
	if (sv->width > (int)ft_strlen(sv->temp))
	{
		if (!(handle_width_util(sv)))
			return (0);
	}
	else
	{
		if (!(sv->toprint = ft_strjoin_free(sv->toprint, sv->temp, 0)))
			return (0);
		sv->temp = ft_free_and_clear(sv->temp);
	}
	return (1);
}
