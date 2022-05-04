/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_type_node.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: safernan <safernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 18:30:51 by safernan          #+#    #+#             */
/*   Updated: 2022/03/09 17:28:11 by safernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

void	delete_type_node(t_type	**type)
{
	t_type	*temp;

	temp = (*type)->next;
	(*type)->next = temp->next;
	if ((*type)->next != NULL)
		(*type)->next->previous = temp->previous;
	free(temp);
}
