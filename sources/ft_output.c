/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_output.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 13:01:33 by mconreau          #+#    #+#             */
/*   Updated: 2022/04/09 13:01:35 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_output_chr(char chr, size_t *count)
{
	(*count)++;
	write(1, &chr, 1);
}

void	ft_output_nbr(long long nbr, size_t *count)
{
	if (nbr < 0)
	{
		ft_output_chr('-', count);
		nbr = -nbr;
	}
	if (nbr > 9)
		ft_output_nbr(nbr / 10, count);
	ft_output_chr((nbr % 10) + '0', count);
}

void	ft_output_pad(char chr, size_t repeat, size_t *count)
{
	while (repeat--)
		ft_output_chr(chr, count);
}	

void	ft_output_str(char *str, size_t limit, size_t *count)
{
	while (*str && limit--)
		ft_output_chr(*str++, count);
}
