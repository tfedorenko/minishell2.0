/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfedoren <tfedoren@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 16:12:52 by tfedoren          #+#    #+#             */
/*   Updated: 2022/08/29 08:27:57 by tfedoren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// int special_char_handler(t_list_lexer *tokens, const char *line, int i, int *t);
// int word_handler(t_list_lexer *tokens, const char *line, int i, int *t);
// int char_handler(t_list_lexer *tokens, const char *line, int *i);
// int	quotes_handler(t_list_lexer *tokens, const char *line, int i, int *t);
// int	find_special(char c);

int	lexer(t_minishell *tokens, const char *line)
{
	int	i;

	i = 0;

	while (line && line[i])
	{

		// ft_printf("test3\n");
		if (line[i] && find_space(line[i]) && push_to_list(tokens, SEP, NULL))
		{
			// push_to_list(tokens, SEP, NULL, f);
			write (1, "error1\n", 7);
			return (1);
		}
		while (line[i] && find_space(line[i]))
			++i;
		// ft_printf("test4\n");
		if (char_handler(tokens, line, &i))
			return (1);
	}
	return (0);
}

int char_handler(t_minishell*tokens, const char *line, int *i)
{
	int t;
	if (line[*i] == '\'' || line[*i] == '\"')
	{
		if (quotes_handler(tokens, line, *i, &t))
		{
			write(1, "error2\n", 7);
			return (1);			
		}
		if (t == 0)
		{
			write(1, "error: unclosed quotes\n", 23);
			return (1);			
		}

		*i += t + 1;
	}
	else if (line[*i] && find_special(line[*i]))
	{
		if (special_char_handler(tokens, line, *i, &t))
		{
			return(1);
		}
		*i += t + 1;
	}
	else if (line[*i])
	{
		if (word_handler(tokens, line, *i, &t))
		{
			write(1, "error3\n", 7);
			return (1);
		}
		*i +=t;
	}
	// printf("Halp god\n");
	// printf("Halp god = %d\n",tokens->head->key);


	return (0);
}

int	get_type(const char *line, int i)
{
	if (line[i] == '|')
		return (PIPE);
	if (line[i] == '>' && line[i + 1] && line[i + 1] == '>')
		return (REDIR_APPEND);
	if (line[i] == '>')
		return (REDIR_OUT);
	if (line[i] == '<' && line[i + 1] && line[i + 1] == '<')
		return (REDIR_SOURCE);
	if (line[i] == '<')
		return (REDIR_IN);
	return (NCONST);
}

/**returns i if qoutes finded and 0 if not**/

int	find_quote(const char *line, char quote)
{
	int	i;

	i = 1;
	while (line[i])
	{
		if (line[i] == quote)
			return (i);
		i++;
	}
	return (0);
}

int	find_space(char c)
{
	if (c == ' ' || c == '\n' || c == '\t' || c == '\r' \
					|| c == '\v' || c == '\f')
		return (c);
	return(0);
}

int	find_special(char c)
{
	if (c == '|' || c == '>' || c == '<')
		return (c);
	return(0);
}

int	quotes_handler(t_minishell *tokens, const char *line, int i, int *t)
{
	char	*substring;
	int		key_word;

	*t = find_quote(line + i, line[i]);
	if (*t == 0)
		return (*t);
	substring = ft_substr(line, i + 1, *t - 1);
	if (substring == NULL)
		return (1);
	if (line[i] == '\'')
		key_word = INSIDE_SQ;
	if (line[i] == '\"')
		key_word = INSIDE_DQ;
	if ( push_to_list(tokens, key_word, substring))
	{
		free(substring);
		return (1);
	}
	return (0);
}

int word_handler(t_minishell *tokens, const char *line, int i, int *t)
{
	char	*substring;

	*t = 0;
	while (line[i + *t] && !find_space(line[i + *t]) \
			&& !find_special(line[i + *t]) && \
			line[i + *t] != '\'' && line[i + *t] != '\"')
			++(*t);
	substring = ft_substr(line, i, *t);
	if (substring == NULL)
		return (1);
	if (push_to_list(tokens, WORD, substring))
		return (1);
	return (0);
}

int special_char_handler(t_minishell *tokens, const char *line, int i, int *t)
{
	*t = get_type(line, i);
	if (*t == NCONST)
	{
		write (1, "error: wrong input\n", 19);
		return (1);
	}
	if (push_to_list(tokens, (*t), NULL))
	{
		write(1, "error4\n", 7);
		return (1);
	}
	// ft_printf("test5\n");
	*t = (*t == REDIR_APPEND || *t == REDIR_SOURCE);
	
	return (0);
}
