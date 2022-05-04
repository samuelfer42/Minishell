/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: safernan <safernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 13:48:18 by safernan          #+#    #+#             */
/*   Updated: 2022/04/21 14:15:12 by safernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

void	ft_export(t_shell *shell, t_token *token)
{
	token = token->next;
	if (export_without_argument(shell, &token) == 1)
		return ;
	while (token != NULL && (token->type == WORD || token->type == EQUAL))
	{
		if (token->type == WORD)
			check_variable_needs_to_be_created(shell, &token);
		else if (token->type == EQUAL)
			return (error_message(EXPORT_ERROR, 1));
		if (token == NULL || g_signal != 0)
			break ;
		token = token->next;
	}
}

void	create_lonely_env_variable(t_shell *shell, t_token *token)
{
	char	*new_env_variable;

	if (token->next != NULL)
		token = token->previous;
	if (check_if_variable_already_exists(shell, token->content) == 1)
		return ;
	new_env_variable = ft_strdup(token->content);
	add_new_env_variable(new_env_variable, shell);
}

void	create_new_env_variable(t_shell *shell, t_token **token)
{
	char	*new_env_variable;
	char	*temp;

	*token = (*token)->previous;
	new_env_variable = ft_strdup((*token)->content);
	*token = (*token)->next;
	while (*token != NULL)
	{
		if ((*token)->type == PIPE || (*token)->type == REDIR_LEFT
			|| (*token)->type == REDIR_RIGHT || (*token)->type == HEREDOC
			|| (*token)->type == D_REDIR_RIGHT || (*token)->type == WHITE_SPACE)
			break ;
		temp = new_env_variable;
		new_env_variable = ft_strjoin(new_env_variable, (*token)->content);
		free(temp);
		*token = (*token)->next;
	}
	temp = ft_cut_str(new_env_variable, 0, find_cara_in_word(new_env_variable,
				'='));
	if (check_if_variable_already_exists(shell, temp) == 1)
		delete_env_variable(shell, temp);
	free(temp);
	add_new_env_variable(new_env_variable, shell);
}

void	check_variable_needs_to_be_created(t_shell *shell, t_token **token)
{
	if ((*token)->next == NULL)
		return (create_lonely_env_variable(shell, *token));
	*token = (*token)->next;
	if ((*token)->type == WHITE_SPACE && (*token)->next != NULL
		&& (*token)->next->type == EQUAL)
	{
		create_lonely_env_variable(shell, *token);
		return (error_message(EXPORT_ERROR, 1));
	}
	else if ((*token)->type == WHITE_SPACE)
		create_lonely_env_variable(shell, *token);
	else if ((*token)->type == EQUAL)
		create_new_env_variable(shell, token);
}
