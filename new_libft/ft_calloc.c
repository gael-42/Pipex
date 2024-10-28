/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemarian <lemarian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 17:12:52 by lemarian          #+#    #+#             */
/*   Updated: 2024/09/12 15:01:58 by lemarian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*array;
	int		i;
	int		total_size;

	total_size = nmemb * size;
	array = malloc(total_size);
	if (!array)
		return (NULL);
	i = 0;
	while (total_size--)
	{
		array[i] = 0;
		i++;
	}
	return ((void *)array);
}
/*int main(void)
{
	int size = 8539;

 	void * d1 = ft_calloc(size, sizeof(int));
 	void * d2 = calloc(size, sizeof(int));
 	if (ft_memcmp(d1, d2, size * sizeof(int)))
	{
		printf("fail\n");
		free(d1);
		free(d2);
		return (0);
	}
	else
	{
		printf("success\n");
		free(d1);
		free(d2);
		return (1);
	}

}*/
