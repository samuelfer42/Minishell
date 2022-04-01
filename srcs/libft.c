/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: safernan <safernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 04:36:38 by safernan          #+#    #+#             */
/*   Updated: 2022/04/01 03:30:33 by safernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

static void		fill_line(char const *s, char c, int count, char *new)
{
	int		i;
	int		booleen;
	int		nbr;

	i = -1;
	nbr = 0;
	booleen = 0;
	while (nbr < count + 1)
	{
		i++;
		if (s[i] != c && booleen == 0)
		{
			nbr++;
			booleen = 1;
		}
		if (s[i] == c && booleen == 1)
			booleen = 0;
	}
	while (s[i + booleen - 1] != c && s[i + booleen - 1])
	{
		new[booleen - 1] = s[i + booleen - 1];
		booleen++;
	}
	return ;
}

static int		len_word(char const *s, char c, int count)
{
	int		i;
	int		booleen;
	int		nbr;

	i = -1;
	nbr = 0;
	booleen = 0;
	while (nbr < count + 1)
	{
		i++;
		if (s[i] != c && booleen == 0)
		{
			nbr++;
			booleen = 1;
		}
		if (s[i] == c && booleen == 1)
			booleen = 0;
	}
	while (s[i] != c && s[i])
	{
		i++;
		booleen++;
	}
	return (booleen - 1);
}

static int		nbr_word(char const *s, char c)
{
	int		i;
	int		booleen;
	int		nbr;

	nbr = 0;
	i = 0;
	booleen = 0;
	while (s[i])
	{
		if (s[i] != c && booleen == 0)
		{
			nbr++;
			booleen = 1;
		}
		if (s[i] == c && booleen == 1)
			booleen = 0;
		i++;
	}
	return (nbr);
}

char			**ft_split(char const *s, char c)
{
	char	**new;
	int		i;

	i = 0;
	if (s == 0)
		return (0);
	if (!(new = malloc(sizeof(char*) * (nbr_word(s, c) + 1))))
		return (0);
	while (i < nbr_word(s, c))
	{
		if (!(new[i] = malloc(sizeof(char) * (len_word(s, c, i) + 1))))
			return (0);
		fill_line(s, c, i, new[i]);
		new[i][len_word(s, c, i)] = 0;
		i++;
	}
	new[nbr_word(s, c)] = 0;
	return (new);
}