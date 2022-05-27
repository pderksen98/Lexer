/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstiter.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: pderksen <pderksen@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/26 16:15:50 by pderksen      #+#    #+#                 */
/*   Updated: 2022/05/26 16:16:27 by pderksen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (!lst)
		return ;
	while (lst->next)
	{
		f(lst->ct);
		lst = lst->next;
	}
}
