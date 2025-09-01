/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_x.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 15:29:18 by mconreau          #+#    #+#             */
/*   Updated: 2024/03/21 17:47:09 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static size_t	ft_offset(t_tkn *token);
static void		ft_uppercase(char *str);

void	ft_process_x(t_tkn *token, int arg, size_t *count, size_t uppercase)
{
	size_t	offset;
	char	*hexa;

	if (token->precision == 0 && arg == 0)
		return (ft_output_pad(' ', token->minwidth, count));
	offset = ft_offset(token);
	if (token->flags.alt && arg != 0)
		hexa = ft_convert_addr((unsigned int) arg, "0123456789abcdef", offset);
	else
		hexa = ft_convert_base((unsigned int) arg, "0123456789abcdef", offset);
	if (!hexa)
		return ;
	if (uppercase)
		ft_uppercase(hexa);
	token->precision = -1;
	ft_process_s(token, hexa, count);
	free(hexa);
}

static size_t	ft_offset(t_tkn *token)
{
	size_t	offset;

	offset = 0;
	if (token->precision >= 0)
	{
		token->flags.zero = 0;
		offset = token->precision;
	}
	else if (token->minwidth > 0 && !token->flags.minus && token->flags.zero)
		offset = token->minwidth;
	return (offset);
}

static void	ft_uppercase(char *str)
{
	while (*str)
		if (ft_islower(*str++))
			*(str - 1) = (char) ft_toupper(*(str - 1));
}
