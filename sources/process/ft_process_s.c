/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_s.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 15:43:34 by mconreau          #+#    #+#             */
/*   Updated: 2024/03/21 17:47:09 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_process_s(t_tkn *token, char *arg, size_t *count)
{
	char	buffer[200000];
	size_t	strlen;

	if (arg == NULL)
		ft_strlcpy(buffer, "(null)", 200000);
	else
		ft_strlcpy(buffer, arg, 200000);
	if (token->precision == 0)
		ft_bzero(buffer, 200000);
	strlen = ft_strlen(buffer);
	if (token->precision > 0 && token->precision < (int) strlen)
		strlen = token->precision;
	if (!token->flags.minus)
		ft_padding(token, strlen, count);
	ft_output_str(buffer, strlen, count);
	if (token->flags.minus)
		ft_padding(token, strlen, count);
}
