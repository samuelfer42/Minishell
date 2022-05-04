/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_double_free.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: safernan <safernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 15:48:18 by safernan          #+#    #+#             */
/*   Updated: 2022/02/20 18:32:43 by safernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

void	ft_double_free_list(t_double_list **list, int free_content)
{
	t_double_list	*temp;

	if (*list == NULL || list == NULL)
		return ;
	while ((*list)->next != NULL)
	{
		temp = (*list)->next;
		if (free_content == 1)
			free((*list)->content);
		free(*list);
		*list = temp;
	}
	if (free_content == 1)
		free((*list)->content);
	free(*list);
	*list = NULL;
}
