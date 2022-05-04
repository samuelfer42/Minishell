/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: safernan <safernan@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/17 23:11:51 by safernan          #+#    #+#             */
/*   Updated: 2021/12/14 16:14:37 by safernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void				*ptr;
	char				*str;
	unsigned int		i;

	i = 0;
	ptr = malloc(count * size);
	if (!ptr)
		return (NULL);
	str = ptr;
	while (i < count * size)
	{
		str[i] = 0;
		i++;
	}
	return (str);
}
