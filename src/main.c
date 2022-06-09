/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: pderksen <pderksen@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/19 11:34:47 by pderksen      #+#    #+#                 */
/*   Updated: 2022/05/26 15:02:11 by pderksen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../lexer.h"

void	call_functions(char *input)
{
	t_list	*list;

	list = NULL;
	if (check_quotes(input) == 1)
		return ;
	list = lexer(input);
	print_link_list(&list);
	return ;
}

int	main(int argc, char **argv, char **envp)
{
	(void)argv;
	(void)envp;
	char	*line;

	if (argc != 1 || argv[1])
	{
		printf("This program does nog accept arguments\n");
		exit(0);
	}
	while (1)
	{
		line = readline("minishell>");
		call_functions(line);
		free(line);
	}
	return(0);
}
