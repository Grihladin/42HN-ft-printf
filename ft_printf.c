/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mratke <mratke@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 15:54:32 by mratke            #+#    #+#             */
/*   Updated: 2024/10/18 18:20:54 by mratke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_printf_format_definer(const char *format, int i, va_list args)
{
	int	printed_len;

	printed_len = 0;
	if (format[i] == 'c')
		printed_len += ft_printf_char((char)va_arg(args, int));
	else if (format[i] == 's')
		printed_len += ft_printf_str(va_arg(args, char *));
	else if (format[i] == 'i' || format[i] == 'd')
		printed_len += ft_printf_int(va_arg(args, int));
	else if (format[i] == 'u')
		printed_len += ft_printf_uint(va_arg(args, unsigned int));
	else if (format[i] == 'p')
		printed_len += ft_printf_ptr(va_arg(args, void *));
	else if (format[i] == 'x' || format[i] == 'X')
		printed_len += ft_printf_hexadecimal(va_arg(args, long int), format[i]);
	return (printed_len);
}

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
		if (format[i] == '%' && format[i + 1] != '\0' && format[i + 1] != '%')
		{
			i++;
			printed_len += ft_printf_format_definer(format, i, args);
		}
		else if (format[i] == '%' && format[i + 1] == '%')
		{
			printed_len += ft_printf_percent();
			i++;
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
