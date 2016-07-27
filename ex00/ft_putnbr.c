/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinvimo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/23 20:17:39 by vinvimo           #+#    #+#             */
/*   Updated: 2016/07/23 20:18:14 by vinvimo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "eval_expr.h"

void	ft_putnbr(long int nb)
{
	if (nb < 0 && nb > -2147483648)
	{
		nb = -nb;
		ft_putchar('-');
	}
	if (nb > 9 && nb < 2147483647)
		ft_putnbr(nb / 10);
	if (nb == -2147483648)
		ft_putstr("-2147483648");
	else if (nb == 2147483647)
		ft_putstr("2147483647");
	else
		ft_putchar(nb % 10 + '0');
}
