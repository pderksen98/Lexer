/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   words.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: pderksen <pderksen@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/09 14:43:44 by pderksen      #+#    #+#                 */
/*   Updated: 2022/07/04 03:19:47 by pieterderks   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../lexer.h"

//Returns 0 if the current char is (>),(<),( ),(|)
//Returns 1 if the current char is ('),(")
//Returns 2 if the current char is a printable ascii
//Returns 3 if the current char is a dollar sign
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
	else if (c == e_DOLLAR)
		return (3);
	else if (ft_isprint(c))
		return (2);
	return (0);
}

char	*double_quote_expander(char *cmd_line, size_t *i, char **envp, char *prev)
{
	size_t	j;
	size_t	len;
	char	*text;
	char	*result;

	if (cmd_line[*i] == e_DOLLAR)
		text = expander(i, cmd_line, envp, 2);
	else
	{
		j = (*i);
		while (cmd_line[j] != e_DOLLAR && cmd_line[j] != d_QUOTE)
			j++;
		len = j - (*i);
		if (len == 0)
			text = NULL;
		else
		{
			text = ft_strdup_len(&cmd_line[*i], len);
			(*i) = (*i) + len;	
		}
	}
	if (prev != NULL && text != NULL)
	{
		result = ft_strjoin(prev, text);
		free(prev);
		free(text);
		ft_check_malloc(result);		
	}
	else if (text && prev == NULL)
		result = text;
	else if (text == NULL && prev == NULL)
		result = NULL;
	else if (text == NULL && prev)
		result = prev;
	if (cmd_line[*i] == e_DOLLAR)
		result = double_quote_expander(cmd_line, i, envp, result);
	return (result);
}









//'text' is a string with all the chars before the matching quote is found
//NULL is returned when no chars in between: "" or ''
char	*between_quotes(char *cmd_line, size_t *i, char quote, char **envp)
{
	char	*text;
	size_t	len;

	(void)envp;
	(*i)++;
	text = NULL;
	if (cmd_line[*i] != quote && quote == s_QUOTE)
	{
		text = ft_strdup_c(&cmd_line[*i], quote);
		ft_check_malloc(text);
		len = ft_strlen(text);
		(*i) = (*i) + len;
	}
	else
		text = double_quote_expander(cmd_line, i, envp, NULL);
	(*i)++;
	return (text);
}

//Combines the previous text (if there is) with the current text
//If next char is a quote: quote function calls itself with result as prev
//If next char is not (<), (>), ( ), (|), ('), (") and printable:
//...word_maker function is called with result as prev
char	*quote(size_t *i, char *cmd_line, char *prev, char quot, char **envp)
{
	char	*text;
	char	*result;

	text = between_quotes(cmd_line, i, quot, envp);
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
		result = quote(i, cmd_line, result, cmd_line[*i], envp);
	else if (check_next_char(cmd_line[*i]) == 2)
		result = word_maker(i, cmd_line, result, envp);
	else if (check_next_char(cmd_line[*i]) == 3)
		result = expand_word(i, cmd_line, result, envp);
	return (result);
}

//Makes string 'text' until: NULL, ( ), (>), (<), (|), ('), (") is found
//Returns string text
char	*create_word(char *cmd_line, size_t *i)
{
	char	*text;
	size_t	j;
	size_t	len;

	j = (*i);
	while (cmd_line[j])
	{
		if (cmd_line[j] == e_SPACE || cmd_line[j] == e_BIG || \
			cmd_line[j] == e_SMALL || cmd_line[j] == e_PIPE || \
			cmd_line[j] == s_QUOTE || cmd_line[j] == d_QUOTE ||
			cmd_line[j] == e_DOLLAR)
			break ;
		j++;
	}
	len = j - (*i);
	text = ft_strdup_len(&cmd_line[*i], len);
	(*i) += len;
	return (text);
}

//Calls create_word function
//Joins previous string and current text if there is a prev string
//If next char is (') or (") the quote function is called with 
//....result as prev string
char	*word_maker(size_t *i, char *cmd_line, char *prev, char **envp)
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
		result = quote(i, cmd_line, result, cmd_line[*i], envp);
	else if (check_next_char(cmd_line[*i]) == 3)
		result = expand_word(i, cmd_line, result, envp);
	return (result);
}
