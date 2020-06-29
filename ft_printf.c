/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkristie <kukinpower@ya.ru>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/29 19:38:40 by mkristie          #+#    #+#             */
/*   Updated: 2020/06/11 16:39:41 by mkristie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

/*
** fmt spec construction:
** %[flags][width][.precision][length]type
** To do mandatory:
** Conversions:	[cspdiuxX%]
** Flags:		[-0.*] and minimum field width with all conversions
*/

_Bool	chrzero_print(t_go *sv)
{
	if (sv->chrzero == 1)
	{
		write(1, sv->toprint, sv->remember_len);
		ft_free_and_clear(sv->toprint);
		if (!(sv->toprint = ft_strdup("")))
			return (0);
		sv->ret_len += sv->remember_len;
		sv->remember_len = 0;
		sv->chrzero = 0;
	}
	return (1);
}

_Bool	check_conversion(va_list args, char c, t_go *sv)
{
	char	tempchr[2];

	if (c == 'd' || c == 'i')
		return (handle_d(args, sv) != 0 ? 1 : 0);
	else if (c == 's' || c == 'c' || c == '%')
		return (handle_s(args, sv->fmt[sv->i], sv) != 0 ? 1 : 0);
	else if (c == 'p')
		return (handle_p(args, sv) != 0 ? 1 : 0);
	else if (c == 'u')
		return (handle_u(args, sv) != 0 ? 1 : 0);
	else if (c == 'x' || c == 'X')
		return (handle_x(args, c, sv) != 0 ? 1 : 0);
	else
	{
		tempchr[0] = c;
		tempchr[1] = '\0';
		if (!(sv->toprint = ft_strjoin_free(sv->toprint, tempchr, 0)))
			return (0);
	}
	return (1);
}

_Bool	oper_utils(va_list args, t_go *sv)
{
	sv->click = 1;
	if (sv->onemoreflag == 0)
	{
		if (!(sv->operate_temp = ft_substr(sv->fmt, 0, sv->l)))
			return (0);
	}
	else if (!(sv->operate_temp =
			ft_substr(sv->fmt, sv->i - (int)sv->l, sv->l)))
		return (0);
	if (!(sv->toprint = ft_strjoin_free(sv->toprint, sv->operate_temp, 0)))
		return (0);
	sv->operate_temp = ft_free_and_clear(sv->operate_temp);
	sv->i++;
	if (!(check_flag(args, sv)))
		return (0);
	if (!(check_conversion(args, sv->fmt[sv->i], sv)))
		return (0);
	if (!chrzero_print(sv))
		return (0);
	sv->l = 0;
	sv->onemoreflag = 1;
	return (1);
}

int		operate_fmt(va_list args, t_go *sv)
{
	while (sv->fmt[sv->i] != '\0')
	{
		if (sv->fmt[sv->i] == '%')
		{
			if (!(oper_utils(args, sv)))
				return (-1);
		}
		if (sv->click == 0)
			sv->l++;
		if (sv->click == 1)
			sv->click = 0;
		sv->i++;
	}
	if (sv->click == 0)
	{
		if (!(sv->operate_temp = ft_substr(sv->fmt, sv->i - sv->l, sv->l)))
			return (-1);
		if (!(sv->toprint = ft_strjoin_free(sv->toprint, sv->operate_temp, 0)))
			return (-1);
		sv->operate_temp = ft_free_and_clear(sv->operate_temp);
		return (ft_strlen(sv->toprint));
	}
	return (0);
}

int		ft_printf(const char *format_str_input, ...)
{
	va_list		args;
	t_go		*sv;
	int			result_len;

	if (!(sv = malloc(sizeof(t_go))))
		return (-1);
	if (!(init_go(sv, (void *)format_str_input)))
		return (free_t_go(sv));
	va_start(args, format_str_input);
	result_len = operate_fmt(args, sv);
	if (result_len != -1)
	{
		write(1, sv->toprint, result_len);
		result_len += sv->ret_len;
	}
	free_t_go(sv);
	va_end(args);
	return (result_len);
}
