/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemarian <lemarian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 15:36:44 by lemarian          #+#    #+#             */
/*   Updated: 2024/09/13 15:26:47 by lemarian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	call_prints(char c, va_list args)
{
	int	len;

	len = 0;
	if (c == 'c')
		len = print_char(va_arg(args, int));
	if (c == 's')
		len = print_str(va_arg(args, char *));
	if (c == 'd' || c == 'i')
		len = print_int(va_arg(args, int));
	if (c == 'u')
		len = print_unsigned(va_arg(args, unsigned int));
	if (c == 'x')
		len = convert_hexa(va_arg(args, unsigned int), -1);
	if (c == 'X')
		len = convert_hexa(va_arg(args, unsigned int), 1);
	if (c == 'p')
		len = print_address(va_arg(args, void *));
	if (c == '%')
	{
		print_char('%');
		len++;
	}
	va_end(args);
	return (len);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		printed;

	va_start(args, str);
	i = 0;
	printed = 0;
	if (!str)
		return (-1);
	while (str[i])
	{
		if (str[i] != '%')
		{
			print_char(str[i]);
			printed++;
		}
		else
		{
			printed = printed + call_prints(str[i + 1], args);
			i++;
		}
		i++;
	}
	va_end(args);
	return (printed);
}
