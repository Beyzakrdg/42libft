/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bekarada <bekarada@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 13:45:09 by bekarada          #+#    #+#             */
/*   Updated: 2024/10/21 07:31:19 by bekarada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*ft_free(char **res, size_t i)
{
	while (i != 0)
	{
		free(res[i]);
		i--;
	}
	free(res[i]);
	free(res);
	return (NULL);
}

static void	ft_word(char const *str, size_t *start, size_t *end, char c)
{
	*start = *end;
	while (str[*start] == c)
		*start = *start + 1;
	*end = *start;
	while (str[*end] != c && str[*end] != '\0')
		*end = *end + 1;
}

static size_t	ft_count(char const *str, char c)
{
	size_t	count;
	size_t	start;
	size_t	end;

	count = 0;
	start = 0;
	end = 0;
	while (str[end] != '\0')
	{
		ft_word(str, &start, &end, c);
		if (end == start)
			break ;
		else
			count++;
	}
	return (count);
}

static char	*ft_assign(char const *str, size_t start, size_t end)
{
	char	*word;
	size_t	i;

	i = 0;
	word = malloc(sizeof(char) * (end - start) + 1);
	if (!word)
		return (NULL);
	word[end - start] = 0;
	while (start < end)
	{
		word[i] = str[start];
		i++;
		start++;
	}
	return (word);
}

char	**ft_split(char const *str, char c)
{
	char	**res;
	size_t	start;
	size_t	end;
	size_t	i;

	res = (char **)malloc(sizeof(char *) * (ft_count(str, c) + 1));
	if (!res)
		return (NULL);
	res[ft_count(str, c)] = 0;
	end = 0;
	start = 0;
	i = 0;
	while (i < ft_count(str, c))
	{
		ft_word(str, &start, &end, c);
		if (end == start)
			break ;
		res[i] = ft_assign(str, start, end);
		if (!res[i])
			return (ft_free(res, i));
		i++;
	}
	return (res);
}
