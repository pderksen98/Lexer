/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstmap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: pderksen <pderksen@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/26 16:16:46 by pderksen      #+#    #+#                 */
/*   Updated: 2022/05/26 16:17:05 by pderksen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*head;

	head = NULL;
	if (!lst || !f)
		return (head);
	while (lst)
	{
		new_lst = ft_lstnew(f(lst->ct));
		if (new_lst)
			ft_lstadd_back(&head, new_lst);
		else
		{
			ft_lstclear(&head, del);
			return (NULL);
		}
		lst = lst->next;
	}
	return (head);
}
