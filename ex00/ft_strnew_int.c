#include "eval_expr.h"

void	*ft_strnew_int(unsigned int size)
{
  long int	*str;
  unsigned int	i;

  if ((str = (long int *)malloc(sizeof(long int) * (size + 1))))
    {
      i = 0;
      while (i < size + 1)
	{
	  str[i] = 0;
	  i++;
	}
      str[i] = 0;
      return (str);
    }
  return (0);
}
