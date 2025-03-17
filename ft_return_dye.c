/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_return_dye.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ischeini <ischeini@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 18:25:46 by ischeini          #+#    #+#             */
/*   Updated: 2025/03/17 19:17:38 by ischeini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long.h"

int	ft_dye(unsigned char t, unsigned char r, unsigned char g, unsigned char b)
{
	return (*(int *)(unsigned char [4]){b, g, r, t});
}

unsigned char	ft_get_t(int trgb)
{
	return (((unsigned char *)&trgb)[3]);
}

unsigned char	ft_get_r(int trgb)
{
	return (((unsigned char *)&trgb)[2]);
}

unsigned char	ft_get_g(int trgb)
{
	return (((unsigned char *)&trgb)[1]);
}

unsigned char	ft_get_b(int trgb)
{
	return (((unsigned char *)&trgb)[0]);
}
