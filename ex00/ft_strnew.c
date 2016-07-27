#include "eval_expr.h"

void	*ft_strnew(unsigned int size)
{
  char		*str;
  unsigned int	i;

  if ((str = (char *)malloc(sizeof(char) * (size + 1))))
    {
      i = 0;
      while (i < size + 1)
	{
	  str[i] = '\0';
	  i++;
	}
      str[i] = '\0';
      return (str);
    }
  return (NULL);
}
