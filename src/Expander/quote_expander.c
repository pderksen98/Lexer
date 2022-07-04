/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   quote_expander.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: pderksen <pderksen@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/04 12:03:59 by pderksen      #+#    #+#                 */
/*   Updated: 2022/07/04 15:50:45 by pderksen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../lexer.h"

char	*expander_q(size_t *j, char *string, char **envp)
{
	size_t	k;
	size_t	len;
	char	*variable;
	char	*result;

	(*j)++;
	k = (*j);
	while (check_char_expander(string[k]))
		k++;
	len = k - (*j);
	if (len == 0)
		return (variable_with_zero_length(string[*j], 0));
	variable = ft_strdup_len(&string[*j], len);
	(*j) = (*j) + len;
	result = variable_finder(variable, len, envp);
	free (variable);
	return (result);
}

char	*expand_for_quote(size_t *j, char *string, char *prev, char **envp)
{
	char	*text;
	char	*result;

	text = expander_q(j, string, envp);
	if (text && prev == NULL)
		result = text;
	else if (text == NULL && prev == NULL)
		result = NULL;
	else if (text == NULL && prev)
		result = prev;
	else
	{
		result = ft_strjoin(prev, text);
		ft_check_malloc(result);
		free(prev);
		free(text);
	}
	if (string[*j] == e_DOLLAR)
		result = expand_for_quote(j, string, result, envp);
	else if (string[*j])
		result = check_quote_expander(string, envp, result, j);
	return (result);
}

char	*create_word_q(char *string, size_t *j)
{
	char	*text;
	size_t	k;
	size_t	len;

	k = (*j);
	while (string[k])
	{
		if (string[k] == e_DOLLAR)
			break ;
		k++;
	}
	len = k - (*j);
	if (len == 0)
		return (NULL);
	text = ft_strdup_len(&string[*j], len);
	(*j) += len;
	return (text);
}

char	*check_quote_expander(char *string, char **envp, char *prev, size_t *j)
{
	char	*text;
	char	*result;

	text = create_word_q(string, j);
	if (prev == NULL)
		result = text;
	else if (prev)
	{
		result = ft_strjoin(prev, text);
		ft_check_malloc(result);
		free(prev);
		free(text);
	}
	if (string[*j] == e_DOLLAR)
		result = expand_for_quote(j, string, result, envp);
	return (result);
}
