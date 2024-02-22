/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboujrar <cboujrar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 17:36:23 by cboujrar          #+#    #+#             */
/*   Updated: 2024/02/22 19:11:59 by cboujrar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

int	ft_atoi(const char *str)
{
	int	result;
	int	signe;

	result = 0;
	signe = 1;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			signe = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + (*str - '0');
		str++;
	}
	return (result * signe);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	count_words(const char *str)
{
	int	count;
	int	x;

	count = 0;
	x = 0;
	while (*str)
	{
		if (*str != ' ' && x == 0)
		{
			x = 1;
			count++;
		}
		else if (*str == ' ')
			x = 0;
		str++;
	}
	return (count);
}

char	*put_word(const char *str, int start, int end)
{
	char	*word;
	int		i;

	i = 0;
	word = malloc((end - start + 1) * sizeof(char));
	if (!word)
		return (NULL);
	while (start < end)
	{
		word[i] = str[start];
		i++;
		start++;
	}
	word[i] = '\0';
	return (word);
}

 void	*free_array(char **str, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		free(str[i]);
		i++;
	}
	free(str);
	return (NULL);
}

 void	ft_initiate_vars(size_t *i, int *j, int *s_word)
{
	*i = 0;
	*j = 0;
	*s_word = -1;
}

char	**ft_split(const char *s)
{
	char	**res;
	size_t	i;
	int		j;
	int		s_word;

	ft_initiate_vars(&i, &j, &s_word);
	res = calloc((count_words(s) + 1), sizeof(char *));
	if (!res)
		return (NULL);
	while (i <= ft_strlen(s))
	{
		if (s[i] != ' ' && s_word < 0)
			s_word = i;
		else if ((s[i] == ' ' || i == ft_strlen(s)) && s_word >= 0)
		{
			res[j] = put_word(s, s_word, i);
			if (!(res[j]))
				return (free_array(res, j));
			s_word = -1;
			j++;
		}
		i++;
	}
	return (res);
}