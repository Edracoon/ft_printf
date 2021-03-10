/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_p.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epfennig <epfennig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/26 12:50:54 by epfennig          #+#    #+#             */
/*   Updated: 2021/03/09 14:50:40 by epfennig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

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
