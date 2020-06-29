/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_flag.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkristie <kukinpower@ya.ru>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 10:24:15 by mkristie          #+#    #+#             */
/*   Updated: 2020/06/11 12:35:35 by mkristie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

_Bool		isflag_or_space(char c)
{
	return (c == ' ' || c == '-' || c == '0' || c == '.' || \
			c == '*' || ft_isdigit(c));
}

_Bool		handle_specs(t_go *sv)
{
	int		start;
	int		len;
	char	*num;

	start = sv->i;
	len = start;
	while (ft_isdigit(sv->fmt[len]))
	{
		len++;
		sv->i++;
	}
	if (!(num = ft_substr(sv->fmt, start, len - start)))
		return (0);
	if (sv->f_dot == 0)
		sv->width = ft_atoi(num);
	else
		sv->precision = ft_atoi(num);
	num = ft_free_and_clear(num);
	return (1);
}

void		asterisk_replace(va_list args, t_go *sv, char c)
{
	if (c == 'w')
	{
		sv->f_ast_wd = 1;
		sv->width = va_arg(args, int);
		if (sv->width < 0)
		{
			sv->width = sv->width * -1;
			sv->f_min_wd = 1;
			sv->f_zero = 0;
		}
	}
	else if (c == 'p')
	{
		sv->f_ast_pr = 1;
		sv->precision = va_arg(args, int);
	}
}

_Bool		dot_and_asterisk(va_list args, t_go *sv)
{
	if (sv->fmt[sv->i] == '-' && sv->f_min_wd == 0 && sv->f_dot == 0)
		sv->f_min_wd = 1;
	else if (sv->fmt[sv->i] == '-' && sv->f_min_pr == 0 && sv->f_dot == 1)
		sv->f_min_wd = 1;
	else if (sv->fmt[sv->i] == '0' && sv->f_zero == 0 && sv->f_dot == 0)
		sv->f_zero = 1;
	else if (sv->fmt[sv->i] == '.' && sv->f_dot == 0)
		handle_flag_dot(sv);
	else if (sv->fmt[sv->i] == '*' && sv->f_ast_wd == 0 && sv->f_dot == 0)
		asterisk_replace(args, sv, 'w');
	else if (sv->fmt[sv->i] == '*' && sv->f_dot > 0 && sv->f_ast_pr == 0)
		asterisk_replace(args, sv, 'p');
	else if (ft_isdigit(sv->fmt[sv->i]))
	{
		if (!(handle_specs(sv)))
			return (0);
		sv->i--;
	}
	return (1);
}

_Bool		check_flag(va_list args, t_go *sv)
{
	while (isflag_or_space(sv->fmt[sv->i]))
	{
		if (sv->fmt[sv->i] == ' ')
		{
			if (!(sv->toprint = ft_strjoin_free(sv->toprint, " ", 0)))
				return (0);
		}
		if (!(dot_and_asterisk(args, sv)))
			return (0);
		sv->i++;
	}
	if (sv->width > sv->precision && sv->f_zero_rem == 1 && sv->precision < 0)
		sv->f_zero = 1;
	return (1);
}
