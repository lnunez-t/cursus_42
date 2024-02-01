/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnunez-t <lnunez-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 12:27:36 by lnunez-t          #+#    #+#             */
/*   Updated: 2023/11/14 18:17:15 by lnunez-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	check_fmt(const char *fmt, va_list args, int *len)
{
	if (*fmt == 's')
		ft_putstr(va_arg(args, char *), len);
	else if (*fmt == 'c')
		ft_putchar((char) va_arg(args, int), len);
	else if (*fmt == 'p')
		ft_putptr(va_arg(args, void *), len);
	else if (*fmt == 'd' || *fmt == 'i')
		ft_putnbr_dec(va_arg(args, int), len);
	else if (*fmt == 'u')
		ft_putnbr_un(va_arg(args, unsigned int), len);
	else if (*fmt == 'x')
		ft_putnbr_base(va_arg(args, unsigned int),
			HEX_LOW_FMT, len);
	else if (*fmt == 'X')
		ft_putnbr_base(va_arg(args, unsigned int),
			HEX_UP_FMT, len);
	else
		ft_putchar(*fmt, len);
}

int	ft_printf(const char *fmt, ...)
{
	int		len;
	va_list	args;

	len = 0;
	va_start(args, fmt);
	while (*fmt)
	{
		if (*fmt == '%')
		{
			fmt++;
			check_fmt(fmt, args, &len);
		}
		else
			ft_putchar(*fmt, &len);
		fmt++;
	}
	va_end(args);
	return (len);
}
