/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy_without_cara.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: safernan <safernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 17:42:21 by safernan          #+#    #+#             */
/*   Updated: 2022/04/29 20:50:42 by safernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

int	ft_strlcpy_without_cara(char *dst, char *src, char cara)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (src[j] != '\0')
	{
		while (src[j] == cara)
			j++;
		if (src[j] == '\0')
			break ;
		dst[i] = src[j];
		i++;
		j++;
	}
	dst[i] = '\0';
	return (ft_strlen((char *)dst));
}
