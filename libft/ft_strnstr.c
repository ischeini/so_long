/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscheini <sscheini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 13:48:27 by sscheini          #+#    #+#             */
/*   Updated: 2024/10/17 17:18:18 by sscheini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Ft_strnstr returns a CHAR * to the first match of all 'little' in 'big'.	*/
/* - The match must exist in 'len' bytes of 'big'.							*/
/* - Returns 'big' if 'little' is empty.									*/
/* - Returns NULL if no match is found.										*/
char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	int		little_len;

	little_len = ft_strlen(little);
	if (!little_len)
		return ((char *) big);
	i = 0;
	while (i < len)
	{
		if (!big[i])
			return (NULL);
		if (big[i] == little[0] && len >= little_len + i)
		{
			if (ft_strncmp(&big[i], &little[0], little_len) == 0)
				return ((char *) &big[i]);
		}
		i++;
	}
	return (NULL);
}
