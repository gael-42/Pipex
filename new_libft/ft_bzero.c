/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemarian <lemarian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 15:35:26 by lemarian          #+#    #+#             */
/*   Updated: 2024/09/12 15:01:54 by lemarian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_bzero(void *str, size_t n)
{
	char	*ptr;

	ptr = (char *)str;
	while (n > 0)
	{
		*ptr = '\0';
		ptr++;
		n--;
	}
	return (str);
}
/*int     main(void)
{
        char *str = (char *)malloc(100);
        printf("%s\n", (char *)ft_bzero(str, 15));
        printf("%s\n", (char *)ft_bzero(str, 5));
        free(str);
        return (0);
}*/
