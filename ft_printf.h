/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eviana <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/09 18:08:15 by eviana            #+#    #+#             */
/*   Updated: 2019/02/13 18:37:27 by eviana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <unistd.h>

typedef struct	s_asset
{
	char	*flags;
	size_t	width;
	int		precision;
	int		length;
	int		type;
}				t_asset;

#endif
