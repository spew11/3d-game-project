#include "cub3D.h"

// char	*ft_strdup(const char *s1)
// {
// 	int		i;
// 	char	*arr;

// 	i = 0;
// 	while (s1[i])
// 	{
// 		i++;
// 	}
// 	arr = (char *)malloc(sizeof(char) * i + 1);
// 	if (!arr)
// 		return (NULL);
// 	arr[i] = '\0';
// 	i--;
// 	while (i >= 0)
// 	{
// 		arr[i] = s1[i];
// 		i--;
// 	}
// 	return (arr);
// }

void	free_arr_2(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		arr[i] = NULL;
		i++;
	}
	free(arr);
}

void	free_arr(char *arr)
{
	if (arr)
		free(arr);
}
