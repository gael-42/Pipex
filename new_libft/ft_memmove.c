/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemarian <lemarian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 12:18:08 by lemarian          #+#    #+#             */
/*   Updated: 2024/09/13 15:27:59 by lemarian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	char	*c_src;
	char	*c_dst;

	c_src = (char *)src;
	c_dst = (char *)dst;
	if (c_src < c_dst)
	{
		while (n-- > 0)
		{
			c_dst[n] = c_src[n];
		}
	}
	else
	{
		ft_memcpy(dst, src, n);
	}
	return (dst);
}
/*int	main(void)
{
	char *src = "rem ipssum dolor sit a";
	char *dest = (char *)malloc(100);

	printf("%s\n", (char *)ft_memmove(dest, src, 8));
	free(dest);
	return (0);
}*/
