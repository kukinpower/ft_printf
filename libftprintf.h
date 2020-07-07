/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romankukin <romankukin@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/29 22:42:42 by mkristie          #+#    #+#             */
/*   Updated: 2020/07/07 22:00:55 by romankukin       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H
# include "libft/libft/libft.h"
# include <stdarg.h>

typedef struct		s_go
{
	char			*toprint;
	char			*fmt;
	char			*wd;
	char			*pr;
	char			*temp;
	char			*operate_temp;
	size_t			l;
	int				width;
	int				precision;
	int				f_min_wd;
	int				f_min_pr;
	int				f_zero;
	int				f_zero_rem;
	int				f_dot;
	int				f_ast_wd;
	int				f_ast_pr;
	int				i;
	int				d_num;
	int				d_spec;
	unsigned int	u_num;
	unsigned int	u_spec;
	int				base;
	int				chrzero;
	int				remember_len;
	int				ret_len;
	int				onemoreflag;
	int				click;

}					t_go;

int					ft_printf(const char *fmt, ...);
_Bool				handle_s(va_list args, char c, t_go *sv);
_Bool				handle_d(va_list args, t_go *sv);
_Bool				handle_p(va_list args, t_go *sv);
_Bool				handle_u(va_list args, t_go *sv);
_Bool				handle_x(va_list args, char c, t_go *sv);
void				*init_go(t_go *sv, void *format_str_input);
int					free_t_go(t_go *sv);
void				make_flags_zero(t_go *sv);
void				is_flag_zero(t_go *sv, char *wd, char *temp);
_Bool				handle_precision(va_list args, t_go *sv);
_Bool				handle_width(va_list args, t_go *sv);
_Bool				handle_precision_u(t_go *sv);
_Bool				handle_width_u(t_go *sv);
_Bool				handle_precision_s(t_go *sv);
_Bool				handle_width_s(t_go *sv);
void				is_hex_lower(t_go *sv, char c);
_Bool				check_flag(va_list args, t_go *sv);
void				handle_flag_dot(t_go *sv);

#endif
