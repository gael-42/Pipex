/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemarian <lemarian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 16:15:14 by lemarian          #+#    #+#             */
/*   Updated: 2024/09/13 15:27:55 by lemarian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char	*s1;

	if (dest == NULL && src == NULL)
		return (dest);
	s1 = (char *)dest;
	while (n > 0)
	{
		*(char *)s1 = *(char *)src;
		s1++;
		src++;
		n--;
	}
	return (dest);
}
/*int	main(void)
{
	char *src = "Hello World";
	char *dest = (char *)malloc(100);
	printf("%s\n", (char *)ft_memcpy(dest, src, 11));
	free(dest);
	return (0);
}*/
