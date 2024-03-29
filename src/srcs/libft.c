/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkodai <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 19:01:18 by tkodai            #+#    #+#             */
/*   Updated: 2021/08/17 12:04:22 by tkodai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "get_next_line.h"
#include "so_long.h"

void	put_error2(char *err_str)
{
	printf("Error\n");
	printf("%s\n", err_str);
	exit(1);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (*str)
	{
		str++;
		i++;
	}
	return (i);
}

char 	*ft_strjoin(char *s1, char *s2)
{
	char	*tmp;
	char	*save;

	tmp = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (tmp == NULL)
		put_error2("malloc failed");
	save = tmp;
	while (*s1)
		*tmp++ = *s1++;
	while (*s2)
		*tmp++ = *s2++;
	*tmp = 0;
	return (save);
}

char	*ft_strdup(char *str)
{
	char	*save;
	char	*tmp;

	tmp = malloc(ft_strlen(str) + 1);
	if (tmp == NULL)
		put_error2("malloc failed");
	save = tmp;
	while (*str)
	{
		*tmp++ = *str++;
	}
	*tmp = 0;
	return (save);
}
