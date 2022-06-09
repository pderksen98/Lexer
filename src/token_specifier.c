/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   token_specifier.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: pderksen <pderksen@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/09 17:00:53 by pderksen      #+#    #+#                 */
/*   Updated: 2022/06/09 18:07:21 by pderksen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../lexer.h"

//Gets called to change the values in t_specify
//0 -> everything back to zero
//1 -> sets redirect to 1
//2 -> sets redirect to 0
//3 -> sets here_doc to 1
//4 -> sets here_doc to 0
//5 -> sets command to 1
void	adjust_specify_struct(t_specify *prev, int code)
{
	if (code == 0)
	{
		prev->redirect = 0;
		prev->here_doc = 0;
		prev->command = 0;
	}
	else if (code == 1)
		prev->redirect = 1;
	else if (code == 2)
		prev->redirect = 0;
	else if (code == 3)
		prev->here_doc = 1;
	else if (code == 4)
		prev->here_doc = 0;
	else if (code == 5)
		prev->command = 1;
}

//WORD after redirect becomes of type FILEE
//WORD after here_doc becomes of type HERE_DOC_TEXT
//If there already is a command, WORD becomes ARG
//If there is not a command yet, WORD becomes CMD
void	word_specifier(t_token *token, t_specify *prev)
{
	if (prev->redirect == 1)
	{
		token->type = FILEE;
		adjust_specify_struct(prev, 2);
	}
	else if (prev->here_doc == 1)
	{
		token->type = HERE_DOC_TEXT;
		adjust_specify_struct(prev, 4);
	}
	else if (prev->command == 1)
		token->type = ARG;
	else if (prev->command == 0)
	{
		token->type = CMD;
		adjust_specify_struct(prev, 5);
	}
}

//Function to specify type: WORD to one of the following:
//....CMD, ARG, FILEE, HERE_DOC_TEXT
//adjust_specify_struct is called to know previous operators
//word_specifier is called when a token of type WORD is found
void	token_specifier(t_list **tokens)
{
	t_list		*temp;
	t_token		*data;
	t_specify	prev;

	adjust_specify_struct(&prev, 0);
	temp = *tokens;
	while (temp)
	{
		data = temp->ct;
		if (data->type == GREAT || data->type == GREAT_GREAT || \
				 data->type == SMALL)
			adjust_specify_struct(&prev, 1);
		else if (data->type == SMALL_SMALL)
			adjust_specify_struct(&prev, 3);
		else if (data->type == PIPE)
			adjust_specify_struct(&prev, 0);
		else if (data->type == WORD)
			word_specifier(data, &prev);
		temp = temp->next;
	}
}
