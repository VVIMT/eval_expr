#include "eval_expr.h"

char	*ft_strdup(char *s1)
{
	size_t		i;
	char		*s2;

	i = 0;
	while (s1[i])
		i++;
	s2 = NULL;
	if (!(s2 = malloc(sizeof(char) * (i + 1))))
		return (NULL);
	i = 0;
	while (s1[i])
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = s1[i];
	return (s2);
}
