/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lexer.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: pderksen <pderksen@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/19 14:16:54 by pderksen      #+#    #+#                 */
/*   Updated: 2022/07/01 12:33:34 by pieterderks   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H
# include "libft/libft.h"
# include <readline/readline.h>
# include <readline/history.h>

// typedef struct s_list
// {
// 	void			*ct;
// 	struct s_list	*next;
// }	t_list;

typedef enum e_ascii
{
	e_SPACE = 32,
	e_BIG = 62,
	e_SMALL = 60,
	s_QUOTE = 39,
	d_QUOTE = 34,
	e_PIPE = 124,
	e_DOLLAR = 36,
}	t_ascii;

typedef enum s_type
{
	FILENAME,
	CMD,
	CMD_ARG,
	PIPE,
	APPEND,
	REDIRECT,
	HERE_DOC,
	INPUT,
	HERE_DOC_TEXT,
	WORD,
}	t_type;

typedef struct s_specify
{
	int	redirect;
	int	here_doc;
	int	command;
}	t_specify;

typedef struct s_token
{
	char			*string;
	t_type			type;
}	t_token;

typedef struct s_prev
{
	int	op;
	int	h_d;
	int	cmd;
}	t_prev;

int		main(int argc, char **argv, char **envp);
void	call_functions(char *input);
int		check_quotes(char *input);
int		search_matching_quote(char *input, char quote, int i);
t_list	*lexer(char *cmd_line);
void	split_cmd_line(t_list **tokens, size_t *i, char c, char *cmd_line);
void	pipe(t_list **tokens, size_t *i);
void	check_smal(t_list **tokens, size_t *i, char *cmd_line);
void	check_big(t_list **tokens, size_t *i, char *cmd_line);
char	*ft_strdup_len(const char *str, size_t len);
size_t	ft_strlen_c(const char *str, int c);
void	string_maker(t_list **tokens, size_t *i, char *cmd_line, char c);
int		check_next_char(char c);
char	*create_word(char *cmd_line, size_t *i);
char	*quote(size_t *i, char *cmd_line, char *prev, char quot);
char	*word_maker(size_t *i, char *cmd_line, char *prev);
char	*between_quotes(char *cmd_line, size_t *i, char quote);
void	print_link_list(t_list **tokens);
void	token_specifier(t_list **tokens);
void	word_specifier(t_token *token, t_specify *prev);
void	adjust_specify_struct(t_specify *prev, int code);
#endif
