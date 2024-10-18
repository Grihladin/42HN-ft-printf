/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mratke <mratke@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 12:14:19 by mratke            #+#    #+#             */
/*   Updated: 2024/10/18 12:20:06 by mratke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

// includes
# include <stdarg.h> // va_list
# include <stdio.h>  //printf
# include <stdlib.h> //malloc
# include <unistd.h> //write

// From libft
int	ft_strlen(const char *str);

// Mandatory part
int	ft_printf(const char *format, ...);
int	ft_printf_char(int c);
int	ft_printf_str(char *s);
#endif
