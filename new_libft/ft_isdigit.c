/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemarian <lemarian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 10:42:53 by lemarian          #+#    #+#             */
/*   Updated: 2024/09/13 15:27:39 by lemarian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	else
		return (0);
}
/*#include <stdio.h>
int	main(void)
{
	printf("%d\n", ft_isdigit('9'));
	printf("%d\n", ft_isdigit('0'));
	printf("%d\n", ft_isdigit('a'));
	return (0);
}*/
