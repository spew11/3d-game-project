/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_nl.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehykim <taehykim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 21:29:23 by taehykim          #+#    #+#             */
/*   Updated: 2023/01/29 21:29:24 by taehykim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int	count(char const *s, char c)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	while (s[i] == c && s[i] != '\0')
		i++;
	while (s[i] != '\0')
	{
		count++;
		while (s[i] != '\0' && s[i] != c)
			i++;
		while (s[i] == c && s[i] != '\0')
		{
			if (s[i + 1] != '\0')
			{
				if (!ft_strncmp(&s[i], "\n\n", 2))
					count++;
			}
			i++;
		}
	}	
	return (count);
}

static void	get_length(int *size, int *k, char const *s, char c)
{
	*size = 0;
	if (!ft_strncmp(&s[*k], "\n\n", 2))
	{
		*size += 1;
		*k += 1;
		return ;
	}
	while (s[*k] != '\0' && s[*k] == c)
			*k += 1;
	while (s[*k] != '\0' && s[*k] != c)
	{
		*size += 1;
		*k += 1;
	}
}

static void	ft_malloc(char **strs, int size, int i)
{
	strs[i] = (char *)malloc(sizeof(char) * (size + 1));
	if (strs[i] == 0)
		ft_free_split(strs, i);
}

static void	go_split(char **strs, char const *s, char c, int i)
{
	int	k;
	int	size;
	int	j;

	k = 0;
	while (s[k])
	{
		get_length(&size, &k, s, c);
		ft_malloc(strs, size, i);
		j = 0;
		k -= size;
		while (j < size)
		{
			if (s[k] == '\n')
			{
				strs[i][j++] = ' ';
				k++;
			}
			else
				strs[i][j++] = s[k++];
		}
		strs[i][j] = '\0';
		++i;
	}
	strs[i] = 0;
}

char	**ft_split_nl(char const *s, char c)
{
	char	**strs;
	int		size;
	int		i;

	if (!s)
		return (NULL);
	size = count(s, c);
	i = 0;
	size += 2;
	strs = (char **)malloc(sizeof(char *) * (size + 1));
	if (!strs)
		return (NULL);
	i = 0;
	go_split(strs, s, c, i);
	return (strs);
}
