/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemarian <lemarian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 16:27:07 by lemarian          #+#    #+#             */
/*   Updated: 2024/09/13 15:27:19 by lemarian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;

	str = (unsigned char *)s;
	while (n--)
	{
		if (*str == (unsigned char)c)
			return (str);
		str++;
	}
	return (0);
}
/*int main(void)
{
	char	s[] = {0, 1, 2, 3, 4};
	printf("%s\n", (char *)ft_memchr(s, 0, 1));
	//printf("%s\n", (char *)memchr("Hello World", 111, 11));
	return (0);
}*/
