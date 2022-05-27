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




t_list	*lexer(char *cmd_line)
{
	t_list	*tokens;
	size_t	i;

	i = 0;
	tokens = NULL;
	while (cmd_line[i])
	{
		categorize_cmd_line(&tokens, &i, cmd_line[i], cmd_line);
		i++;
	}
}
