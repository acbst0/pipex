#include "../pipex.h"

char	*ft_strdup(const char *str)
{
	size_t	a;
	char	*r;

	a = ft_strlen(str);
	r = (char *)malloc(sizeof(char) * (a + 1));
	if (!r)
		return (0);
	ft_strlcpy(r, str, a + 1);
	return (r);
}
