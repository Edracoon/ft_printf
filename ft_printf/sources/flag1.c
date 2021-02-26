/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epfennig <epfennig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 14:52:59 by epfennig          #+#    #+#             */
/*   Updated: 2021/02/26 11:18:27 by epfennig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void		ft_type_di(int di, t_flags *flags)
{
	char	*nb;
	int		temp;

	if (flags->dot == 0 && di == 0)
	{
		while (flags->width > 0)
		{
			ft_putchar(' ');
			flags->width--;
		}
		return ;
	}
	if (di < 0 && (flags->dot >= 0 || flags->flag_zero == 1))
	{
		if (flags->flag_zero == 1 && flags->dot == -1)
			ft_putchar('-');
		flags->flag_zero = 1;
		flags->width--;
	}
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
	{
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
		if (di < 0 && (flags->dot >= 0 || (!(flags->flag_zero == 1 && flags->dot == -1))))
		{
			ft_putchar('-');
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
	}
	free(nb);
}

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

void		ft_type_s(char *argu, t_flags *flags)
{
	if (argu == NULL)
		argu = "(null)";
	if (flags->dot >= 0 && flags->dot > ft_strlen(argu))
		flags->dot = ft_strlen(argu);
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

void		ft_type_x(unsigned int argu, t_flags *flags)
{
	char	*nb;
	int		i;
	int		temp;

	i = -1;
	nb = ft_upxtoa(argu, 16);
	while (nb[++i])
		nb[i] = ft_tolower(nb[i]);
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

void		ft_type_x1(unsigned int argu, t_flags *flags)
{
	char	*nb;
	int		temp;

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
