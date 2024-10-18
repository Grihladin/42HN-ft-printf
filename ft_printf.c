/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mratke <mratke@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 15:54:32 by mratke            #+#    #+#             */
/*   Updated: 2024/10/18 15:04:21 by mratke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		printed_len;
	char	c;
	char	*str;
	int		integer;

	i = 0;
	printed_len = 0;
	va_start(args, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%' && format[i + 1] != '\0')
		{
			i++;
			if (format[i] == 'c')
			{
				c = (char)va_arg(args, int);
				printed_len += ft_printf_char(c);
			}
			else if (format[i] == 's')
			{
				str = va_arg(args, char *);
				printed_len += ft_printf_str(str);
			}
			else if (format[i] == 'i' || format[i] == 'd')
			{
				integer = va_arg(args, int);
				printed_len += ft_printf_int(integer);
			}
		}
		else
			printed_len += ft_printf_char(format[i]);
		i++;
	}
	va_end(args);
	return (printed_len);
}

// int	main(void)
// {
// 	int	i;

// 	i = 21324354;
// 	ft_printf("%i", i);
// }
