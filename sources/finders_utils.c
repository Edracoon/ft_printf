/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finders_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epfennig <epfennig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/26 11:32:30 by epfennig          #+#    #+#             */
/*   Updated: 2021/02/26 15:13:12 by epfennig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		find_type(int c)
{
	if (c == 'c' || c == 's' || c == 'p' ||
		c == 'd' || c == 'i' || c == 'u' ||
		c == 'x' || c == 'X' || c == '%')
		return (c);
	else
		return (0);
}

int		find_flag(int c)
{
	if ((c == '-') || (c == ' ') || (c == '0') ||
		(c == '.') || (c == '*'))
		return (c);
	else
		return (0);
}

int		len_option(const char *str, int i)
{
	while (str[i] == '.' || str[i] == '-' || str[i] == '*'
			|| str[i] == '0' || (str[i] >= '0' && str[i] <= '9'))
		i++;
	return (i);
}
