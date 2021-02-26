/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_upper_x.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epfennig <epfennig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/26 12:44:54 by epfennig          #+#    #+#             */
/*   Updated: 2021/02/26 15:13:26 by epfennig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void		minus_1_upx(char *nb, t_flags *flags)
{
	int temp;

	if (flags->dot >= 0)
	{
		temp = flags->dot;
		while ((temp - 1) - (ft_strlen(nb) - 1) > 0)
		{
			ft_putchar('0');
			temp--;
		}
	}
	ft_putstr(nb, ft_strlen(nb));
}

void		minus_0_upx(char *nb, t_flags *flags)
{
	if (flags->dot >= 0)
	{
		while ((flags->dot - 1) - (ft_strlen(nb) - 1) > 0)
		{
			ft_putchar('0');
			flags->dot--;
		}
	}
	ft_putstr(nb, ft_strlen(nb));
}

void		dot_sup_upx(char *nb, t_flags *flags)
{
	if (flags->dot >= 0)
	{
		flags->width -= flags->dot;
		while (flags->width > 0)
		{
			ft_putchar(' ');
			flags->width--;
		}
	}
	else
	{
		while ((flags->width) - (ft_strlen(nb)) > 0)
		{
			if (flags->flag_zero == 1)
				ft_putchar('0');
			else
				ft_putchar(' ');
			flags->width--;
		}
	}
}

void		ft_type_x1(unsigned int argu, t_flags *flags)
{
	char	*nb;

	nb = ft_upxtoa(argu, 16);
	if (flags->dot == 0 && argu == 0)
	{
		while (flags->width > 0)
		{
			ft_putchar(' ');
			flags->width--;
		}
		free(nb);
		return ;
	}
	if (flags->flag_minus == 1)
		minus_1_upx(nb, flags);
	if (flags->dot >= 0 && flags->dot < ft_strlen(nb))
		flags->dot = ft_strlen(nb);
	dot_sup_upx(nb, flags);
	if (flags->flag_minus == 0)
		minus_0_upx(nb, flags);
	free(nb);
}
