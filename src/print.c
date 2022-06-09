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
		if (data->type == GREAT)
			printf("type: GREAT			string: %s\n", data->string);
		if (data->type == SMALL)
			printf("type: SMALL			string: %s\n", data->string);
		if (data->type == GREAT_GREAT)
			printf("type: GREAT_GREAT		string: %s\n", data->string);
		if (data->type == SMALL_SMALL)
			printf("type: SMALL_SMALL		string: %s\n", data->string);
		if (data->type == WORD)
			printf("type: WORD			string: %s\n", data->string);
		temp = temp->next;
	}
}
