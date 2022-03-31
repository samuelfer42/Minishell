/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: safernan <safernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 03:22:59 by safernan          #+#    #+#             */
/*   Updated: 2022/03/31 03:28:59 by safernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

t_sep	*create_cell(char *cmd_sep)     // fonction qui créent les cellules
{
  t_sep	*cell;

  cell = malloc(sizeof(t_sep));
  if (!(cell))
  	return (NULL);
  cell->prev = NULL;
  cell->next = NULL;
  cell->cmd_sep = cmd_sep;
  return (cell);
}

t_sep	*add_cell(t_sep *list, char *cmd_sep, int pos)  // fonction qui ajoute une cellule
{
  t_sep	*prec;
  t_sep	*cur;
  t_sep	*cell;
  int		i;

  cur = list;
  i = 0;
  cell = create_cell(cmd_sep);
  if (list == NULL)
  	return (cell);
  while (i < pos)
  {
  	i++;
  	prec = cur;
  	cur = cur->next;
  }
  prec->next = cell;
  cell->next = cur;
  return (list);
}

void	print_list(t_sep *list)     // imprimer les cellules
{
  int		i;

  i = 0;
  while (list)
  {
  	printf("-----------------------------------\n");
  	printf("| i = %d                            \n", i);
  	printf("| list->cmd_sep : %s            \n", list->cmd_sep);
  	printf("-----------------------------------\n");
  	list = list->next;
  	i++;
  }
}