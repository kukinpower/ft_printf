/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_t_go.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkristie <kukinpower@ya.ru>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/03 08:48:22 by mkristie          #+#    #+#             */
/*   Updated: 2020/06/09 20:01:37 by mkristie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	free_t_go(t_go *sv)
{
	sv->i = 0;
	sv->remember_len = 0;
	sv->ret_len = 0;
	sv->chrzero = 0;
	sv->onemoreflag = 0;
	if (sv->toprint != NULL)
		ft_free_and_clear(sv->toprint);
	if (sv->fmt != NULL)
		ft_free_and_clear(sv->fmt);
	if (sv->wd != NULL)
		ft_free_and_clear(sv->wd);
	if (sv->pr != NULL)
		ft_free_and_clear(sv->pr);
	if (sv->temp != NULL)
		ft_free_and_clear(sv->temp);
	free(sv);
	return (-1);
}
