/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   operators.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: pderksen <pderksen@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/09 14:50:42 by pderksen      #+#    #+#                 */
/*   Updated: 2022/06/24 14:24:39 by pderksen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../lexer.h"

//checks if after the big_redirect(>) another big_redirect comes
//if yes, then type is >>
//if no, then type is >
//Makes token with correct type
void	check_big(t_list **tokens, size_t *i, char *cmd_line)
{
	t_list	*new;
	t_token	*token_ct;

	token_ct = malloc(sizeof(t_token));
	ft_check_malloc(token_ct);
	token_ct->string = NULL;
	if (cmd_line[*i + 1] == e_BIG)
	{
		(*i)++;
		token_ct->type = APPEND;
	}
	else
		token_ct->type = REDIRECT;
	new = ft_lstnew(token_ct);
	ft_check_malloc(new);
	ft_lstadd_back(tokens, new);
	(*i)++;
}

//checks if after the smal_redirect(<) another smal_redirect comes
//if yes, then type is <<
//if no, then type is <
//Makes token with correct type
void	check_smal(t_list **tokens, size_t *i, char *cmd_line)
{
	t_list	*new;
	t_token	*token_ct;

	token_ct = malloc(sizeof(t_token));
	ft_check_malloc(token_ct);
	token_ct->string = NULL;
	if (cmd_line[*i + 1] == e_SMALL)
	{
		(*i)++;
		token_ct->type = HERE_DOC;
	}
	else
		token_ct->type = INPUT;
	new = ft_lstnew(token_ct);
	ft_check_malloc(new);
	ft_lstadd_back(tokens, new);
	(*i)++;
}

//Makes a token with type PIPE
void	pipe(t_list **tokens, size_t *i)
{
	t_list	*new;
	t_token	*token_ct;

	token_ct = malloc(sizeof(t_token));
	ft_check_malloc(token_ct);
	token_ct->string = NULL;
	token_ct->type = PIPE;
	new = ft_lstnew(token_ct);
	ft_check_malloc(new);
	ft_lstadd_back(tokens, new);
	(*i)++;
}
