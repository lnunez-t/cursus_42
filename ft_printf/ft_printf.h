/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnunez-t <lnunez-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 13:26:48 by lnunez-t          #+#    #+#             */
/*   Updated: 2023/11/14 17:30:38 by lnunez-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>

# define HEX_LOW_FMT "0123456789abcdef"
# define HEX_UP_FMT "0123456789ABCDEF"

int		ft_printf(const char *fmt, ...);
void	ft_putchar(char c, int *len);
void	ft_putnbr_base(unsigned long nbr, char *base, int *len);
void	ft_putnbr_dec(int nbr, int *len);
void	ft_putstr(char *s, int *len);
void	ft_putptr(void *p, int *len);
void	ft_putnbr_un(unsigned long nbr, int *len);

#endif
