/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: safernan <safernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 14:39:59 by safernan          #+#    #+#             */
/*   Updated: 2022/04/20 14:40:52 by safernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

void	print_env(char	**tab)
{
	int	i;

	i = 0;
	while (tab[i] != NULL)
	{
		if (find_cara_in_word(tab[i], '=') != -1)
			printf("%s\n", tab[i]);
		i++;
	}
}
