/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstnew.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: pderksen <pderksen@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/26 16:04:59 by pderksen      #+#    #+#                 */
/*   Updated: 2022/05/26 16:05:28 by pderksen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new_list;

	if (!content)
		return (NULL);
	new_list = malloc(sizeof(t_list));
	if (!new_list)
		return (NULL);
	new_list->ct = content;
	new_list->next = NULL;
	return (new_list);
}
