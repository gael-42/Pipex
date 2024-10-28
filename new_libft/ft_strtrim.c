/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemarian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 14:41:58 by lemarian          #+#    #+#             */
/*   Updated: 2024/06/04 14:41:23 by lemarian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	set_check(char c, const char *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	int		start;
	int		end;
	int		i;

	i = 0;
	while (s1[i] && set_check(s1[i], set))
		i++;
	start = i;
	i = ft_strlen(s1) - 1;
	while (i > 0 && set_check(s1[i], set))
		i--;
	end = i;
	if (start > end)
	{
		str = malloc(sizeof(char) * 1);
		if (!str)
			return (NULL);
		return (ft_bzero(str, 1));
	}
	str = malloc(sizeof(char) * (end - start + 2));
	if (!str)
		return (NULL);
	ft_strlcpy(str, &s1[start], (end - start + 2));
	return (str);
}
/*int	main(void)
{
	char	*str = ft_strtrim("Hello WorldH", "H");
	printf("%s\n", str);
	free(str);
	return (0);
}*/
