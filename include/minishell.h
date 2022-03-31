/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: safernan <safernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 00:30:07 by safernan          #+#    #+#             */
/*   Updated: 2022/03/31 05:52:01 by safernan         ###   ########.fr       */
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
typedef struct	s_split
{
	int		k;
	int		i;
	int		j;
	int		len;
	int		count_words;
	char	c;
	char	**str;
}				t_split;
int			ft_malloc_words_util(char const *s, char c, t_split *sp);
static int	ft_count_words(char const *s, char c, t_split *sp);
int			ft_count_words_util(char const *s, t_split *sp);
size_t  	ft_strlen(const char *s);
int			ft_malloc_words(char const *s, char **str,
			int words, t_split *sp);
char		**ft_minishell_split(char const *s, char c);
void		ft_leah_minishell(char **str, int index);
int			protection(char const *s, int i, char c, t_split *split);
void			ft_write_words_util(char const *s, t_split *sp);
void			ft_write_words_minishell(char const *s, int words, t_split *sp);
//Liste
void	    print_list(t_sep *list);
t_sep	    *add_cell(t_sep *list, char *cmd_sep, int pos);
t_sep	    *create_cell(char *cmd_sep);

int        parsing(char *buffer, int i);

#endif