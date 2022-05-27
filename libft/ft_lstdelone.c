/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstdelone.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: pderksen <pderksen@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/26 16:13:18 by pderksen      #+#    #+#                 */
/*   Updated: 2022/05/26 16:13:52 by pderksen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (!lst)
		return ;
	del(lst->ct);
	free (lst);
}
