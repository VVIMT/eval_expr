/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eval_expr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinvimo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/23 19:15:05 by vinvimo           #+#    #+#             */
/*   Updated: 2016/07/24 22:58:34 by vinvimo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "eval_expr.h"

long int	split(char *str);
int			eval_expr_bis(char *str, int k, int j);

int			eval_expr(char *str)
{
	char	*strtmp;

	strtmp = (char*)ft_strnew(ft_strlen(str) + 3);
	strtmp[0] = '(';
	ft_strcpy(strtmp + 1, str);
	strtmp[ft_strlen(str) + 1] = ')';
	return (eval_expr_bis(strtmp, 0, 0));
}

int			eval_expr_bis(char *str, int k, int j)
{
	char	*strtmp;
	char	*tmpnb;
	int		i;

	while (str[j] && str[j] != ')')
		j++;
	i = j;
	while (i > 0 && str[i] != '(')
		i--;
	strtmp = (char*)ft_strnew(ft_strlen(str));
	tmpnb = ft_itoa(split(ft_strncpy(strtmp, str + i + 1, j - i - 1)));
	ft_strncpy(strtmp, str, i);
	ft_strcpy(strtmp + i, tmpnb);
	k = ft_strlen(tmpnb);
	ft_strcpy(strtmp + i + k, str + j + 1);
	i = 1;
	while (strtmp[i] >= '0' && strtmp[i] <= '9')
	  i++;
	if (strtmp[i] != '\0')
		return (eval_expr_bis(strtmp, 0, 0));
	return (ft_atoi(strtmp));
}

void		stock_operators_bis(int *i, int *k, char *new, char *str)
{
	while (str[*i])
	{
		if (str[*i] == '*' || str[*i] == '/'
			|| str[*i] == '%' || str[*i] == '+' || str[*i] == '-')
		{
			new[*k] = str[*i];
			(*k)++;
		}
		(*i)++;
	}
}

char		*stock_operators(char *new, int k, int i, char *str)
{
	while (str[i])
	{
		if (str[i] == '*' || str[i] == '/'
			|| str[i] == '%' || str[i] == '+' || str[i] == '-')
			k++;
		i++;
	}
	new = (char*)ft_strnew(k + 1);
	i = 0;
	k = 0;
	while (str[i] < '0' || str[i] > '9')
		if (str[i++] == '-')
			k = 1;
	if (k == 1)
		new[0] = '-';
	else
		new[0] = '+';
	k = 1;
	stock_operators_bis(&i, &k, new, str);
	return (new);
}

int			stock_nb_bis(int i, char *str)
{
	int		k;
	int		x;

	k = 0;
	while (i >= 0 && (str[i] < '0' || str[i] > '9'))
	{
		if (str[i] == '+' || str[i] == '-' || str[i] == '*'
			|| str[i] == '/' || str[i] == '%')
		{
			k++;
			if (k == 1)
				x = i;
		}
		i--;
	}
	if (k == 2)
	{
		str[x] = ' ';
		return (-1);
	}
	return (1);
}

long int	*stock_nb(long int *nb, int k, int i, char *str)
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
			nb[k] = stock_nb_bis(i - 1, str) * ft_atoi(str + i);
				k++;
			while (str[i] >= '0' && str[i] <= '9')
				i++;
		}
		i++;
	}
	return (nb);
}

long int	calculate2(long int *nb, int k)
{
	long int	result;
	int			i;

	i = 0;
	result = 0;
	while (i <= k)
	{
		result = result + nb[i];
		i++;
	}
	return (result);
}

long int	calculate(long int *nb, char *new, int k)
{
	long int	*nb2;
	int			i;

	nb2 = (long int*)ft_strnew_int(k);
	i = -1;
	while (new[++i])
		if (new[i] == '-')
			nb[i] = -1 * nb[i];
	k = 0;
	i = 0;
	while (new[i])
	{
		while (new[i] && (new[i] == '*' || new[i] == '/' || new[i] == '%'))
		{
			if (new[i] == '*')
				nb2[k - 1] = nb2[k - 1] * nb[i];
			else if (new[i] == '/')
				nb2[k - 1] = nb2[k - 1] / nb[i];
			else if (new[i] == '%')
				nb2[k - 1] = nb2[k - 1] % nb[i];
			i++;
		}
		nb2[k] = nb[i];
		k++;
		i++;
	}
	return (calculate2(nb2, k));
}

long int	split(char *str)
{
	long int	*nb;
	int			i;
	char		*new;

	nb = stock_nb(NULL, 0, 0, str);
	new = stock_operators(NULL, 0, 0, str);
	i = 0;
	while (new[i])
		i++;
	return (calculate(nb, new, i));
}

int			main(int ac, char **av)
{
	if (ac > 1)
	{
		ft_putnbr(eval_expr(av[1]));
		ft_putchar('\n');
	}
	return (0);
}
