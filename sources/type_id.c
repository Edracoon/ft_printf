/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_id.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epfennig <epfennig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/26 11:37:50 by epfennig          #+#    #+#             */
/*   Updated: 2021/03/09 15:19:25 by epfennig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void		padding_di(int diff, char c)
{
	while (diff > 0)
	{
		ft_putchar(c);
		diff--;
	}
}

int			minus_0_di(int di, int size_ap, t_flags *flags)
{
	if (flags->flag_zero == 1 && flags->dot < 0)
	{
		if (di < 0)
		{
			ft_putchar('-');
			di *= -1;
		}
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
	return (di);
}

char		*itoa_di(int di)
{
	char	*nb;

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
	return (nb);
}

void		ft_type_di(int di, t_flags *flags)
{
	char	*nb;
	int		size_ap;
	int		i;

	nb = itoa_di(di);
	i = ft_strlen(nb);
	flags->width = di < 0 ? flags->width - 1 : flags->width;
	size_ap = (flags->dot <= i || flags->dot < 0) ? i : flags->dot;
	if (flags->dot == 0 && di == 0)
		size_ap = 0;
	if (flags->flag_minus == 0 && flags->width > size_ap)
		di = minus_0_di(di, size_ap, flags);
	if (di < 0 && (!(flags->width > size_ap && flags->flag_zero == 1
		&& flags->dot < 0 && flags->flag_minus == 0)))
		ft_putchar('-');
	flags->dot = di < 0 ? flags->dot++ : flags->dot;
	if (flags->dot > ft_strlen(nb))
		padding_di(flags->dot - i, '0');
	if (!(di == 0 && flags->dot == 0))
		ft_putstr(nb, i);
	if (flags->flag_minus > 0 && flags->width > size_ap)
		padding_di(flags->width - size_ap, ' ');
	free(nb);
}
