/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   list.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: pderksen <pderksen@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/25 13:59:06 by pderksen      #+#    #+#                 */
/*   Updated: 2022/05/27 12:04:16 by pderksen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../lexer.h"

t_token	*create_new_token(char *string, int type)
{
	t_token	*token;
	
	token = malloc(sizeof(t_token));
	check_malloc(token);
	//if malloc fails still check what to return
	token->next = NULL;
	token->text = ...
	token->type = type;
}

void	make_linked_list(t_token **list, t_data data)
{
	t_token	*new_token;
	t_token	*temp;
	int		i;

	i = 0;
	while (char input...)
	{
		string = function(input);
		new_token = create_new_token(input, string);
		if (i == 0)
		{
			temp = new_token;
			*list = temp;
		}
		else
		{
			temp->next = new_token;
			temp = new_token;
		}
		i++;
	}	
}



