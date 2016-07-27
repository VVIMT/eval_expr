/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eval_expr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinvimo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/23 19:15:05 by vinvimo           #+#    #+#             */
/*   Updated: 2016/07/24 23:27:26 by vinvimo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "eval_expr.h"

long int		split(char *str);

int		eval_expr(char *str)
{
	char		*strtmp;
	char		*tmpnb;
	int		i;
	int		j;
	int		k;

	k = 0;
	j = 0;
	while (str[j] && str[j] != ')')
		j++;
	i = j;
	while (i > 0 && str[i] != '(')
		i--;
	if (!(strtmp = (char *)malloc(sizeof(char) * (j - i + 1))))
		return (0);
	tmpnb = ft_itoa(split(ft_strncpy(strtmp, str + i + 1, j - i - 1)));
	strtmp = (char *)ft_strnew(ft_strlen(str));
	ft_strncpy(strtmp, str, i);
	ft_strcpy(strtmp + i, tmpnb);
	k = ft_strlen(tmpnb);
	ft_strcpy(strtmp + i + k, str + j + 1);
	i = 1;
	while (strtmp[i] >= '0' && strtmp[i] <= '9')
	  i++;
ft_putstr(strtmp);	
ft_putchar('\n');
if (strtmp[i] != '\0')
		return (eval_expr(strtmp));
	return (ft_atoi(strtmp));
}

char *stock_operators(char *new, int k, int i, char *str)
{
	while (str[i])
    {
		if (str[i] == '*' || str[i] == '/'
			|| str[i] == '%' || str[i] == '+' || str[i] == '-')
			k++;
		i++;
    }
	new = (char *)ft_strnew(2 * k);
	i = 0;
	while (str[i])
	{
		if (str[i] == '*' || str[i] == '/'
			|| str[i] == '%' || str[i] == '+' || str[i] == '-')
		{
			new[k] = str[i];
			k = k + 2;
		}
		new[k - 1] = '+';
		i++;
	}
	return (new);
}

/*char *stock_operators(char *new, int k, int i, char *str)
{
  while (str[i])
    {
      if (str[i] == '*' || str[i] == '/'
	|| str[i] == '%' || str[i] == '+' || str[i] == '-')
	k++;
      i++;
    }
  new = (char *)ft_strnew(2 * k);
  i = 0;
  if (str[0] == '-')
    {
    new[0] = '-';
    i = 1;
    }
  else
	  new[0] = '+';
   k = 1;
  while (str[i])
    {
      if (str[i] == '*' || str[i] == '/'
	|| str[i] == '%' || str[i] == '+' || str[i] == '-')
	{
		new[k] = str[i];
		k++;
	}
      i++;
    }
  return (new);
}*/

long int *stock_nb(long int *nb, int k, int i, char *str)
{
  while (str[i])
    {
      if (str[i] >= '0' && str[i] <= '9')
	{
	  while (str[i] >= '0' && str[i] <= '9')
	    i++;
	  k++;
	}
      i++;
    }
  nb = (long int *)ft_strnew_int(k + 1);
  k = 0;
  i = 0;
  while (str[i])
    {
      if (str[i] >= '0' && str[i] <= '9')
	{
	  nb[k] = ft_atoi(str + i);
	  k++;
	  while (str[i] >= '0' && str[i] <= '9')
	    i++;
	}
      i++;
    }
  return (nb);
}

long int calculate2(long int *nb, int k)
{
  long int result;
  int i;

  i = 0;
  result = 0;
  while (i <= k)
    {
      result = result + nb[i];
      i++;
    }
  return (result);
}

long int calculate(long int *nb, char *new, int k)
{
  long int *nb2;
  int i;

  nb2 = (long int *)ft_strnew_int(k);
  i = 0;
  k = 0;
  while (new[i])
    {
      if (new[i] == '-')
		  nb[i] = -1 * nb[i];
	  i++;
	}
  i = 0;
  while (new[i])
  {
    while (new[i] && (new[i] == '*' || new[i] == '/' || new[i] == '%'))
	{
	  if (new[i] == '*')
	    nb2[k - 2] = nb2[k - 2] * nb[i];
	  else if (new[i] == '/')
	    nb2[k - 2] = nb2[k - 2] / nb[i];
	  else if (new[i] == '%')
	    nb2[k - 2] = nb2[k - 2] % nb[i];
	  i++;
	}
      nb2[k] = nb[i];
      k = k + 2;
      i++;
  }
  return (calculate2(nb2, k));
}

long int		split(char *str)
{
	long int *nb;
	int i;
	char	*new;

	new = stock_operators(NULL, 0, 0, str);
	nb = stock_nb(NULL, 0, 0, str);
	i = 0;
	while (new[i])
	  i++;
    return (calculate(nb, new, i));
}

int		main(int ac, char **av)
{
	if (ac > 1)
	{
		ft_putnbr(eval_expr(av[1]));
		ft_putchar('\n');
	}
	return (0);
}
