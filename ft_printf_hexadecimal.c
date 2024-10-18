/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hexadecimal.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mratke <mratke@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 17:59:29 by mratke            #+#    #+#             */
/*   Updated: 2024/10/18 18:38:19 by mratke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_printf_hexadecimal_lowercase(long int n)
{
	char	convert;
	int		n_len;

	n_len = 0;
	if (n == 0)
	{
		write(1, "0", 1);
		n_len++;
		return (n_len);
	}
	if (n < 0)
	{
		write(1, "-", 1);
		n_len++;
	}
	if (n >= 16)
		n_len += ft_printf_hexadecimal_lowercase(n / 16);
	if ((n % 16) < 10)
		convert = (n % 16) + '0';
	else
		convert = ((n % 16) - 10) + 'a';
	write(1, &convert, 1);
	return (n_len + 1);
}

static int	ft_printf_hexadecimal_uppercase(long int n)
{
	char	convert;
	int		n_len;

	n_len = 0;
	if (n == 0)
	{
		write(1, "0", 1);
		n_len++;
		return (n_len);
	}
	if (n < 0)
	{
		n = -n;
		write(1, "-", 1);
		n_len++;
	}
	if (n >= 16)
		n_len += ft_printf_hexadecimal_uppercase(n / 16);
	if ((n % 16) < 10)
		convert = (n % 16) + '0';
	else
		convert = ((n % 16) - 10) + 'A';
	write(1, &convert, 1);
	return (n_len + 1);
}

int	ft_printf_hexadecimal(long int n, int type)
{
	int	printed_len;

	printed_len = 0;
	if (type == 'x')
	{
		printed_len += ft_printf_hexadecimal_lowercase(n);
		return (printed_len);
	}
	else
	{
		printed_len += ft_printf_hexadecimal_uppercase(n);
		return (printed_len);
	}
}
