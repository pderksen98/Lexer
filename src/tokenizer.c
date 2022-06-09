/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   tokenizer.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: pderksen <pderksen@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/27 12:04:55 by pderksen      #+#    #+#                 */
/*   Updated: 2022/06/09 14:54:55 by pderksen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../lexer.h"

//Calls the quote function if the current char is a (') or (")
//Els the word_maker function is called
//A token is created for the final returned string with type WORD
void	string_maker(t_list **tokens, size_t *i, char *cmd_line, char c)
{
	t_list	*new;
	t_token	*token_ct;
	char	*string;

	if (c == s_QUOTE || c == d_QUOTE)
		string = quote(i, cmd_line, NULL, c);
	else
		string = word_maker(i, cmd_line, NULL);
	if (string)
	{
		token_ct = malloc(sizeof(*token_ct));
		ft_check_malloc(token_ct);
		token_ct->string = string;
		token_ct->type = WORD;
		new = ft_lstnew(token_ct);
		ft_check_malloc(new);
		ft_lstadd_back(tokens, new);
	}
	else
		return ;
}

//Checks the current character and calls the corresponing functions
void	split_cmd_line(t_list **tokens, size_t *i, char c, char *cmd_line)
{
	if (c == e_SPACE)
	{
		(*i)++;
		return ;
	}
	else if (c == e_BIG)
		check_big(tokens, i, cmd_line);
	else if (c == e_SMALL)
		check_smal(tokens, i, cmd_line);
	else if (c == e_PIPE)
		pipe(tokens, i);
	else if (c == s_QUOTE || c == d_QUOTE || ft_isprint(c))
		string_maker(tokens, i, cmd_line, c);
	else
		(*i)++;
}

//Get the cmd_line and initializes the linked list
//When split_cmd_line funciton returns current char is again given to
//.... the split_cmd_line funcion
//breaks out of the loop when end of line is reached
//Linked list with tokens is returned
t_list	*lexer(char *cmd_line)
{
	t_list	*list;
	size_t	i;
	size_t	input_len;

	i = 0;
	list = NULL;
	input_len = ft_strlen(cmd_line);
	while (i < input_len)
	{
		split_cmd_line(&list, &i, cmd_line[i], cmd_line);
	}
	return (list);
}
