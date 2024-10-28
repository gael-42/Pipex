/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemarian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 16:43:16 by lemarian          #+#    #+#             */
/*   Updated: 2024/06/10 17:10:10 by lemarian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

static int	count_len(size_t nb)
{
	int	len;

	len = 0;
	if (nb == 0)
		return (1);
	while (nb > 0)
	{
		nb = nb / 10;
		len++;
	}
	return (len);
}

int	print_unsigned(unsigned int nb)
{	
	int	len;

	len = count_len(nb);
	if (nb >= 10)
	{
		print_unsigned(nb / 10);
		print_unsigned(nb % 10);
	}
	else
	{
		nb = nb + 48;
		write(1, &nb, 1);
	}
	return (len);
}
/*int	main(void)
{
	printf("%d\n", print_unsigned(0));
	return (0);
}*/
