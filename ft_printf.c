/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mratke <mratke@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 15:54:32 by mratke            #+#    #+#             */
/*   Updated: 2024/10/18 15:09:54 by mratke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		printed_len;

	i = 0;
	printed_len = 0;
	va_start(args, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%' && format[i + 1] != '\0')
		{
			i++;
			if (format[i] == 'c')
				printed_len += ft_printf_char((char)va_arg(args, int));
			else if (format[i] == 's')
				printed_len += ft_printf_str(va_arg(args, char *));
			else if (format[i] == 'i' || format[i] == 'd')
				printed_len += ft_printf_int(va_arg(args, int));
		}
		else
			printed_len += ft_printf_char(format[i]);
		i++;
	}
	return (va_end(args), printed_len);
}

// int	main(void)
// {
// 	int	i;

// 	i = 21324354;
// 	ft_printf("%i", i);
// }
