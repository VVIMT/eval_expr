#include "eval_expr.h"

unsigned int ft_strlen(char *s)
{
  unsigned int i;

  i = 0;
  while (s[i] != 0)
    i++;
  return (i);
}
