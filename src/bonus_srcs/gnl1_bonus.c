//#include "get_next_line.h"
#include "so_long_bonus.h"

static char	*ft_strchr(char *str)
{
	while (*str)
	{
		if (*str == '\n')
			return (str);
		str++;
	}
	return (NULL);
}

static char	*ft_substr(char	*str, int start, int len)
{
	char	*save;
	char	*tmp;
	int		s_len;

	s_len = ft_strlen(str);
	if (s_len < len)
		len = s_len;
	tmp = malloc(len + 1);
	if (tmp == NULL)
	{
		printf("Error\nmalloc failed\n");
		exit(1);
	}
	save = tmp;
	while (len-- > 0 && str[start])
		*tmp++ = str[start++];
	*tmp = 0;
	return (save);
}

int	gnl2(int fd, char **ptr, char **ss)
{
	char		*tmp;
	char		buf[1001];
	int			r;

	*ptr = ft_strchr(*ss);
	while (*ptr == NULL)
	{
		r = read(fd, buf, 1000);
		if (r == -1)
			return (-1);
		if (r == 0)
			break ;
		buf[r] = 0;
		tmp = *ss;
		*ss = ft_strjoin(*ss, buf);
		free(tmp);
		*ptr = ft_strchr(*ss);
	}
	return (0);
}

int	get_next_line(int fd, char **line)
{
	char		*ptr;
	char		*tmp;
	static char	*ss;

	if (ss == NULL)
		ss = ft_strdup("");
	if (gnl2(fd, &ptr, &ss) == -1)
		return (-1);
	if (ptr != NULL)
	{
		tmp = ss;
		*line = ft_substr(ss, 0, ptr - ss);
		ss = ft_substr(ss, ptr - ss + 1, ft_strlen(ss));
		free (tmp);
		return (1);
	}
	else
	{
		*line = ft_strdup(ss);
		free(ss);
	}
	return (0);
}
