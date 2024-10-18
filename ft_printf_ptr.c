/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_ptr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mratke <mratke@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 16:06:56 by mratke            #+#    #+#             */
/*   Updated: 2024/10/18 17:56:25 by mratke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_pointer(unsigned long int n)
{
	char	convert;
	int		n_len;

	n_len = 0;
	if (n >= 16)
		n_len += print_pointer(n / 16);
	if ((n % 16) < 10)
	{
		convert = (n % 16) + '0';
	}
	else
	{
		convert = ((n % 16) - 10) + 'a';
	}
	write(1, &convert, 1);
	return (n_len + 1);
}

int	ft_printf_ptr(void *ptr)
{
	int	printed_len;

	printed_len = 0;
	printed_len += ft_printf_str("0x");
	printed_len += print_pointer((unsigned long int)ptr);
	return (printed_len);
}
