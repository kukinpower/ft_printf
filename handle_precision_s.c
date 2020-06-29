/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_precision_s.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkristie <kukinpower@ya.ru>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/05 14:27:38 by mkristie          #+#    #+#             */
/*   Updated: 2020/06/09 19:49:52 by mkristie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

_Bool	handle_precision_s(t_go *sv)
{
	sv->d_spec = 1;
	if (!(sv->pr = malloc(sizeof(char) * (sv->precision + 1))))
		return (0);
	sv->pr[sv->precision] = '\0';
	ft_memmove(sv->pr, sv->temp, sv->precision);
	sv->temp = ft_free_and_clear(sv->temp);
	if (!(sv->temp = ft_strdup(sv->pr)))
		return (0);
	sv->pr = ft_free_and_clear(sv->pr);
	return (1);
}
