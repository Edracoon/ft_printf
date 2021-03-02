/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_s.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epfennig <epfennig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/26 12:24:42 by epfennig          #+#    #+#             */
/*   Updated: 2021/02/26 15:13:24 by epfennig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void		minus_1_s(char *argu, t_flags *flags)
{
	if (flags->flag_minus == 1)
	{
		if (flags->dot >= 0)
		{
			while (flags->dot - ft_strlen(argu) > 0)
			{
				ft_putchar(' ');
				flags->dot--;
			}
			ft_putstr(argu, flags->dot);
		}
		else
			ft_putstr(argu, ft_strlen(argu));
	}
}

void		minus_0_s(char *argu, t_flags *flags)
{
	if (flags->flag_minus == 0)
	{
		if (flags->dot >= 0)
		{
			while (flags->dot - ft_strlen(argu) > 0)
			{
				ft_putchar(' ');
				flags->dot--;
			}
			ft_putstr(argu, flags->dot);
		}
		else
			ft_putstr(argu, ft_strlen(argu));
	}
}

void		ft_type_s(char *argu, t_flags *flags)
{
	if (argu == NULL)
		argu = "(null)";
	if (flags->dot >= 0 && flags->dot > ft_strlen(argu))
		flags->dot = ft_strlen(argu);
	minus_1_s(argu, flags);
	if (flags->dot >= 0)
	{
		while (flags->width - flags->dot > 0)
		{
			ft_putchar(' ');
			flags->width--;
		}
	}
	else
	{
		while (flags->width - ft_strlen(argu) > 0)
		{
			ft_putchar(' ');
			flags->width--;
		}
	}
	minus_0_s(argu, flags);
}
