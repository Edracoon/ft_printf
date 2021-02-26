/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_c.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epfennig <epfennig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/26 12:13:59 by epfennig          #+#    #+#             */
/*   Updated: 2021/02/26 13:13:05 by epfennig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void		ft_type_c(int argu, t_flags *flags)
{
	if (flags->flag_minus == 1)
		ft_putchar(argu);
	if (flags->width > 1)
	{
		while (flags->width-- > 1)
			ft_putchar(' ');
	}
	if (flags->star != 0)
	{
		while (flags->star-- > 1)
			ft_putchar(' ');
	}
	if (flags->flag_minus == 0)
		ft_putchar(argu);
	if (flags->star < 0)
	{
		while (flags->star++ < -2)
			ft_putchar(' ');
	}
}
