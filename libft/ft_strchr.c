/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscheini <sscheini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 20:21:20 by sscheini          #+#    #+#             */
/*   Updated: 2024/10/17 17:17:54 by sscheini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Ft_strchr returns a CHAR * to the first ocurrance of 'c' inside 's'.	*/
/* - Return NULL in case no ocurrance is found.							*/
char	*ft_strchr(const char *s, int c)
{
	size_t	i;
	char	c_c;

	i = 0;
	c_c = (char) c;
	while (s[i])
	{
		if (s[i] == c_c)
			return ((char *) &s[i]);
		i++;
	}
	if (s[i] == c_c)
		return ((char *) &s[i]);
	return (NULL);
}
