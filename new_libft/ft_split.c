/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemarian <lemarian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 12:03:57 by lemarian          #+#    #+#             */
/*   Updated: 2024/10/21 14:12:46 by lemarian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	count_words(char const *s, char c)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c && (i == 0 || s[i - 1] == c))
			count++;
		i++;
	}
	return (count);
}

int	word_len(const char *s, char c)
{
	int	len;

	len = 0;
	while (*s != c && *s)
	{
		len++;
		s++;
	}
	return (len);
}

char	**fill_array(char **array, char const *s, char c)
{
	int	i;
	int	letter;
	int	word;

	i = 0;
	word = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			letter = 0;
			while (s[i] != c && s[i])
			{
				array[word][letter] = s[i];
				letter++;
				i++;
			}
			array[word][letter] = '\0';
			word++;
		}
		else
			i++;
	}
	return (array);
}

char	**malloc_array(char **array, char const *s, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			array[j] = malloc(sizeof(char) * (word_len(&s[i], c) + 1));
			if (!array[j])
			{
				while (j > 0)
					free(array[--j]);
				free(array);
				return (NULL);
			}
			i = i + word_len(&s[i], c);
			j++;
		}
		else
			i++;
	}
	return (array);
}

char	**ft_split(char const *s, char c)
{
	char	**array;
	int		words;

	if (!s)
		return (NULL);
	words = count_words(s, c);
	array = malloc(sizeof(char *) * (words + 1));
	if (!array)
		return (NULL);
	array[words] = 0;
	array = malloc_array(array, s, c);
	if (array == NULL)
		return (array);
	fill_array(array, s, c);
	return (array);
}

/*int   main(void)
{
        char    *str = "Hello,World,test,again";
        char    **array;
        array = ft_split(str, ',');
        int     i = 0;
        while (array[i])
        {
                printf("%s\n",  array[i]);
                i++;
        }
        while (i > 0)
        {
                free(array[i]);
                i--;
        }
        free(array);
        return (0);
}*/
