/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leobarbo <leobarbo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 09:41:00 by leobarbo          #+#    #+#             */
/*   Updated: 2023/12/01 15:56:45 by leobarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_printf_arg(const char *format, int idx, va_list ap)
{
	if (format[idx + 1] == '%')
		return (ft_putchar(format[idx + 1]));
	else if (format[idx + 1] == 'c')
		return (ft_putchar(va_arg(ap, int)));
	else if (format[idx + 1] == 's')
		return (ft_putstr(va_arg(ap, char *)));
	else if (format[idx + 1] == 'd')
		return (ft_putnbr(va_arg(ap, int)));
	else if (format[idx + 1] == 'i')
		return (ft_putnbr(va_arg(ap, int)));
	else if (format[idx + 1] == 'u')
		return (ft_putnbr_unsg(va_arg(ap, unsigned int)));
	else if (format[idx + 1] == 'x')
		return (ft_puthex(va_arg(ap, unsigned int), "0123456789abcdef"));
	else if (format[idx + 1] == 'X')
		return (ft_puthex(va_arg(ap, unsigned int), "0123456789ABCDEF"));
	else if (format[idx + 1] == 'p')
		return (ft_putstr("0x") + ft_putpointer(va_arg
				(ap, void *), "0123456789abcdef"));
	else
		return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		ret;
	int		idx;

	ret = 0;
	idx = 0;
	if (!format)
		return (-1);
	va_start(ap, format);
	while (format[idx])
	{
		if (format[idx] == '%' && ft_strrchr("scpdiuxX%", format[idx + 1]))
		{
		ret += ft_printf_arg(format, idx, ap);
		idx++;
		}
		else
			ret += ft_putchar(format[idx]);
		idx++;
	}
	va_end(ap);
	return (ret);
}
