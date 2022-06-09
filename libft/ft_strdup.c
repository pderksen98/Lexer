/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strdup.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: pderksen <pderksen@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/28 15:16:27 by pderksen      #+#    #+#                 */
/*   Updated: 2022/06/09 13:58:00 by pderksen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	i;
	size_t	length;
	char	*ptr;

	i = 0;
	length = ft_strlen(s1);
	ptr = (char *)malloc((length + 1) * sizeof(char));
	if (ptr == NULL)
		return (0);
	while (i < length)
	{
		ptr[i] = s1[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}
