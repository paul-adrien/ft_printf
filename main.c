/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eviana <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 13:39:38 by eviana            #+#    #+#             */
/*   Updated: 2019/03/10 15:22:26 by plaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <string.h>
#include <time.h>
#include <limits.h>


int             main()
{
	int		ans;
	int		cor;

	ans = ft_printf("Okalmos : %c %f %d %x", 'A', 1235.123, 0, 56985);
	ft_putchar('\n');
	cor = printf("Okalmos : %c %f %d %x", 'A', 1235.123, 0, 56985);
		ft_putchar('\n');

	ft_putnbr(ans);
	ft_putnbr(cor);
	ft_putchar('\n');

	ans = ft_printf("Okalmos : %12c %-5f %020d %#x", 'A', 1235.123, 0, 56985);
		ft_putchar('\n');
cor = printf("Okalmos : %12c %-5f %020d %#x", 'A', 1235.123, 0, 56985);
		ft_putchar('\n');
ft_putnbr(ans);
	ft_putnbr(cor);


	return (0);
}
