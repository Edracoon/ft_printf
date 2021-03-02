/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_c.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epfennig <epfennig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/26 12:13:59 by epfennig          #+#    #+#             */
/*   Updated: 2021/02/26 15:13:20 by epfennig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void		ft_type_c(int argu, t_flags *flags)
{
	if (flags->flag_minus == 1)
	{
		ft_putchar(argu);
		if (flags->width > 1)
		{
			while (flags->width-- > 1)
				ft_putchar(' ');
		}
	}
	if (flags->flag_minus == 0)
	{
		while (flags->width-- > 1)
		{
			if (flags->flag_zero == 1)
				ft_putchar('0');
			else
				ft_putchar(' ');
		}
		ft_putchar(argu);
	}
}
