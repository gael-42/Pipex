/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemarian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 11:48:00 by lemarian          #+#    #+#             */
/*   Updated: 2024/05/24 15:22:06 by lemarian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memset(void *str, int c, size_t n)
{
	char	*ptr;

	ptr = (char *)str;
	while (n > 0)
	{
		*ptr = (char)c;
		ptr++;
		n--;
	}
	return (str);
}
/*int	main(void)
{
	char *str = (char *)malloc(100);
	printf("%s\n", (char *)ft_memset(str, 65, 15));
	printf("%s\n", (char *)ft_memset(str, 75, 5));
	free(str);
	return (0);
}*/
