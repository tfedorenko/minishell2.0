/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfedoren <tfedoren@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 00:35:01 by tfedoren          #+#    #+#             */
/*   Updated: 2022/09/10 22:53:28 by tfedoren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

extern int	g_stat;

t_token	*expand(t_token *token, t_env *env);
void	set_expanded_value(t_token *token, char *replaced, int start, \
			int *index);
void	expand_home_var(t_token *tmp, t_env *env, int *index);
void	expand_env_var(t_token *tmp, t_env *env, int *index);

t_token	*expand(t_token *token, t_env *env)
{
	int		i;
	int		squote;
	int		dquote;
	t_token	*tmp;

	tmp = token;
	while (tmp)
	{
		i = 0;
		squote = 0;
		dquote = 0;
		while (tmp->value && tmp->value[i] != '\0')
		{
			check_quote(tmp->value[i], &squote, &dquote);
			if (is_general_env_var(tmp->value + i, squote))
				expand_env_var(tmp, env, &i);
			else if (i == 0 && is_home_env_var(tmp->value, squote))
				expand_home_var(tmp, env, &i);
			else
				i++;
		}
		tmp = tmp->next;
	}
	return (token);
}

void	expand_env_var(t_token *tmp, t_env *env, int *index)
{
	int		start;
	char	*target;
	char	*replaced;

	start = (*index) + 1;
	(*index)++;
	while ((ft_isalpha(tmp->value[*index]) == 1 || \
			ft_isdigit(tmp->value[*index])) && tmp->value[*index] != '\0')
		(*index)++;
	target = ft_substr(tmp->value, start, (*index) - start);
	replaced = search_env(env, target);
	free(target);
	set_expanded_value(tmp, replaced, start, index);
}

void	expand_home_var(t_token *tmp, t_env *env, int *index)
{
	char	*replaced;

	replaced = search_env(env, "HOME");
	if (!replaced)
		replaced = ft_strdup(getenv("HOME"));
	(*index)++;
	set_expanded_value(tmp, replaced, 1, index);
}

void	set_expanded_value(t_token *token, char *replaced, int start, \
			int *index)
{
	char	*head;
	char	*tail;

	if (token->value[start] == '?')
	{
		replaced = ft_itoa(g_stat);
		(*index) = start + 1;
	}
	if (!replaced)
		replaced = ft_strdup("");
	head = ft_substr(token->value, 0, start - 1);
	tail = ft_substr(token->value, *index, ft_strlen(token->value));
	free(token->value);
	token->value = ft_strjoin(head, replaced);
	token->value = ft_strjoin_free_s1(token->value, tail);
	free(replaced);
	free(head);
	free(tail);
	if (ft_strlen(token->value) == 0)
	{
		free(token->value);
		token->value = NULL;
	}
	(*index) = (*index) - ((*index) - start + 1);
}
