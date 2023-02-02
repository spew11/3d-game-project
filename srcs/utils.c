/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehykim <taehykim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 21:29:50 by taehykim          #+#    #+#             */
/*   Updated: 2023/02/01 19:47:03 by eunjilee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while ((s1[i] || s2[i]) && i < n)
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	src_len;

	i = 0;
	src_len = 0;
	while (src[src_len])
		src_len++;
	i = 0;
	if (dstsize == 0)
		return (src_len);
	while ((i + 1 < dstsize) && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (src_len);
}

static int	get_answer(const char *str, int sign)
{
	unsigned long long	result;
	int					arr_len;

	result = 0;
	arr_len = 0;
	while ('0' <= *str && *str <= '9')
	{
		arr_len++;
		result = result * 10 + *str - 48;
		if ((result > 2147483647) && sign == 1)
			exit_error("incorrect map\n");
		if ((result > 2147483648) && sign == -1)
			exit_error("incorrect map\n");
		str++;
	}
	return (sign * (int)result);
}

int	ft_atoi(const char *str)
{
	int	sign;

	sign = 1;
	if (*str == '\0')
		exit_error("incorrect map\n");
	while (*str == 32 || (9 <= *str && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while (*str == '0')
		str++;
	if ('0' > *str || *str > '9')
		return (0);
	return (get_answer(str, sign));
}

char	*ft_strdup_except_nl(const char *s1)
{
	int		i;
	char	*arr;

	i = 0;
	while (s1[i])
		i++;
	arr = (char *)malloc(sizeof(char) * i);
	if (!arr)
		return (NULL);
	arr[i - 1] = '\0';
	i -= 2;
	while (i >= 0)
	{
		arr[i] = s1[i];
		i--;
	}
	return (arr);
}
