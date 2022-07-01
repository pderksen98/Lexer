/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   paths.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: pieterderksen <pieterderksen@student.co      +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/01 12:55:18 by pieterderks   #+#    #+#                 */
/*   Updated: 2022/07/01 14:15:16 by pieterderks   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

	// else if (check_next_char(cmd_line[*i] == 3))
	// 	result = expand_word(i, cmd_line, result);

char	*variable_finder(char **env, char *word, int word_len)
{
	while (*env)
	{
		if (ft_strncmp(word, *env, word_len) == 0)
			return (*env + (word_len + 1));
		env++;
	}
	return (NULL);
}

int	check_char_expander(char c)
{
	if (ft_isalpha(c) == 1)
		return (1);
	else if (ft_isdigit(c) == 1)
		return (1);
	
}


char	*create_variable_word(char *cmd_line, )


char	expand_word(size_t *i, char *cmd_line, char *prev)
{
	int		variable_len;
	char	*result;

	variable_len = 0;
	*i++;
	while (check_char_expander(cmd_line[*i]) == 1)
	{
		*i++;
		variable_len++;
	}
	if (variable_len == 0)
	{
		result = malloc(sizeof(char) * 2);
		ft_check_malloc(result);
		result[0] = '$';
		result[1] = '\0';
		return (result);
	}
	else
	{
		
	}
	
		
}

char	*expand_word(size_t *i, char *cmd_line, char *prev)


	// if (check_next_char(cmd_line[*i]) == 1)
	// 	result = quote(i, cmd_line, result, cmd_line[*i]);
	// else if (check_next_char(cmd_line[*i]) == 2)
	// 	result = word_maker(i, cmd_line, result);
	// return (result);