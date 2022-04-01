/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: safernan <safernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 23:21:53 by safernan          #+#    #+#             */
/*   Updated: 2022/04/01 04:16:58 by safernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int main(int argc, char **argv, char **env)
{
    char    *buffer;
    int     i;
    while (1)
    {
        buffer = readline("safernan $>");
        if (strcmp(buffer, "exit") == 0)
        {
            free(buffer);
            return (0);
        }
        add_history(buffer);
		printf("-------------------------------------\n");
        printf("char *buffer readline -> : %s\n", buffer);
		printf("-------------------------------------\n");
        parsing(buffer, i);
        free(buffer);
        
    }
   return (0);
}

int    parsing(char *buffer, int i)
{
    char    **str = NULL;
    t_sep	*list;
    
	str = ft_split(buffer, ' ');
	i = 0;
    while (str[++i])
    {
      list = add_cell(list, str[i], i);
	  printf("=================\n");
	  printf("%s\n", str[i]);
	  printf("=================\n");
    }
	str = malloc(sizeof(char*) * (i + 1));
	str[i] = NULL;
    return (0);
}