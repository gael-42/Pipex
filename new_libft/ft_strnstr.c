/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemarian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 16:04:56 by lemarian          #+#    #+#             */
/*   Updated: 2024/06/04 11:35:14 by lemarian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	int	i;
	int	j;

	i = 0;
	if (little[0] == '\0')
		return ((char *)big);
	while (big[i] && len - i > 0)
	{
		j = 0;
		while (big[i + j] == little[j] && 0 < len - i - j)
		{
			if (little[j + 1] == '\0')
				return ((char *)big + i);
			j++;
		}
		i++;
	}
	return (NULL);
}
/*int	main(void)
{
	char *str = "aaabcabcd";
	char *find = "abcd";
	printf("%s\n", ft_strnstr(str, find, 9));
	return (0);
}*/
