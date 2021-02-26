/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epfennig <epfennig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 15:07:14 by epfennig          #+#    #+#             */
/*   Updated: 2021/02/26 11:00:47 by epfennig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_type_u(unsigned int argu, t_flags *flags)
{
	char	*nb;
	int		temp;

	nb = ft_upxtoa(argu, 10);
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
	{
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
	if (flags->dot >= 0 && flags->dot < ft_strlen(nb))
		flags->dot = ft_strlen(nb);
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
	if (flags->flag_minus == 0)
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
	free(nb);
}

void		ft_type_p(unsigned long long argu, t_flags *flags)
{
	char	*nb;
	int		i;

	i = -1;
	nb = ft_upxtoa(argu, 16);
	while (nb[++i])
		nb[i] = ft_tolower(nb[i]);
	if (flags->flag_minus == 1)
	{
		ft_putstr("0x", 2);
		ft_putstr(nb, ft_strlen(nb));
	}
	while (flags->width - (ft_strlen(nb) + 2) > 0)
	{
		ft_putchar(' ');
		flags->width--;
	}
	if (flags->flag_minus == 0)
	{
		ft_putstr("0x", 2);
		ft_putstr(nb, ft_strlen(nb));
	}
	free(nb);
}
