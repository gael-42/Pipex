/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_address.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemarian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 17:43:49 by lemarian          #+#    #+#             */
/*   Updated: 2024/06/11 13:30:34 by lemarian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"
#include <stdint.h>

int	print_address(void *ptr)
{
	uintptr_t	address;

	if (ptr == 0)
	{
		print_str("(nil)");
		return (5);
	}
	address = (uintptr_t)ptr;
	write(1, "0x", 2);
	return (convert_hexa(address, -1) + 2);
}
/*int main(void)
{
	int	nb = 5;
	int	*ptr;
	ptr = &nb;
	print_address(ptr);
	printf("compare %p\n", ptr);
	return (0);
}*/
