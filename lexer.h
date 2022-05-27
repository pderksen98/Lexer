/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lexer.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: pderksen <pderksen@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/19 14:16:54 by pderksen      #+#    #+#                 */
/*   Updated: 2022/05/27 12:57:09 by pderksen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H
# include "libft/libft.h"
# include <readline/readline.h>
# include <readline/history.h>

typedef struct s_list
{
	void			*ct;
	struct s_list	*next;
}	t_list;

typedef	enum s_type
{
	FILEE = 1,
	CMD,
	ARG,
	PIPE,
	GREATER,
	GREATER_GREATER,
	SMALLER,
	SMALLER_SMALLER,
	HERE_DOC_TEXT,
}	t_type;

typedef struct s_token
{
	char			*string;
	t_type			type;
}	t_token;

typedef struct	s_prev
{
	int	op;
	int	h_d;
	int	cmd;
}	t_prev;

int		main(int argc, char **argv, char **envp);
void	call_functions(char *input);
void	make_linked_list(t_token **list, char *input);
t_token	*create_new_token(char *string, int type);
int		check_quotes(char *input);
int		search_matching_quote(char *input, char quote, int i);
#endif
