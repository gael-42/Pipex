/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemarian <lemarian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 16:59:53 by lemarian          #+#    #+#             */
/*   Updated: 2024/09/12 15:02:42 by lemarian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	check_size(int n)
{
	int	size;

	size = 1;
	if (n < 0)
		size++;
	while (n / 10 != 0)
	{
		n = n / 10;
		size++;
	}
	return (size);
}

char	*ft_itoa(int n)
{
	char		*str;
	int			size;
	long int	nb;

	size = check_size(n);
	nb = (long int)n;
	str = malloc(sizeof(char) * (size + 1));
	if (!str)
		return (NULL);
	str[size--] = '\0';
	if (n == 0)
		str[0] = '0';
	if (n < 0)
	{
		str[0] = '-';
		nb = nb * -1;
	}
	while (nb != 0)
	{
		str[size--] = (nb % 10) + 48;
		nb = nb / 10;
	}
	return (str);
}
/*int	main(void)
{
	char	*str = ft_itoa(-2147483648);
	printf("%s\n", str);
	free(str);
	return (0);
}*/
