/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: safernan <safernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 00:30:07 by safernan          #+#    #+#             */
/*   Updated: 2022/04/01 04:06:23 by safernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef MINISHELL_H
# define MINISHELL_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <string.h>

typedef	struct			s_sep
{
	char				*cmd_sep;
	struct s_sep		*prev;
	struct s_sep		*next;
}						t_sep;

//Libft

size_t  	ft_strlen(const char *s);
char		**ft_split(char const *s, char c);

//Liste
void	    print_list(t_sep *list);
t_sep	    *add_cell(t_sep *list, char *cmd_sep, int pos);
t_sep	    *create_cell(char *cmd_sep);

int        parsing(char *buffer, int i);

#endif