/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemarian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 13:38:06 by lemarian          #+#    #+#             */
/*   Updated: 2024/06/04 10:47:44 by lemarian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t siz)
{
	char	*og;
	size_t	i;
	size_t	j;
	size_t	result;

	og = (char *)src;
	i = ft_strlen(dest);
	j = 0;
	if (siz > ft_strlen(dest))
		result = ft_strlen(og) + ft_strlen(dest);
	else
		result = ft_strlen(og) + siz;
	if (siz > 0)
	{
		while (src[j] && i < (siz - 1))
		{
			dest[i] = src[j];
			i++;
			j++;
		}
	}
	dest[i] = '\0';
	return (result);
}
/*int     main(void)
{
        char dest[11] = "Hello";
        printf("%lu\n", ft_strlcat(dest, "lorem ipsum dolor sit amet", 0));
        printf("%s\n", dest);
        return (0);
}*/
