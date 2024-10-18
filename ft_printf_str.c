/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mratke <mratke@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 15:55:18 by mratke            #+#    #+#             */
/*   Updated: 2024/10/17 16:06:09 by mratke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_str(char *s)
{
	int	s_len;

	if (s != NULL)
	{
		s_len = ft_strlen(s);
		write(1, s, s_len);
		return (s_len);
	}
	return (-1);
}
