/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tkn.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 13:23:57 by mconreau          #+#    #+#             */
/*   Updated: 2022/04/09 13:23:59 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void	ft_tkn_ini(t_tkn *token);
static void	ft_tkn_minwidth(t_tkn *token, const char *input);
static void	ft_tkn_precision(t_tkn *token, const char *input);
static void	ft_tkn_type(t_tkn *token, const char *input);

t_tkn	ft_tkn_new(const char *input)
{
	t_tkn		token;

	ft_tkn_ini(&token);
	token.flags = ft_flg_new(&input[token.offset], &token.offset);
	ft_tkn_minwidth(&token, &input[token.offset]);
	ft_tkn_precision(&token, &input[token.offset]);
	ft_tkn_type(&token, &input[token.offset]);
	return (token);
}

static void	ft_tkn_ini(t_tkn *token)
{
	token->minwidth = 0;
	token->precision = -1;
	token->type = 0;
	token->offset = 1;
}

static void	ft_tkn_minwidth(t_tkn *token, const char *input)
{
	if (ft_isdigit(*input))
	{
		token->minwidth = ft_atoi(input);
		token->offset += ft_nbrlen(token->minwidth);
	}
}

static void	ft_tkn_precision(t_tkn *token, const char *input)
{
	if (ft_strncmp(input, ".", 1) == 0 && ft_isdigit(*(input + 1)))
	{
		token->precision = ft_atoi(input + 1);
		token->offset += ft_nbrlen(token->precision) + 1;
	}
	else if (ft_strncmp(input, ".", 1) == 0 && !ft_isdigit(*(input + 1)))
	{
		token->precision = 0;
		token->offset++;
	}
}

static void	ft_tkn_type(t_tkn *token, const char *input)
{
	if (ft_strncmp(input, "c", 1) == 0)
		token->type = "c";
	if (ft_strncmp(input, "s", 1) == 0)
		token->type = "s";
	if (ft_strncmp(input, "p", 1) == 0)
		token->type = "p";
	if (ft_strncmp(input, "d", 1) == 0)
		token->type = "d";
	if (ft_strncmp(input, "i", 1) == 0)
		token->type = "i";
	if (ft_strncmp(input, "u", 1) == 0)
		token->type = "u";
	if (ft_strncmp(input, "x", 1) == 0)
		token->type = "x";
	if (ft_strncmp(input, "X", 1) == 0)
		token->type = "X";
	if (ft_strncmp(input, "%", 1) == 0)
		token->type = "%";
	token->offset += ft_strlen(token->type);
}
