/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: pderksen <pderksen@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/09 17:36:39 by pderksen      #+#    #+#                 */
/*   Updated: 2022/06/09 18:07:26 by pderksen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../lexer.h"

void	print_link_list(t_list **tokens)
{
	t_list	*temp;
	t_token	*data;

	temp = *tokens;
	while (temp)
	{
		data = temp->ct;
		if (data->type == PIPE)
			printf("type: PIPE			string: %s\n", data->string);
		else if (data->type == GREAT)
			printf("type: GREAT			string: %s\n", data->string);
		else if (data->type == SMALL)
			printf("type: SMALL			string: %s\n", data->string);
		else if (data->type == GREAT_GREAT)
			printf("type: GREAT_GREAT		string: %s\n", data->string);
		else if (data->type == SMALL_SMALL)
			printf("type: SMALL_SMALL		string: %s\n", data->string);
		else if (data->type == CMD)
			printf("type: CMD			string: %s\n", data->string);
		else if (data->type == ARG)
			printf("type: ARG			string: %s\n", data->string);
		else if (data->type == FILEE)
			printf("type: FILEE			string: %s\n", data->string);
		else if (data->type == HERE_DOC_TEXT)
			printf("type: HERE_DOC_TEXT		string: %s\n", data->string);
		temp = temp->next;
	}
}
