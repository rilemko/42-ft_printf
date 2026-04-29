/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_padding.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 15:07:52 by mconreau          #+#    #+#             */
/*   Updated: 2024/03/21 17:47:09 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_padding(t_tkn *token, size_t offset, size_t *count)
{
	char	chr;

	chr = ' ';
	if ((token->flags.zero && !token->flags.minus))
		chr = '0';
	if (token->minwidth > offset)
		ft_output_pad(chr, token->minwidth - offset, count);
}
