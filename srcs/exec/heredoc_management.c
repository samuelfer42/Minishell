/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_management.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: safernan <safernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 13:58:49 by safernan          #+#    #+#             */
/*   Updated: 2022/05/01 18:54:58 by safernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	handle_heredoc(t_redirection *redirection, t_shell *shell,
		t_command *command)
{
	int	fd[2];
	int	reader;

	if (pipe(fd) == -1)
		return (error_system(shell, PIPE_FORK));
	reader = fork();
	if (reader < 0)
		return (error_system(shell, PIPE_FORK));
	if (reader == 0)
	{
		new_line_until_delimitator(fd, redirection->file);
		close(fd[1]);
		if (command == NULL)
			free_redirection(&redirection);
		free_all(shell);
		exit(g_signal);
	}
	else
	{
		waitpid(reader, &g_signal, 0);
		g_signal = WEXITSTATUS(g_signal);
		close(fd[1]);
		close(fd[0]);
	}
	return (0);
}

void	new_line_until_delimitator(int *fd, char *file)
{
	char	*line;

	close (fd[0]);
	ft_putstr_fd("> ", STDOUT_FILENO);
	while (get_next_line(STDIN_FILENO, &line, file) > 0)
	{
		if (ft_strncmp(line, file, ft_strlen(file)) == 0)
		{
			free(line);
			return ;
		}
		ft_putstr_fd("> ", STDOUT_FILENO);
		ft_putstr_fd(line, fd[1]);
		free(line);
	}
}
