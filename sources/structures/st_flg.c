/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 13:56:16 by mconreau          #+#    #+#             */
/*   Updated: 2022/04/09 13:56:18 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void		ft_flg_ini(t_flg *flags);
static size_t	ft_flg_set(const char *input, t_flg *flags);

t_flg	ft_flg_new(const char *input, size_t *offset)
{
	t_flg		flags;

	ft_flg_ini(&flags);
	(*offset) += ft_flg_set(input, &flags);
	return (flags);
}

static void	ft_flg_ini(t_flg *flags)
{
	flags->minus = 0;
	flags->zero = 0;
	flags->plus = 0;
	flags->blank = 0;
	flags->alt = 0;
}

static size_t	ft_flg_set(const char *input, t_flg *flags)
{
	size_t	index;

	index = 0;
	while (input[index] && ft_strchr("-0+ #", input[index]))
	{
		if (!ft_strncmp(&input[index], "-", 1))
			flags->minus = 1;
		if (!ft_strncmp(&input[index], "0", 1))
			flags->zero = 1;
		if (!ft_strncmp(&input[index], "+", 1))
			flags->plus = 1;
		if (!ft_strncmp(&input[index], " ", 1))
			flags->blank = 1;
		if (!ft_strncmp(&input[index], "#", 1))
			flags->alt = 1;
		index++;
	}
	return (index);
}
