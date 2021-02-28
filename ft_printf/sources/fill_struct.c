/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epfennig <epfennig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/26 11:31:31 by epfennig          #+#    #+#             */
/*   Updated: 2021/02/26 16:38:04 by epfennig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void		flag_minus(t_flags *flags)
{
	flags->flag_minus = 1;
	flags->flag_zero = 0;
}

void		flag_nombre(char nb, t_flags *flags)
{
	if (flags->star == 1)
		flags->width = 0;
	flags->width = (flags->width * 10) + (nb - '0');
}

void		flag_width(va_list args, t_flags *flags)
{
	flags->star = 1;
	flags->width = va_arg(args, int);
	if (flags->width < 0)
	{
		flags->flag_minus = 1;
		flags->width *= -1;
		flags->flag_zero = 0;
	}
}

int			flag_dot(const char *str, int start,
			t_flags *flags, va_list args)
{
	int i;

	i = start + 1;
	if (str[i] == '*')
	{
		flags->dot = va_arg(args, int);
		i++;
	}
	else
	{
		flags->dot = 0;
		while (ft_isdigit(str[i]))
			flags->dot = (flags->dot * 10) + (str[i++] - '0');
	}
	return (i);
}
