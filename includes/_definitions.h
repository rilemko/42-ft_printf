/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _definitions.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 16:04:01 by mconreau          #+#    #+#             */
/*   Updated: 2024/03/24 12:20:13 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "_constants.h"

typedef int			t_fd;
typedef int			t_pid;
typedef int			t_rt;

typedef struct s_flg {
	size_t	minus;
	size_t	zero;
	size_t	plus;
	size_t	blank;
	size_t	alt;
}	t_flg;

typedef struct s_tkn {
	t_flg	flags;
	size_t	minwidth;
	int		precision;
	char	*type;
	size_t	offset;
}	t_tkn;
