/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_upxtoa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epfennig <epfennig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 12:41:51 by epfennig          #+#    #+#             */
/*   Updated: 2021/03/09 14:38:37 by epfennig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int			ft_intlen2(unsigned long long nb, int base)
{
	int		len;

	len = 0;
	if (nb == 0)
		return (1);
	if (nb < 0)
	{
		nb = nb * (-1);
		len++;
	}
	while (nb > 0)
	{
		nb = nb / base;
		len++;
	}
	return (len);
}

char		*ft_upxtoa(unsigned long long n, int base)
{
	int		len;
	char	*str;

	if (n == 0)
		return (ft_strdup("0"));
	len = ft_intlen2(n, base);
	if ((str = malloc(sizeof(char) * (len + 1))) == NULL)
		return (NULL);
	str[len] = '\0';
	len--;
	while (len >= 0)
	{
		if ((n % base) < 10)
			str[len] = '0' + (n % base);
		else
			str[len] = '7' + (n % base);
		n = (n / base);
		len--;
	}
	return (str);
}
