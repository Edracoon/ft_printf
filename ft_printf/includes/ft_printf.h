/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epfennig <epfennig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 12:58:34 by marvin            #+#    #+#             */
/*   Updated: 2021/02/26 15:01:07 by epfennig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct	s_flags
{
	int			flag_minus;
	int			flag_zero;
	int			width;
	int			dot;
	int			star;
	char		type;
}				t_flags;

t_flags			*struct_init(t_flags *flags);

int				ft_printf(const char *str, ...);
void			ft_type_di(int argu, t_flags *flags);
void			ft_type_c(int argu, t_flags *flags);
void			ft_type_s(char *argu, t_flags *flags);
void			ft_type_x(unsigned int argu, t_flags *flags);
void			ft_type_x1(unsigned int argu, t_flags *flags);
void			ft_type_u(unsigned int argu, t_flags *flags);
void			ft_type_p(unsigned long long argu, t_flags *flags);

void			ft_putchar(char c);

int				ft_atoi(const char *str);
int				ft_isdigit(int c);
char			*ft_itoa(long int n);
void			ft_putstr(char *str, int len);
char			*ft_strdup(char *src);
int				ft_strlen(char *str);
int				ft_tolower(int c);
char			*ft_upxtoa(unsigned long long n, int base);

int				find_type(int c);
int				find_flag(int c);
int				len_option(const char *str, int i);

void			flag_minus(t_flags *flags);
void			flag_nombre(char nb, t_flags *flags);
void			flag_width(va_list args, t_flags *flags);
int				flag_dot(const char *str, int start,
				t_flags *flags, va_list args);

#endif
