/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epfennig <epfennig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 12:58:34 by marvin            #+#    #+#             */
/*   Updated: 2021/02/26 10:55:29 by epfennig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct	s_flags
{
	int			flag_minus;
	int			flag_zero;
	int			width;
	int			dot;
	int			star;
	char		type;
}				t_flags;

int				ft_printf(const char *str, ...);
void			ft_type_di(int argu, t_flags *flags);
void			ft_type_c(int argu, t_flags *flags);
void			ft_type_s(char *argu, t_flags *flags);
void			ft_type_x(unsigned int argu, t_flags *flags);
void			ft_type_x1(unsigned int argu, t_flags *flags);
void			ft_type_u(unsigned int argu, t_flags *flags);
void			ft_type_p(unsigned long long argu, t_flags *flags);

int				ft_atoi(const char *str);
char			*ft_itoa(long int n);
char			*ft_upxtoa(unsigned long long n, int base);
char			*ft_strdup(char *src);

int				ft_isdigit(int c);
int				ft_tolower(int c);
int				ft_strlen(char *str);
void			ft_putchar(char c);
void			ft_putstr(char *str, int len);

#endif
