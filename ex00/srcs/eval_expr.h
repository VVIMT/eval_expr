/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eval_expr.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinvimo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/23 20:29:34 by vinvimo           #+#    #+#             */
/*   Updated: 2016/07/23 22:09:25 by vinvimo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EVAL_EXPR_H
# define EVAL_EXPR_H

# include <unistd.h>
# include <stdlib.h>

void	ft_putchar(char c);
void	ft_putstr(char *str);
void	ft_putnbr(long int nb);
char	*ft_strcpy(char *dst, const char *src);
char	*ft_strncpy(char *dest, char *src, unsigned int n);
char	*ft_strdup(char *s1);
unsigned int ft_strlen(char *s);
void	*ft_strnew(unsigned int size);
void	*ft_strnew_int(unsigned int size);
int	ft_atoi(char *str);
char	*ft_itoa(long int n);
int	eval_expr(char *str);

#endif
