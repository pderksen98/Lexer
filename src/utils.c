/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: pderksen <pderksen@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/09 14:49:58 by pderksen      #+#    #+#                 */
/*   Updated: 2022/06/09 14:52:47 by pderksen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../lexer.h"

//duplicates the string 'str' up to len characteres
char	*ft_strdup_len(const char *str, size_t len)
{
	size_t	i;
	char	*new_str;

	if ((size_t)ft_strlen(str) < len)
		len = (size_t)ft_strlen(str);
	new_str = malloc(sizeof(char) * (len + 1));
	ft_check_malloc(new_str);
	i = 0;
	while (i < len && str[i])
	{
		new_str[i] = str[i];
		i++;
	}
	new_str[i] = 0;
	return (new_str);
}

//finds the length of the string up to the given char c
size_t	ft_strlen_c(const char *str, int c)
{
	size_t	i;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	return (i);
}
