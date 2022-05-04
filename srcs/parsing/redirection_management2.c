/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection_management2.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: safernan <safernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 08:06:15 by safernan          #+#    #+#             */
/*   Updated: 2022/05/01 18:57:35 by safernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

t_redirection	*create_redirection_struct(char *str, t_type type)
{
	t_redirection	*redirection;

	redirection = malloc(sizeof(*redirection));
	if (redirection == NULL)
		return (NULL);
	if (type == REDIR_RIGHT || type == D_REDIR_RIGHT)
		redirection->file = ft_strdup(find_file_for_redir(str, '>'));
	else if (type == REDIR_LEFT || type == HEREDOC)
		redirection->file = ft_strdup(find_file_for_redir(str, '<'));
	redirection->type = type;
	redirection->next = NULL;
	return (redirection);
}

char	*find_file_for_redir(char	*str, char redir)
{
	int	i;

	i = 0;
	while (str[i] != '\0' && (str[i] == redir || ft_isspace(str[i]) == 1))
		i++;
	return (&str[i]);
}

int	append_redirection_struct(t_redirection **redirection, char *str,
		t_type type)
{
	t_redirection	*temp;

	temp = *redirection;
	while ((temp)->next != NULL)
		temp = temp->next;
	temp->next = create_redirection_struct(str, type);
	if (temp->next == NULL)
	{
		error_message(MALLOC, 1);
		return (-1);
	}
	return (0);
}

void	print_redirection(t_redirection	*redirection)
{
	int	compt;

	compt = 0;
	if (redirection == NULL)
		return ;
	while (redirection->next != NULL)
	{
		printf("compt = %d content = %s\n", compt, (*redirection).file);
		compt++;
		redirection = redirection->next;
	}
	printf("compt = %d content = %s\n", compt, (*redirection).file);
}

int	check_creation_file(t_redirection *redir, t_shell *shell,
		t_token *token, t_command *command)
{
	if (token != NULL)
	{
		free_redirection(&redir);
		return (0);
	}
	if (create_file(redir, shell, command) < 0)
	{
		free_redirection(&redir);
		return (1);
	}
	return (42);
}
