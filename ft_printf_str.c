/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mratke <mratke@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 15:55:18 by mratke            #+#    #+#             */
/*   Updated: 2024/10/18 15:02:25 by mratke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

int	ft_printf_str(char *s)
{
	int	s_len;

	if (s != NULL)
	{
		s_len = ft_strlen(s);
		write(1, s, s_len);
		return (s_len);
	}
	write(1, "(null)", 6);
	return (6);
}
