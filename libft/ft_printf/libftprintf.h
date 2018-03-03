/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelest <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/04 15:19:03 by ndelest           #+#    #+#             */
/*   Updated: 2018/02/17 19:38:06 by ndelest          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include <limits.h>
# include <wchar.h>
# include "../srcs_libft/includes/libft.h"

typedef union				u_typearg
{
	int						i;
	short int				shi;
	long int				li;
	long long int			lli;
	intmax_t				im;
	ssize_t					sszi;
	unsigned int			ui;
	unsigned short int		ushi;
	unsigned long int		uli;
	unsigned long long int	ulli;
	uintmax_t				uim;
	unsigned char			uc;
	size_t					szi;
	char					c;
	wint_t					wc;
	wchar_t					*ws;
}							t_typearg;
typedef	struct				s_arg
{
	char					type;
	char					flags[5];
	char					conv[4];
	int						minfield;
	int						precision;
	unsigned char			buffer[BUFF_SIZE];
	int						index;
	int						last_arg;
	int						len;
	char					*stock;
	size_t					type_len;
	t_typearg				typearg;
}							t_arg;
int							ft_printf(const char *format, ...);
int							ft_signedint(va_list ap, t_arg *arg);
int							ft_unsignedint(va_list ap, t_arg *arg, int base);
char						*ft_imtoa(intmax_t n);
char						*ft_uitoa_base(uintmax_t n, int base);
void						ft_putwchar(unsigned int a, int size, t_arg *arg);
unsigned int				ft_itowchar(wint_t wi, size_t *len);
int							d_arg(t_arg *arg, va_list ap);
int							bigd_arg(t_arg *arg, va_list ap);
int							u_arg(t_arg *arg, va_list ap);
int							bigu_arg(t_arg *arg, va_list ap);
int							o_arg(t_arg *arg, va_list ap);
int							bigo_arg(t_arg *arg, va_list ap);
int							x_arg(t_arg *arg, va_list ap);
int							bigx_arg(t_arg *arg, va_list ap);
int							p_arg(t_arg *arg, va_list ap);
int							c_arg(t_arg *arg, va_list ap);
int							bigc_arg(t_arg *arg, va_list ap);
int							s_arg(t_arg *arg, va_list ap);
int							bigs_arg(t_arg *arg, va_list ap);
int							pct_arg(t_arg *arg);
int							b_arg(t_arg *arg, va_list ap);
int							ft_nullstr_arg(t_arg *arg);
int							ft_conv_distribution(t_arg *arg, va_list ap);
void						ft_strcapitalize(char *str);
void						ft_argreset(t_arg *arg);
t_arg						ft_arginit(void);
void						ft_printbuffer(t_arg *arg);
void						ft_putbuffer(t_arg *arg, unsigned char c);
void						ft_fillflags(const char *format, int *i,
											t_arg *arg);
void						ft_fillfields(const char *format, int *i,
											t_arg *arg);
int							ft_fillconv(const char *format, int *i, t_arg *arg);
void						ft_putfield(t_arg *arg, char c, int opt);
void						ft_putflagsnb(t_arg *arg);
void						ft_putflagstring(t_arg *arg);
void						ft_putflagschar(t_arg *arg, size_t type_len);
int							ft_error(t_arg *arg, va_list ap);
#endif
