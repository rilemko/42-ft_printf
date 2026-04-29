/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 13:06:49 by mconreau          #+#    #+#             */
/*   Updated: 2022/04/19 17:48:16 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_convert_addr(unsigned long long nbr, char *base, size_t precision)
{
	char	buffer[1024];
	char	*hexa;

	ft_bzero(buffer, 1024);
	hexa = ft_convert_base(nbr, base, precision);
	if (!hexa)
		return (NULL);
	ft_strlcpy(buffer, "0x", 1024);
	ft_strlcat(buffer, hexa, 1024);
	free(hexa);
	return (ft_strdup(buffer));
}

char	*ft_convert_base(unsigned long long nbr, char *base, size_t precision)
{
	char	buffer[1024];
	size_t	baselen;

	ft_bzero(buffer, 1024);
	baselen = ft_strlen(base);
	while (nbr > (baselen - 1))
	{
		ft_chrcat(buffer, base[nbr % baselen], 1024);
		nbr /= baselen;
	}
	ft_chrcat(buffer, base[nbr], 1024);
	while (ft_strlen(buffer) < precision)
		ft_chrcat(buffer, '0', 1024);
	return (ft_strdup(ft_strrev(buffer)));
}
