/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_width_s.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkristie <kukinpower@ya.ru>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/05 14:14:45 by mkristie          #+#    #+#             */
/*   Updated: 2020/06/11 15:49:22 by mkristie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

_Bool	wd_alloc_s(t_go *sv, char c)
{
	if (!(sv->wd = malloc(sizeof(char) * (sv->width + 1))))
		return (0);
	ft_memset(sv->wd, c, sv->width);
	sv->wd[sv->width] = '\0';
	return (1);
}

_Bool	width_s_utils(t_go *sv)
{
	if (!(sv->toprint = ft_strjoin_free(sv->toprint, sv->wd, 0)))
		return (0);
	if (sv->chrzero > 0)
	{
		sv->remember_len = (int)ft_strlen(sv->toprint);
		if (sv->f_min_wd > 0 && sv->f_min_wd == 0)
			sv->toprint[0] = '\0';
		else if (sv->f_min_wd == 0)
			sv->toprint[sv->remember_len - 1] = '\0';
		else
			sv->toprint[sv->remember_len - sv->width] = '\0';
	}
	sv->wd = ft_free_and_clear(sv->wd);
	return (1);
}

_Bool	handle_width_s(t_go *sv)
{
	size_t		start;

	if (sv->f_zero > 0 && sv->f_min_wd == 0)
	{
		if (!(wd_alloc_s(sv, '0')))
			return (0);
	}
	else
	{
		if (!(wd_alloc_s(sv, ' ')))
			return (0);
	}
	if (sv->chrzero == 0)
	{
		if (sv->f_min_wd > 0)
			ft_memmove(sv->wd, sv->temp, ft_strlen(sv->temp));
		else
		{
			start = ft_strlen(sv->wd) - ft_strlen(sv->temp);
			ft_memmove(sv->wd + start, sv->temp, ft_strlen(sv->temp));
		}
	}
	if (!(width_s_utils(sv)))
		return (0);
	return (1);
}
