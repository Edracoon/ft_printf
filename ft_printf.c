/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epfennig <epfennig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 12:59:39 by marvin            #+#    #+#             */
/*   Updated: 2021/03/04 16:55:04 by epfennig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

/*
** I used a global variable to make easier
** the return value of printf.
*/
int		g_count;

void			ft_putchar(char c)
{
	write(1, &c, 1);
	g_count++;
}

int				ft_check_type(va_list args,
					t_flags *flags)
{
	if (flags->type == 'd' || flags->type == 'i')
		ft_type_di(va_arg(args, int), flags);
	if (flags->type == 'c')
		ft_type_c(va_arg(args, int), flags);
	if (flags->type == 's')
		ft_type_s(va_arg(args, char *), flags);
	if (flags->type == 'x')
		ft_type_x(va_arg(args, unsigned int), flags);
	if (flags->type == 'X')
		ft_type_x1(va_arg(args, unsigned int), flags);
	if (flags->type == 'u')
		ft_type_u(va_arg(args, unsigned int), flags);
	if (flags->type == 'p')
		ft_type_p(va_arg(args, unsigned long long int), flags);
	if (flags->type == '%')
		ft_type_c('%', flags);
	return (0);
}

void			parse_flag(const char *str, int i, va_list args, t_flags *flags)
{
	while (str[i])
	{
		if (!ft_isdigit(str[i]) && !find_type(str[i])
		&& !find_flag(str[i]))
			break ;
		if (str[i] == '0' && flags->width == 0 && flags->flag_minus == 0)
			flags->flag_zero = 1;
		if (str[i] == '.')
			i = flag_dot(str, i, flags, args);
		if (str[i] == '-')
			flag_minus(flags);
		if (str[i] == '*')
			flag_width(args, flags);
		if (ft_isdigit(str[i]))
			flag_nombre(str[i], flags);
		if (find_type(str[i]))
		{
			flags->type = str[i];
			break ;
		}
		i++;
	}
	ft_check_type(args, flags);
}

t_flags			*struct_init(t_flags *flags)
{
	flags->flag_minus = 0;
	flags->flag_zero = 0;
	flags->width = 0;
	flags->dot = -1;
	flags->star = 0;
	flags->type = 0;
	return (flags);
}

int				ft_printf(const char *str, ...)
{
	va_list		args;
	int			i;
	t_flags		*flags;

	g_count = 0;
	if (!(flags = malloc(sizeof(t_flags))))
		return (-1);
	va_start(args, str);
	i = -1;
	while (str[++i])
	{
		if (str[i] == '%')
		{
			i++;
			parse_flag(str, i, args, struct_init(flags));
			i = len_option(str, i);
		}
		else
			ft_putchar(str[i]);
	}
	free(flags);
	va_end(args);
	return (g_count);
}
