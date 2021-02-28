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

void		minus_1_di(char *nb, int di, t_flags *flags)
{
	int		temp;

	if (di < 0 && flags->dot >= 0)
		ft_putchar('-');
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
	return ;
}

void		minus_0_di(char *nb, int di, t_flags *flags)
{
	int		temp;

	if (di < 0 && flags->dot >= 0)
	{
		ft_putchar('z');
	}
	else if (di < 0 && flags->dot > ft_strlen(nb))
		ft_putchar(' ');
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
	return ;
}

void		dot_sup_0_di(int di, char *nb, t_flags *flags)
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
		if (di < 0 && flags->flag_zero == 0)
			flags->width--;
		while ((flags->width) - (ft_strlen(nb)) > 0)
		{
			if (flags->flag_zero == 1 && flags->flag_minus == 0)
				ft_putchar('0');
			else
				ft_putchar(' ');
			flags->width--;
		}
	}
	return ;
}

int			norme_di(int di, t_flags *flags)
{
	if (flags->dot == 0 && di == 0)
	{
		while (flags->width > 0)
		{
			ft_putchar(' ');
			flags->width--;
		}
		return (0);
	}
	if (di < 0 && (flags->dot >= 0 || flags->flag_zero == 1 || flags->flag_minus == 1))
	{
		if ((flags->flag_zero == 1 || flags->flag_minus == 1) && flags->dot < 0)
			ft_putchar('-');
		flags->flag_zero = 1;
		flags->width--;
	}
	return (1);
}

void		ft_type_di(int di, t_flags *flags)
{
	char	*nb;

	if (norme_di(di, flags) == 0)
		return ;
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
	if (flags->flag_minus == 1)
		minus_1_di(nb, di, flags);
	if (flags->dot >= 0 && flags->dot < ft_strlen(nb))
		flags->dot = ft_strlen(nb);
	dot_sup_0_di(di, nb, flags);
	if (flags->flag_minus == 0)
		minus_0_di(nb, di, flags);
	free(nb);
}
