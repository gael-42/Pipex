/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemarian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 17:04:10 by lemarian          #+#    #+#             */
/*   Updated: 2024/06/11 12:09:10 by lemarian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	print_zero(void)
{
	write(1, "0", 1);
	return (1);
}

int	what_size(int letter_size)
{
	if (letter_size == -1)
		letter_size = 87;
	else
		letter_size = 55;
	return (letter_size);
}

int	convert_hexa(size_t nb, int letter_size)
{
	char	hex[100];
	int		i;
	int		remainder;
	int		len;

	i = 0;
	remainder = 0;
	len = 0;
	letter_size = what_size(letter_size);
	if (nb == 0)
		len = print_zero();
	while (nb > 0)
	{
		remainder = nb % 16;
		if (remainder < 10)
			hex[i++] = remainder + '0';
		else
			hex[i++] = remainder + letter_size;
		nb = nb / 16;
	}
	while (--i >= 0 && len++ >= 0)
		write(1, &hex[i], 1);
	return (len);
}
/*int	main(void)
{
	printf("%d\n", convert_hexa(0, -1));
	return (0);
}*/
