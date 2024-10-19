/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mratke <mratke@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 12:37:50 by mratke            #+#    #+#             */
/*   Updated: 2024/10/19 19:35:22 by mratke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_int(int n)
{
	char	convert;
	int		n_len;

	n_len = 0;
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	if (n == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	if (n < 0)
	{
		n = -n;
		write(1, "-", 1);
		n_len = 1;
	}
	if (n >= 10)
		n_len += ft_printf_int(n / 10);
	convert = (n % 10) + '0';
	write(1, &convert, 1);
	return (n_len + 1);
}
