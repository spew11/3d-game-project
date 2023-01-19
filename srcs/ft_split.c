/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehykim <taehykim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 17:43:34 by taehykim          #+#    #+#             */
/*   Updated: 2022/08/23 17:43:37 by taehykim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int	count(char const *s, char c)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	if (s[i] == c && s[i] != '\0')
		i++;
	while (s[i] != '\0')
	{
		count++;
		while (s[i] != '\0' && s[i] != c)
			i++;
		if (s[i] == c && s[i] != '\0')
			i++;
	}	
	return (count);
}

static void	get_length(int *size, int *k, char const *s, char c)
{
	if (s[*k] != '\0' && s[*k] == c)
		*k += 1;
	while (s[*k] != '\0' && s[*k] != c)
	{
		*size += 1;
		*k += 1;
	}
}

static void	ft_free(char **strs, int i)
{
	int	index;

	index = i - 1;
	while (index >= 0)
	{
		free(strs[index]);
		strs[index] = NULL;
		--index;
	}
	free(strs);
	strs = 0;
	return ;
}

static void	go_split(char **strs, char const *s, char c, int i)
{
	int	k;
	int	size;
	int	j;

	k = 0;
	while (s[k])
	{
		size = 0;
		get_length(&size, &k, s, c);
		// printf("s = %d k = %d\n", size, k);
		if (!size)
		{
			// printf("aasdfasdfs %d\n", i);
			strs[i] = (char *)malloc(sizeof(char) * (2));
			strs[i][0] = ' ';
			strs[i][1] = '\0';
			printf("***%d****%s****\n", i, strs[i]);
			i++;
			continue ;
		}
		strs[i] = (char *)malloc(sizeof(char) * (size + 1));
		if (strs[i] == 0)
		{
			ft_free(strs, i);
			exit_error("malloc error\n");
		}
		j = 0;
		k -= size;
		while (j < size)
			strs[i][j++] = s[k++];
		strs[i][j] = '\0';
		// if (i == 6) {
			// printf("****%s****\n", strs[i]);
		// }
		printf("***%d****%s****\n", i, strs[i]);
		i++;
	}
	//printf("hihi %d", i);
	//printf("before end***%d****%s****\n", i, strs[11]);
	strs[i] = 0;
}

char	**ft_split(char const *s, char c)
{
	char	**strs;
	int		size;
	int		i;

	if (!s)
		return (NULL);
	size = count(s, c);
	// printf("%s = %d\n", s, size);
	strs = (char **)malloc(sizeof(char *) * (size + 1));
	if (!strs)
		exit_error("malloc error\n");
	i = 0;
	go_split(strs, s, c, i);
	//printf("end*******%s****\n", strs[6]);
	return (strs);
}
