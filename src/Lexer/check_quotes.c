/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_quotes.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: pderksen <pderksen@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/25 13:59:16 by pderksen      #+#    #+#                 */
/*   Updated: 2022/07/04 14:52:40 by pderksen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../lexer.h"

//loops through the string to find the matching single or double quote
int	search_matching_quote(char *input, char quote, int i)
{
	while (input[i])
	{
		if (input[i] == quote)
			return (i);
		i++;
	}
	return (0);
}

//checks the input line for single and double quotes
//if it finds one it calls the search_matching_quote function
int	check_quotes(char *input)
{
	int	i;
	int	tokens;

	i = 0;
	tokens = 0;
	while (input[i])
	{
		if (input[i] == 34 || input[i] == 39)
		{
			i = search_matching_quote(input, input[i], (i + 1));
			if (i == 0)
			{
				ft_putstr_fd("Error: Not a matching single or \
					double quote\n", 2);
				return (EXIT_FAILURE);
			}
			tokens++;
		}
		i++;
	}
	return (EXIT_SUCCESS);
}
