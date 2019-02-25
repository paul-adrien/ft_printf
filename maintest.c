/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maintest.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eviana <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 14:37:21 by eviana            #+#    #+#             */
/*   Updated: 2019/02/25 15:04:28 by eviana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		main(int argc, char **argv)
{
	//ft_putstr(ft_convert_base(ft_ulltoa(4294967296), "0123456789", "0123456789abcdef"));
	//long long ll;
	
	//ll = -9223372036854775808;
	//ft_putstr(ft_lltoa(ll));
	if (argc == 4)
		ft_putstr(ft_convert_base(argv[1], argv[2], argv[3]));
	else
		ft_putstr("il faut 3 arguments");
	return (0);
}
