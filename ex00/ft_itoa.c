/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinvimo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/23 22:07:30 by vinvimo           #+#    #+#             */
/*   Updated: 2016/07/23 22:09:04 by vinvimo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "eval_expr.h"

int	ft_nlen(long int n)
{
  unsigned int i;

  i = 0;
  while (n >= 10 || n <= -10)
    {
      n = n / 10;
      i++;
    }
  return (i);
}

char	*ft_itoa_bis(long int n, int neg, int size, char *nbr)
{
  if (n < 0 && neg == 0)
    {
      n = -n;
      neg = 1;
      nbr[0] = '-';
    }
  if (n >= 10 && size >= 0)
    {
      nbr[size] = (n % 10) + '0';
      return (ft_itoa_bis(n / 10, neg, size - 1, nbr));
    }
  if (size >= neg)
    nbr[size] = n + '0';
  return (nbr);
}

char	*ft_itoa(long int n)
{
  unsigned int	size;
  char		*nbr;

  if (n <= -2147483648)
    return (ft_strdup("-2147483648"));
  size = ft_nlen(n);
  if (n < 0)
    size++;
  if (!(nbr = ft_strnew(size + 1)))
    return (NULL);
  return (ft_itoa_bis(n, 0, size, nbr));
}
