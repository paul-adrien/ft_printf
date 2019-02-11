/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eviana <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/09 18:08:15 by eviana            #+#    #+#             */
/*   Updated: 2019/02/11 14:43:38 by eviana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

typedef struct	s_asset
{
	int		complexity;
	char	*flags;
	int		width;
	int		precision;
	int		length;
	int		type;
}				t_asset;

#endif
