/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: safernan <safernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 07:49:46 by safernan          #+#    #+#             */
/*   Updated: 2022/05/01 18:56:40 by safernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXEC_H
# define EXEC_H

/*
** LAUNCH_SHELL
*/

int			launch_shell(t_shell *shell);
int			prompt(char **user_input, t_shell *shell);
void		free_all(t_shell *shell);

/*
** EXECUTE_INPUT
*/

int			execute_input(t_shell *shell, t_token *token, t_command *command);
void		launch_command(t_shell *shell, t_token *token, t_command *command);
void		handle_command(t_shell *shell, t_token *token,
				t_command *command);
int			execute_child_process(t_shell *shell, t_token *token,
				t_command *command);
void		execute_parent_process(t_shell *shell, t_token *token,
				t_command *command, int pid);

/*
** REDIRECTIONS
*/

void		handle_redirection(t_command *command, t_shell *shell,
				t_token *token);
int			create_file(t_redirection *redirection, t_shell *shell,
				t_command *command);
int			initialize_redir(t_shell *shell);
void		reset_fd(t_shell *shell);
int			handle_heredoc(t_redirection *redirection, t_shell *shell,
				t_command *command);
void		new_line_until_delimitator(int *fd, char *file);
void		open_fd(t_shell *shell, t_redirection *redirection);

/*
** COMMAND
*/

void		ft_pwd(t_shell *shell);
void		ft_echo(t_token *token);
void		create_buffer_for_echo(t_token *token, char **str);
void		ft_exit(t_shell *shell, t_token *token, t_command *command);
void		exit_basic_case(t_shell *shell, t_token *token, t_command *command);
void		exit_numeric_issue(t_shell *shell, t_command *command);
int			check_number_of_arguments(t_token *token, int exit_case,
				t_command *command);
void		close_fd(t_shell *shell, t_command *command);
int			handle_cases_other_than_words(t_token *token);
void		ft_cd(t_shell *shell, t_token *token, t_command *command);
void		ft_export(t_shell *shell, t_token *token);
void		check_variable_needs_to_be_created(t_shell *shell, t_token **token);
int			export_without_argument(t_shell *shell, t_token **token);
char		**create_binary(t_token *token);
int			command_lenght(t_token *token);
void		case_execve_fail(t_shell *shell, int exit_or_return,
				char **command);
int			check_if_variable_already_exists(t_shell *shell,
				char *new_env_variable);
void		delete_env_variable(t_shell *shell, char *env_to_delete);
void		ft_unset(t_shell *shell, t_token *token);
char		**copy_previous_env_variable(t_shell *shell, char *env_to_delete);
void		execute_binary(t_shell *shell, t_token *token, int exit_or_return);
void		create_new_env_variable(t_shell *shell, t_token **token);
void		create_lonely_env_variable(t_shell *shell, t_token *token);
void		add_new_env_variable(char *new_env_variable, t_shell *shell);
void		execute_executable(t_shell *shell, t_token *token);
void		print_env(char **tab);
void		print_tab(char **tab);
char		**export_tab(char **tab);

/*
** SIGNALS
*/

void		handle_signals(int signum);
void		handle_exec_signals(int signum);

/*
** PIPE
*/

int			handle_pipe(t_shell *shell, t_command *command,
				t_token *token);
void		child_process(t_shell *shell, t_token *token, t_command *command);
void		parent_process(pid_t pid, t_shell *shell);
void		handle_pipe_builtin(t_shell *shell, t_token *token,
				t_command *command);
void		handle_pipe_bin(t_shell *shell, t_token *token,
				t_command *command);
void		pipe_redirection(t_shell *shell, t_command *command);
void		clean_after_pipe(t_shell *shell);

#endif
