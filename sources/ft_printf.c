/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 11:41:05 by mconreau          #+#    #+#             */
/*   Updated: 2024/03/21 17:47:09 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static size_t	ft_process(const char *input, va_list arguments, size_t *count);

int	ft_printf(const char *input, ...)
{
	size_t	count;
	va_list	arguments;

	count = 0;
	va_start(arguments, input);
	while (*input)
	{
		if (!ft_strncmp(input, "%", 1))
			input += ft_process(input, arguments, &count);
		else
			ft_output_chr(*input++, &count);
	}
	return (count);
}

static size_t	ft_process(const char *input, va_list arguments, size_t *count)
{
	t_tkn		token;

	token = ft_tkn_new(input);
	if (ft_strncmp(token.type, "c", 1) == 0)
		ft_process_c(&token, va_arg(arguments, int), count);
	if (ft_strncmp(token.type, "s", 1) == 0)
		ft_process_s(&token, va_arg(arguments, char *), count);
	if (ft_strncmp(token.type, "p", 1) == 0)
		ft_process_p(&token, va_arg(arguments, unsigned long long), count);
	if (ft_strncmp(token.type, "d", 1) == 0)
		ft_process_d(&token, va_arg(arguments, int), count);
	if (ft_strncmp(token.type, "i", 1) == 0)
		ft_process_i(&token, va_arg(arguments, int), count);
	if (ft_strncmp(token.type, "u", 1) == 0)
		ft_process_u(&token, va_arg(arguments, int), count);
	if (ft_strncmp(token.type, "x", 1) == 0)
		ft_process_x(&token, va_arg(arguments, unsigned int), count, 0);
	if (ft_strncmp(token.type, "X", 1) == 0)
		ft_process_x(&token, va_arg(arguments, unsigned int), count, 1);
	if (ft_strncmp(token.type, "%", 1) == 0)
		ft_output_chr('%', count);
	va_end(arguments);
	return (token.offset);
}
