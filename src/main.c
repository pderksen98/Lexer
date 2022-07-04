/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: pderksen <pderksen@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/19 11:34:47 by pderksen      #+#    #+#                 */
/*   Updated: 2022/07/04 15:43:53 by pderksen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../lexer.h"

//Receives the cmd_line (input)
//calls the different functions with the input
void	call_functions(char *input, char **envp)
{
	t_list	*list;

	list = NULL;
	if (check_quotes(input) == 1)
		return ;
	list = lexer(input, envp);
	token_specifier(&list);
	print_link_list(&list);
	return ;
}

//Returns error when arguments are given
//Reads the command line, returns this line to call_functions
//When new line is given the old line is freed
int	main(int argc, char **argv, char **envp)
{
	char	*line;

	(void)argv;
	if (argc != 1 || argv[1])
	{
		printf("This program does nog accept arguments\n");
		exit(0);
	}
	while (1)
	{
		line = readline("minishell>");
		if (!line)
			break ;
		call_functions(line, envp);
		free(line);
	}
	return (0);
}
