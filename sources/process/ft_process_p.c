/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_p.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 16:15:11 by mconreau          #+#    #+#             */
/*   Updated: 2024/03/21 17:47:09 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_process_p(t_tkn *token, unsigned long long arg, size_t *count)
{
	size_t	offset;
	char	*addr;

	offset = 0;
	if (token->precision > 0)
		offset = token->precision;
	addr = ft_convert_addr(arg, "0123456789abcdef", offset);
	if (!addr)
		return ;
	token->precision = -1;
	token->flags.zero = 0;
	ft_process_s(token, addr, count);
	free(addr);
}
