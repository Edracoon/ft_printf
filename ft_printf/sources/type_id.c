/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_id.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epfennig <epfennig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/26 11:37:50 by epfennig          #+#    #+#             */
/*   Updated: 2021/02/26 15:37:12 by epfennig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void		ft_type_di(int di, t_flags *flags)
{
	char	*nb;
	int		size_ap;

	if (di < 0)
	{
		if (di == -2147483648)
			nb = ft_itoa(2147483648);
		else
		{
			di = di * -1;
			nb = ft_itoa(di);
			di = di * -1;
		}
	}
	else
		nb = ft_itoa(di);
	flags->width = di < 0 ? flags->width - 1 : flags->width;
	size_ap = (flags->dot <= ft_strlen(nb) || flags->dot < 0) ? ft_strlen(nb) : flags->dot;
	if (flags->dot == 0 && di == 0)
		size_ap = 0;
	if (flags->flag_minus == 0 && flags->width > size_ap)
	{
		if (flags->flag_zero == 1 && flags->dot < 0)
		{
			if (di < 0)
				ft_putchar('-');
			while (flags->width - size_ap > 0)
			{
				ft_putchar('0');
				flags->width--;
			}
		}
		else
		{
			while (flags->width - size_ap > 0)
			{
				ft_putchar(' ');
				flags->width--;
			}
		}
	}
	if (di < 0 && !(flags->width > size_ap) && !(flags->flag_zero == 1)
		&& !(flags->dot < 0) && !(flags->flag_minus == 0))
		ft_putchar('-');
	flags->dot = di < 0 ? flags->dot++ : flags->dot;
	if (flags->dot > ft_strlen(nb))
	{
		while (flags->dot - ft_strlen(nb) > 0)
		{
			ft_putchar('0');
			flags->dot--;
		}
	}
	if (!(di == 0 && flags->dot == 0))
		ft_putstr(nb, ft_strlen(nb));
	if (flags->flag_minus > 0 && flags->width > size_ap)
	{
		while (flags->width - size_ap > 0)
		{
			ft_putchar(' ');
			flags->width--;
		}
	}
	free(nb);
}
