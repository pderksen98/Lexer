/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   paths.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: pieterderksen <pieterderksen@student.co      +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/01 12:55:18 by pieterderks   #+#    #+#                 */
/*   Updated: 2022/07/04 15:44:10 by pderksen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../lexer.h"

	// else if (check_next_char(cmd_line[*i] == 3))
	// 	result = expand_word(i, cmd_line, result);

char	*variable_finder(char *variable, size_t len, char **envp)
{
	char	*result;

	while (*envp)
	{
		if (ft_strncmp(variable, *envp, len) == 0)
		{
			result = ft_strdup(*envp + (len + 1));
			ft_check_malloc(result);
			return (result);
		}
		envp++;
	}
	return (NULL);
}

//ascii 95 is: (_)
int	check_char_expander(char c)
{
	if (ft_isalpha(c) == 1)
		return (1);
	else if (ft_isdigit(c) == 1)
		return (1);
	else if (c == 95)
		return (1);
	return (0);
}

char	*variable_with_zero_length(char c, int flag)
{
	char	*result;

	if (flag == 1)
	{
		if (c == s_QUOTE || c == d_QUOTE)
			return (NULL);
	}
	result = malloc(sizeof(char) * 2);
	ft_check_malloc(result);
	result[0] = '$';
	result[1] = '\0';
	return (result);
}

char	*expander(size_t *i, char *cmd_line, char **envp)
{
	size_t	j;
	size_t	len;
	char	*variable;
	char	*result;

	(*i)++;
	j = (*i);
	while (check_char_expander(cmd_line[j]))
		j++;
	len = j - (*i);
	if (len == 0)
		return (variable_with_zero_length(cmd_line[*i], 1));
	variable = ft_strdup_len(&cmd_line[*i], len);
	(*i) = (*i) + len;
	result = variable_finder(variable, len, envp);
	free (variable);
	return (result);
}

char	*expand_word(size_t *i, char *cmd_line, char *prev, char **envp)
{
	char	*text;
	char	*result;

	text = expander(i, cmd_line, envp);
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
	if (check_next_char(cmd_line[*i]) == 1)
		result = quote(i, cmd_line, result, envp);
	else if (check_next_char(cmd_line[*i]) == 2)
		result = word_maker(i, cmd_line, result, envp);
	else if (check_next_char(cmd_line[*i]) == 3)
		result = expand_word(i, cmd_line, result, envp);
	return (result);
}
