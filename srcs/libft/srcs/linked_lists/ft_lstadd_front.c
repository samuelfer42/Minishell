/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: safernan <safernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/15 18:55:52 by safernan          #+#    #+#             */
/*   Updated: 2021/05/12 10:42:04 by safernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

void	ft_lstadd_front(t_list **alst, t_list *new)
{
	if (alst != NULL)
	{
		new->next = *alst;
		*alst = new;
	}
}
