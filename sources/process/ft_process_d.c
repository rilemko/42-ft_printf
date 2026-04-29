/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_d.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 13:56:45 by mconreau          #+#    #+#             */
/*   Updated: 2024/03/21 17:47:09 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void	ft_output_d(t_tkn *token, long long int arg, size_t *count);

void	ft_process_d(t_tkn *token, long long int arg, size_t *count)
{
	size_t	offset;

	if (token->precision == 0 && arg == 0)
		return (ft_output_pad(' ', token->minwidth, count));
	offset = ft_nbrlen(arg);
	if (token->precision > (int) offset)
		offset = token->precision;
	if (arg < 0 || (arg > 0 && (token->flags.plus || token->flags.blank)))
		offset++;
	if (!token->flags.minus)
	{
		if (arg < 0 && token->flags.zero
			&& !((int) token->minwidth > token->precision
				&& token->precision > 0))
			ft_output_chr('-', count);
		if ((int) token->minwidth > token->precision && token->precision > 0)
			token->flags.zero = 0;
		ft_padding(token, offset, count);
	}
	ft_output_d(token, arg, count);
	if (token->flags.minus)
		ft_padding(token, offset, count);
}

static void	ft_output_d(t_tkn *token, long long int arg, size_t *count)
{
	size_t	nbrlen;

	nbrlen = ft_nbrlen(arg);
	if (arg < 0 && !token->flags.zero)
		ft_output_chr('-', count);
	else if (token->flags.plus)
		ft_output_chr('+', count);
	else if (token->flags.blank)
		ft_output_chr(' ', count);
	if (token->precision > (int) nbrlen)
		ft_output_pad('0', token->precision - nbrlen, count);
	if (arg < 0)
		arg = -arg;
	ft_output_nbr(arg, count);
}
