/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ischeini <ischeini@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 16:44:05 by sscheini          #+#    #+#             */
/*   Updated: 2024/12/04 16:49:35 by ischeini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "libft.h"
# include <stdarg.h>

/* Creates and returns a CONST CHAR * that includes an hexadecimal base		*/
/* wich variates on dependence to the specifier send as an argument.		*/
const char	*ft_sethexa(int specifier);

/* Performs the same way as ft_strdup, but for a single CHAR argument.		*/
char		*ft_chrdup(char c);

/* Allocates a new CHAR * adding "0x" to the ptr send as argument.			*/
/* - Notice that it frees the previous ptr before returning the new one.	*/
char		*ft_ptrdup(void *ptr, int spf);

/* Writes the formatted output to stdout.									*/
int			ft_printf(char const *txt, ...);

#endif