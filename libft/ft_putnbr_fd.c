/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscheini <sscheini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 16:28:59 by sscheini          #+#    #+#             */
/*   Updated: 2024/10/17 17:17:40 by sscheini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Ft_putnbr_fd writes 'n' as a STRING into the 'fd' passed as an argument. */
int	ft_putnbr_fd(int n, int fd)
{
	int	w_bytes;

	w_bytes = 0;
	if (n == INT_MIN)
	{
		w_bytes += ft_putnbr_fd(INT_MIN / 10, fd);
		n = 8;
	}
	if (n < 0)
	{
		n *= -1;
		w_bytes += ft_putchar_fd('-', fd);
	}
	if (n >= 10)
	{
		w_bytes += ft_putnbr_fd(n / 10, fd);
		n = n % 10;
	}
	w_bytes += ft_putchar_fd(n + 48, fd);
	return (w_bytes);
}
