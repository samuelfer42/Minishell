/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: safernan <safernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 23:21:53 by safernan          #+#    #+#             */
/*   Updated: 2022/03/31 06:25:57 by safernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int main(int argc, char **argv, char **env)
{
    char    *buffer;
    int     i;
    i = 0;
    while (1)
    {
        buffer = readline("safernan $>");
        if (strcmp(buffer, "exit") == 0)
        {
            free(buffer);
            return (0);
        }
        add_history(buffer);
        parsing(buffer, i);
        free(buffer);
        
    }
   return (0);
}

int    parsing(char *buffer, int i)
{
    char    **str;
    t_sep	*list;
 
  //  str = (char **)malloc(sizeof(char *) * 1);
    
    while (str[++i])
    {
      //  str = ft_split(buffer, ';');
        list = add_cell(list, str[i], i);
       // print_list(list);
    }
    return (0);
}