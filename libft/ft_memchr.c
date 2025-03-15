/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscheini <sscheini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 12:55:26 by sscheini          #+#    #+#             */
/*   Updated: 2024/10/17 17:17:22 by sscheini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Ft_memchr searches for 'c' inside 's' for 'n' bytes.						*/
/* - Returns a VOID * to the first match or NULL, in case there's no match.	*/
void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*s_c;
	unsigned char	c_c;
	size_t			i;

	i = 0;
	s_c = (unsigned char *) s;
	c_c = (unsigned char) c;
	while (i < n)
	{
		if (s_c[i] == c_c)
			return ((void *) &s_c[i]);
		i++;
	}
	return (NULL);
}
