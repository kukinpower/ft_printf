/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_hex_lower.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkristie <kukinpower@ya.ru>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/06 13:46:16 by mkristie          #+#    #+#             */
/*   Updated: 2020/06/09 19:58:11 by mkristie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	is_hex_lower(t_go *sv, char c)
{
	int		i;

	i = 0;
	if (c == 'x')
	{
		while (sv->temp[i])
		{
			if (ft_isalpha(sv->temp[i]))
				sv->temp[i] = ft_tolower(sv->temp[i]);
			i++;
		}
	}
}
