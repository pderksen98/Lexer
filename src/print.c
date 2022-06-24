/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: pderksen <pderksen@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/09 17:36:39 by pderksen      #+#    #+#                 */
/*   Updated: 2022/06/24 14:30:55 by pderksen      ########   odam.nl         */
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
		else if (data->type == REDIRECT)
			printf("type: REDIRECT			string: %s\n", data->string);
		else if (data->type == INPUT)
			printf("type: INPUT			string: %s\n", data->string);
		else if (data->type == APPEND)
			printf("type: APPEND		string: %s\n", data->string);
		else if (data->type == HERE_DOC)
			printf("type: HERE_DOC			string: %s\n", data->string);
		else if (data->type == CMD)
			printf("type: CMD			string: %s\n", data->string);
		else if (data->type == CMD_ARG)
			printf("type: CMD_ARG			string: %s\n", data->string);
		else if (data->type == FILENAME)
			printf("type: FILENAME			string: %s\n", data->string);
		else if (data->type == HERE_DOC_TEXT)
			printf("type: HERE_DOC_TEXT		string: %s\n", data->string);
		temp = temp->next;
	}
}
