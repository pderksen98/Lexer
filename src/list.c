/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   list1.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: pderksen <pderksen@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/27 12:04:55 by pderksen      #+#    #+#                 */
/*   Updated: 2022/05/27 14:01:48 by pderksen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../lexer.h"

//checks if after the big_redirect(>) another big_redirect comes
//if yes, then type is >>
//if no, then type is >
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
		token_ct->type = GREAT_GREAT;
	}
	else
		token_ct->type = GREAT;
	new = ft_lstnew(token_ct);
	ft_check_malloc(new);
	ft_lstadd_back(tokens, new);
	(*i)++;
}

//checks if after the smal_redirect(<) another smal_redirect comes
//if yes, then type is <<
//if no, then type is <
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
		token_ct->type = SMALL_SMALL;
	}
	else
		token_ct->type = SMALL;
	new = ft_lstnew(token_ct);
	ft_check_malloc(new);
	ft_lstadd_back(tokens, new);
	(*i)++;
}

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



















char	*between_quotes(char *cmd_line, size_t *i, char quote)
{
	char	*text;
	size_t	len;
	
	(*i)++;
	text = NULL;
	if (cmd_line[*i] != quote)
	{
		text = ft_strdup_c(&cmd_line[*i], quote);
		ft_check_malloc(text);
		len = ft_strlen(text);
		(*i) = (*i) + len;
	}
	(*i)++;
	return (text);
}

char	*quote(size_t *i, char *cmd_line, char *prev, char quot)
{
	char	*text;
	char	*result;

	text = between_quotes(cmd_line, i, quot);
	if (text && prev == NULL)
		result = text;
	else if (text == NULL && prev == NULL)
		result = NULL;
	else if (text == NULL && prev)
		result = prev;
	else if (text && prev)
	{
		result = ft_strjoin(prev, text);
		ft_check_malloc(result);
		free(prev);
		free(text);
	}
	if (check_next_char(cmd_line[*i]) == 1)
		result = quote(i, cmd_line, result, cmd_line[*i]);
	else if (check_next_char(cmd_line[*i]) == 2)
		result = word_maker(i, cmd_line, result);
	return (result);
}


char	*create_word(char *cmd_line, size_t *i)
{
	char	*text;
	size_t	j;
	size_t	len;

	j = (*i);
	while (cmd_line[j])
	{
		if (cmd_line[j] == e_SPACE || cmd_line[j] == e_BIG || cmd_line[j] == e_SMALL || cmd_line[j] == e_PIPE || cmd_line[j] == s_QUOTE || cmd_line[j] == d_QUOTE)
			break ;
		j++;
	}
	len = j - (*i);
	text = ft_strdup_len(&cmd_line[*i], len);
	(*i) += len;
	return (text);
}

char	*word_maker(size_t *i, char *cmd_line, char *prev)
{
	char	*text;
	char	*result;

	text = create_word(cmd_line, i);
	if (prev == NULL)
		result = text;
	else if (prev)
	{
		result = ft_strjoin(prev, text);
		ft_check_malloc(result);
		free(prev);
		free(text);
	}
	if (check_next_char(cmd_line[*i]) == 1)
		result = quote(i, cmd_line, result, cmd_line[*i]);
	else if (check_next_char(cmd_line[*i]) == 2)
		result = word_maker(i, cmd_line, result);
	return (result);
}

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
		printf("check: %s\n", string);
		token_ct = malloc(sizeof(token_ct));
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

//Returns 0 if the current char is (>),(<),( ),(|)
//Returns 1 if the current char is ('),(")
//Returns 2 if the current char is a printable ascii
int	check_next_char(char c)
{
	if (c == e_BIG)
		return (0);
	else if (c == e_SMALL)
		return (0);
	else if (c == e_SPACE)
		return (0);
	else if (c == e_PIPE)
		return (0);
	else if (c == s_QUOTE || c == d_QUOTE)
		return (1);
	else if (ft_isprint(c))
		return (2);
	return (0);
}



void	split_cmd_line(t_list **tokens, size_t *i, char c, char *cmd_line)
{
	// printf("KOEKKOEK\n");
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
	


	// else if (ft_isprint(c))
	// 	word_maker(tokens, i, cmd_line, NULL);
}























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
