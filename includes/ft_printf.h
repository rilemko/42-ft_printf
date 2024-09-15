/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 11:38:03 by mconreau          #+#    #+#             */
/*   Updated: 2024/03/24 12:20:05 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "_includes.h"
#include "_definitions.h"

int		ft_printf(const char *input, ...);
char	*ft_convert_addr(unsigned long long nbr, char *base, size_t precision);
char	*ft_convert_base(unsigned long long nbr, char *base, size_t precision);
t_flg	ft_flg_new(const char *input, size_t *offset);
void	ft_output_chr(char chr, size_t *count);
void	ft_output_nbr(long long int nbr, size_t *count);
void	ft_output_pad(char chr, size_t repeat, size_t *count);
void	ft_output_str(char *str, size_t limit, size_t *count);
void	ft_padding(t_tkn *token, size_t offset, size_t *count);
void	ft_process_c(t_tkn *token, int arg, size_t *count);
void	ft_process_d(t_tkn *token, long long int arg, size_t *count);
void	ft_process_i(t_tkn *token, int arg, size_t *count);
void	ft_process_p(t_tkn *token, unsigned long long arg, size_t *count);
void	ft_process_s(t_tkn *token, char *arg, size_t *count);
void	ft_process_u(t_tkn *token, unsigned int arg, size_t *count);
void	ft_process_x(t_tkn *token, int arg, size_t *count, size_t uppercase);
t_tkn	ft_tkn_new(const char *input);
