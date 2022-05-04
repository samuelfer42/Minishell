/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   use_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: safernan <safernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 08:07:17 by safernan          #+#    #+#             */
/*   Updated: 2022/04/07 08:07:19 by safernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	get_env(t_shell *shell, char **envp)
{
	int	index;
	int	i;

	index = 0;
	i = 0;
	while (envp[index] != NULL)
		index++;
	shell->env->index = index;
	shell->env->env = copy_tab(envp, index);
	create_env_tab(shell);
	shell->env->alpha = NULL;
	while (i < index)
	{
		if (ft_strncmp(envp[i], "HOME=", ft_strlen("HOME=")) == 0)
			get_absolute_path(shell, envp[i]);
		i++;
	}
}

void	alpha_sort(t_shell *shell)
{
	int		i;
	int		j;
	char	*temp;
	int		size;

	i = 0;
	while (i < shell->env->index)
	{
		j = i + 1;
		while (j < shell->env->index)
		{
			size = ft_strlen(shell->env->alpha[i])
				+ ft_strlen(shell->env->alpha[j]);
			if (ft_strncmp(shell->env->alpha[i],
					shell->env->alpha[j], size) > 0)
			{
				temp = shell->env->alpha[i];
				shell->env->alpha[i] = shell->env->alpha[j];
				shell->env->alpha[j] = temp;
			}
			j++;
		}
		i++;
	}
}

void	get_absolute_path(t_shell *shell, char *path)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	shell->absolute_path = malloc(sizeof(char) * ft_strlen(path));
	if (shell->absolute_path == NULL)
		return ;
	while (path[i] != '\0' && path[i] != '=')
		i++;
	i++;
	while (path[i] != '\0')
	{
		shell->absolute_path[j] = path[i];
		i++;
		j++;
	}
	shell->absolute_path[j] = '\0';
}

void	create_env_tab(t_shell *shell)
{
	int	i;

	initialize_env_tab(shell);
	i = 0;
	while (i < shell->env->index)
	{
		if (find_cara_in_word(shell->env->env[i], '=') == -1)
		{
			shell->env->tab_variable_name[i] = ft_strdup(shell->env->env[i]);
			shell->env->tab_variable_equals[i] = ft_strdup("");
		}
		else
		{
			shell->env->tab_variable_name[i] = ft_cut_str(shell->env->env[i], 0,
					find_cara_in_word(shell->env->env[i], '='));
			shell->env->tab_variable_equals[i]
				= ft_strdup(ft_strchr((const char *)shell->env->env[i], '='));
		}
		i++;
	}
	shell->env->tab_variable_name[i] = NULL;
	shell->env->tab_variable_equals[i] = NULL;
}

char	**copy_tab(char **tab, int size)
{
	char	**new;
	int		i;

	new = malloc(sizeof(char *) * (size + 1));
	if (new == NULL)
		return (NULL);
	i = 0;
	while (tab[i] != NULL)
	{
		new[i] = ft_strdup(tab[i]);
		i++;
	}
	new[i] = NULL;
	return (new);
}
